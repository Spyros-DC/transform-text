#ifndef WORDS_NUMBERS_FACTORY_HPP
#define WORDS_NUMBERS_FACTORY_HPP

#include "number.hpp"
#include "error.hpp"

namespace words{

    namespace numbers{

        std::pair<error, std::vector<number> > number_factory(word word_inst, 
                                                              const std::vector<number>& v_numbers);


    } // namespace numbers
} // namespace words

#endif // WORDS_NUMBERS_FACTORY_HPP