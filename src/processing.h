#ifndef TRANSFORMTEXT_PROCESSING_H
#define TRANSFORMTEXT_PROCESSING_H

#include <string>
#include <vector>
#include "word.h"

namespace text {

    using namespace words::numbers;

    class processor{

        public:
            processor(const std::string& str);

            std::string run();

            void find_pairs_for_replace();

            std::vector<std::pair<std::string, std::string> > pairs_for_replace();

            std::string find_substr(const std::string pattern);

            std::vector<word> convert_to_words(std::string str);
        private:
            const std::string& str_;
            // vector of pairs of {original sub string, replace sub string}
            std::vector<std::pair<std::string, std::string> > pairs_for_replace_;
    };


}// namespace text

#endif //TRANSFORMTEXT_PROCESSING_H