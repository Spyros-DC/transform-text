#include "compose.hpp"

namespace words{

    namespace numbers{

        number compose_number_with_word(const number num, const word word_inst) {

            number copy{num};
            //copy.v_words.push_back(word_inst);
            return copy;
        }

    } // namespace numbers
} // namespace words