#include <gtest/gtest.h>
#include <iostream>
#include "compose.h"
#include "print.h"

using namespace words::numbers;


TEST(composeSuite, units) { 

  vec_numbers v_num{number{word{order::units, 1}},
                    number{word{order::units, 2}},
                    number{word{order::units, 3}}};

  auto res = compose_numbers(v_num);

  ASSERT_EQ(res.size(), 3);
  for(const auto& elem: res){
    ASSERT_EQ(elem.size(), 1);
  }
}