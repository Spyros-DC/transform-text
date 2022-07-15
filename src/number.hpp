#ifndef WORDS_NUMBERS_NUMBER_HPP
#define WORDS_NUMBERS_NUMBER_HPP

#include <vector>
#include "word.hpp"

namespace words{

    namespace numbers{

        struct number{
            word word_inst;
            std::vector<number> v_numbers;
        };


    } // namespace numbers
} // namespace words

#endif // WORDS_NUMBERS_NUMBER_HPP