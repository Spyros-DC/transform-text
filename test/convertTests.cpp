#include <gtest/gtest.h>
#include <iostream>
#include "src/lib/include/convert.h"
#include "src/lib/include/print.h"
#include "src/lib/include/factory.h"
#include "src/lib/include/compose.h"

using namespace words::numbers;


TEST(convertSuite, first) {
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
    ASSERT_EQ(convert_to_num(res[0]), (900*1000*1000+2));
    ASSERT_EQ(convert_to_num(res[1]), (2));
}

TEST(convertSuite, second) {
    std::vector<word> v_words{
            word{order::units, 9},
            word{order::hundreds, 1},
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
    ASSERT_EQ(convert_to_num(res[0]), (902));
}

TEST(convertSuite, third) {
    std::vector<word> v_words{
            word{order::units, 2},
            word{order::hundreds, 1},
            word{order::tens, 2},
            word{order::units, 2},
            word{order::thousands, 1},
            word{order::tens, 3},
            word{order::units, 5}
    };

    vec_numbers v_nums{};

    for(const auto& w: v_words){
        auto loop_res = number_factory(w, v_nums);
        ASSERT_EQ(loop_res.first, error::ok);
        v_nums = loop_res.second;
    }

    vec_vec_numbers res = compose_numbers(v_nums);

    ASSERT_EQ(res.size(), 1);
    ASSERT_EQ(convert_to_num(res[0]), (222035));
}