#include <gtest/gtest.h>
#include <iostream>
#include "src/factory.hpp"
#include "src/print.hpp"

using namespace words::numbers;

TEST(factorySuite, units) { 

  int value{9};
  std::vector<number> v_num{};
  auto res = number_factory(word{order::units, value}, v_num);

  ASSERT_EQ(res.first, error::ok);
  ASSERT_EQ(res.second.size(), 1);
  ASSERT_EQ(res.second[0].word_inst.value, value);

  for(auto num : res.second){
    std::cout << num;
  }
  
}