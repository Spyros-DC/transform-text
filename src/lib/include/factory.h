#ifndef WORDS_NUMBERS_FACTORY_HPP
#define WORDS_NUMBERS_FACTORY_HPP

#include "number.h"
#include "error.h"

namespace words{

    namespace numbers{

        std::pair<error, vec_numbers > number_factory(word word_inst, 
                                                      const vec_numbers& v_numbers);


    } // namespace numbers
} // namespace words

#endif // WORDS_NUMBERS_FACTORY_HPP