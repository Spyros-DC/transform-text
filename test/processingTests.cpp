#include <gtest/gtest.h>
#include "processing.h"
#include "convert.h"

namespace text {
    std::string replace(const std::string &str, std::string original, std::string replace);

    std::vector<std::string> remove_one_character(const std::string &str, char c);

    std::pair<bool, std::string> find_if_stop_word(const std::string maybe_num);
}

TEST(processingSuite, first) {
    std::string str{"your amount is one hundred and fifty five"};
    ASSERT_EQ( text::replace(str, "one hundred and fifty five", "155"), "your amount is 155");
}

TEST(processingSuite, second) {

    std::string str{"Zero costs."};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "0 costs.");
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

    ASSERT_EQ(processor_inst.run().second, "Tom is 23 and Laura is 21");
}

TEST(processingSuite, seventh) {
    std::string str{"Tom is twenty   three and Laura is twenty     one"};
    std::string res{str};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "Tom is 23 and Laura is 21");
}

TEST(processingSuite, eighth) {
    std::string str{"one hundred twenty-three"};
    std::string res{str};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "123");
}

TEST(processingSuite, ninth) {
    std::string str{"this tree is one hundred twenty-three years old."};
    std::string res{str};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "this tree is 123 years old.");
}

TEST(processingSuite, tenth) {
    std::string str{"this tree is one hundred and twenty-three."};
    std::string res{str};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "this tree is 123.");
}

TEST(processingSuite, eleventh) {

    auto p_res = text::find_if_stop_word("three.");
    ASSERT_EQ(p_res.first, true);
    ASSERT_EQ(p_res.second, "three");
}

TEST(processingSuite, twelfth) {

    std::string str{"one million two hundred and thirty-three thousand four hundred and forty-five"};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "1233445");
}

TEST(processingSuite, thirteenth) {

    std::string str{"One hundred and twenty five. Three."};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "125. 3.");
}

TEST(processingSuite, fourteenth) {

    std::string str{"One hundred and twenty-five."};
    text::processor processor_inst{str};

    ASSERT_EQ(processor_inst.run().second, "125.");
}