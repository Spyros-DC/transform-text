#ifndef TRANSFORMTEXT_CONVERT_H
#define TRANSFORMTEXT_CONVERT_H

#include "number.h"
#include "error.h"

namespace words{

    namespace numbers{

        long long convert_vec_of_nums_to_num(const vec_numbers& v_v_nums);

        std::pair<error, vec_vec_numbers> convert_words_to_nums(const std::vector<word>& v_words);

    } // namespace numbers
} // namespace words

#endif //TRANSFORMTEXT_CONVERT_H
