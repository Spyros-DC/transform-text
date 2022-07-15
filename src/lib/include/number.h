#ifndef WORDS_NUMBERS_NUMBER_HPP
#define WORDS_NUMBERS_NUMBER_HPP

#include <vector>
#include "word.h"

namespace words{

    namespace numbers{

        struct number{
            word word_inst;
            std::vector<number> v_numbers;
        };


    } // namespace numbers
} // namespace words

typedef std::vector<words::numbers::number> vec_numbers;
typedef std::vector<std::vector<words::numbers::number> > vec_vec_numbers;

#endif // WORDS_NUMBERS_NUMBER_HPP