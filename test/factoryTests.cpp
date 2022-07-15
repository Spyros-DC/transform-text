#include <gtest/gtest.h>
#include <iostream>
#include "src/lib/include/factory.h"
#include "src/lib/include/print.h"

using namespace words::numbers;

TEST(factorySuite, units) { 

  int value{9};
  vec_numbers v_num{};
  auto res = number_factory(word{order::units, value}, v_num);

  ASSERT_EQ(res.first, error::ok);
  ASSERT_EQ(res.second.size(), 1);
  ASSERT_EQ(res.second[0].word_inst.value, value);
}

TEST(factorySuite, tens) { 

  int value{3};
  vec_numbers v_num{};
  auto res = number_factory(word{order::tens, 3}, v_num);
  if(res.first == error::ok){
    res = number_factory(word{order::units, 2}, res.second);
  }

  ASSERT_EQ(res.first, error::ok);
  ASSERT_EQ(res.second.size(), 2);
  ASSERT_EQ(res.second[0].word_inst.value, value);

}

TEST(factorySuite, hundreds) { 

  vec_numbers v_num{};
  auto res = number_factory(word{order::tens, 3}, v_num);
  if(res.first == error::ok){
    res = number_factory(word{order::units, 2}, res.second);
  }

  if(res.first == error::ok){
    res = number_factory(word{order::hundreds, 1}, res.second);
  }

  ASSERT_EQ(res.first, error::ok);
  ASSERT_EQ(res.second.size(), 1);
  ASSERT_EQ(res.second[0].v_numbers.size(), 2);

}