#ifndef TRANSFORMTEXT_CONFIG_H
#define TRANSFORMTEXT_CONFIG_H

#include <map>
#include <set>
#include "word.h"

using namespace words::numbers;

namespace text {

    extern std::map<std::string, word> config_m;

    extern std::set<std::string> set_of_number_words;

}// namespace text

#endif //TRANSFORMTEXT_CONFIG_H
