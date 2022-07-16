#include <gtest/gtest.h>
#include "processing.h"
#include "convert.h"

namespace text {
    std::string replace(const std::string &str, std::string original, std::string replace);

    std::vector<std::string> remove_one_character(const std::string &str, char c);
}

TEST(processingSuite, first) {
    std::string str{"your amount is one hundred and fifty five"};
    ASSERT_EQ( text::replace(str, "one hundred and fifty five", "155"), "your amount is 155");
}

TEST(processingSuite, second) {
    std::string str{"twenty-two"};
    auto res = text::remove_one_character(str, '-');
    ASSERT_EQ( res.size(), 2);
    ASSERT_EQ( res[0], "twenty");
    ASSERT_EQ( res[1], "two");
}

TEST(processingSuite, third) {
    std::string str{"twenty--two"};
    auto res = text::remove_one_character(str, '-');
    ASSERT_EQ( res.size(), 1);
    ASSERT_EQ( res[0], "twenty--two");
}

TEST(processingSuite, fourth) {
    std::string str{"twenty.two"};
    auto res = text::remove_one_character(str, '.');
    ASSERT_EQ( res.size(), 2);
    ASSERT_EQ( res[0], "twenty");
    ASSERT_EQ( res[1], "two");
}

TEST(processingSuite, fifth) {
    std::string str{"Tom is twenty three and Laura is twenty one"};
    text::processor processor_inst{str};
    processor_inst.find_pairs_for_replace();
    for(auto elem: processor_inst.pairs_for_replace()){
        std::cout << elem.first << " - " << elem.second << "\n";
    }
}

TEST(processingSuite, sixth) {
    std::string str{"Tom is twenty three and Laura is twenty one"};
    std::string res{str};
    text::processor processor_inst{str};
    processor_inst.find_pairs_for_replace();

    ASSERT_EQ(processor_inst.run(), "Tom is 23 and Laura is 21");
}

TEST(processingSuite, seventh) {
    std::string str{"Tom is twenty   three and Laura is twenty     one"};
    std::string res{str};
    text::processor processor_inst{str};
    processor_inst.find_pairs_for_replace();

    ASSERT_EQ(processor_inst.run(), "Tom is 23 and Laura is 21");
}