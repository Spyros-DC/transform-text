#include <gtest/gtest.h>
#include "convert.h"
#include "print.h"
#include "compose.h"
#include "config.h"

TEST(configSuite, first) {

    std::string str_num{"one hundred thirty three"};
    std::vector<word> v_words{};

    std::stringstream stream_inst{str_num};
    std::string loop_str{};
    while(stream_inst >> loop_str){
        v_words.push_back(text::config_m[loop_str]);
    }

    auto conv1 =  convert_words_to_nums(v_words);
    ASSERT_EQ(conv1.first, error::ok);

    for(const auto& elem: conv1.second){
        ASSERT_EQ(convert_vec_of_nums_to_num(elem), 133);
    }
}