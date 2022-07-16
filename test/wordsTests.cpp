#include <gtest/gtest.h>
#include "compose.h"
#include "factory.h"

using namespace words::numbers;


TEST(wordsSuite, first) { 

    std::vector<word> v_words{
        word{order::units, 9},
        word{order::hundreds, 1},
        word{order::millions, 1},
        word{order::units, 2}
    };

    vec_numbers v_nums{};

    for(const auto& w: v_words){
        auto loop_res = number_factory(w, v_nums);
        ASSERT_EQ(loop_res.first, error::ok);
        v_nums = loop_res.second;
    }

    vec_vec_numbers res = compose_numbers(v_nums);
    ASSERT_EQ(res.size(), 1);
    ASSERT_EQ(res[0].size(), 2);
    ASSERT_EQ(res[0][0].v_numbers.size(), 1);
}

TEST(wordsSuite, second) { 

    std::vector<word> v_words{
        word{order::units, 9},
        word{order::hundreds, 1},
        word{order::millions, 1},
        word{order::units, 2},
        word{order::units, 2}
    };

    vec_numbers v_nums{};

    for(const auto& w: v_words){
        auto loop_res = number_factory(w, v_nums);
        ASSERT_EQ(loop_res.first, error::ok);
        v_nums = loop_res.second;
    }

    vec_vec_numbers res = compose_numbers(v_nums);
    ASSERT_EQ(res.size(), 2);
    ASSERT_EQ(res[1].size(), 1);
    ASSERT_EQ(res[0][1].word_inst.order_inst, order::units);
}