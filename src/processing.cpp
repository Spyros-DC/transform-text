#include "processing.h"
#include "config.h"
#include "convert.h"
#include <regex>

namespace text {

    std::string replace(const std::string& str, std::string original, std::string replace);

    std::pair<bool, std::string> find_if_stop_word(const std::string maybe_num);

    std::string to_lower_case(std::string str);

    std::string replace(const std::string& str, std::string original, std::string replace) {
        return std::regex_replace(str, std::regex(original), replace);
    }

    std::string to_lower_case(std::string str){
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return str;
    }

    std::pair<bool, std::string> find_if_stop_word(const std::string maybe_num) {
        std::set<char> set_of_stop_chars{'.', '!', ';'};

        if(maybe_num.empty())
            return {false, maybe_num};

        if(!set_of_stop_chars.count(maybe_num.back()))
            return {false, maybe_num};

        std::string word{};
        for(auto character: maybe_num){
            if(!set_of_stop_chars.count(character))
                word += character;
            else
                break;
        }

        return {true, word};
    }

    processor::processor(const std::string& str): str_{str} {}

    std::pair<error, std::string> processor::run() {

        this->remove_dashes();
        std::string res{str_};

        this->find_pairs_for_replace();

        for(auto replace_elem: pairs_for_replace_){

            std::string original_substr = this->find_substr(replace_elem.first);
            if(original_substr.empty())
                return {error::error, {}};

            auto words = this->convert_to_words(replace_elem.second);
            auto pair_error_nums = convert_words_to_nums(words);

            std::string replace_str{};
            for(auto elem: pair_error_nums.second)
                replace_str += std::to_string( convert_vec_of_nums_to_num(elem) );

            res = replace(res, original_substr, replace_str);

        }

        return {error::ok, res};
    }

    void processor::find_pairs_for_replace() {

        std::stringstream stream_inst{str_};

        std::string maybe_num{};
        bool is_number{false};
        std::string original_sub_string{};
        std::string replace_sub_string{};
        bool is_stop_word{false};

        while(stream_inst >> maybe_num){
            std::string lower_case_maybe_num = to_lower_case(maybe_num);

            if(is_number && lower_case_maybe_num == "and")
                continue;
            std::pair<bool, std::string> p_find_stop_word_res = find_if_stop_word(maybe_num);
            if(p_find_stop_word_res.first){
                is_stop_word = true;
                maybe_num = p_find_stop_word_res.second;
                lower_case_maybe_num = to_lower_case(maybe_num);
            }

            if(set_of_number_words.count(lower_case_maybe_num)){
                if(is_number){
                    original_sub_string += " " + maybe_num;
                    replace_sub_string += " " + lower_case_maybe_num;
                }else{
                    is_number = true;
                    if(!replace_sub_string.empty())
                        pairs_for_replace_.push_back({original_sub_string, replace_sub_string});
                    original_sub_string.clear();
                    replace_sub_string.clear();
                    original_sub_string += " " + maybe_num;
                    replace_sub_string += " " + lower_case_maybe_num;
                }

                if(is_stop_word)
                    is_number = false;
            }else{
                is_number = false;
            }
        }
        if(!replace_sub_string.empty())
            pairs_for_replace_.push_back({original_sub_string, replace_sub_string});

    }

    std::vector<std::pair<std::string, std::string> > processor::pairs_for_replace() {
        return pairs_for_replace_;
    }

    std::string processor::find_substr(const std::string pattern) {

        std::stringstream stream_inst{pattern};
        std::string num{};
        std::vector<std::string> v_str{};

        while(stream_inst >> num){
            v_str.push_back(num);
        }

        std::string str_regex{};
        int idx{1};
        int size = v_str.size();
        for(auto elem: v_str){
            str_regex += elem;
            if(idx != size)
                str_regex += " +(and)? ?";
            idx++;
        }

        std::regex r{str_regex};

        for(auto iter = std::sregex_iterator(str_.begin(), str_.end(), r);
            iter != std::sregex_iterator();
            ++iter){
            std::smatch m = *iter;
            return m.str();
        }

        return "";
    }

    std::vector<word> processor::convert_to_words(std::string str) {
        std::vector<word> v_words{};

        std::stringstream stream_inst{str};
        std::string loop_str{};
        while(stream_inst >> loop_str){
            v_words.push_back(text::config_m[loop_str]);
        }

        return v_words;
    }

    void processor::remove_dashes() {
        std::stringstream str_stream{str_};
        std::string word{};
        while(str_stream >> word){
            auto idx = word.find('-');

            if(idx == std::string::npos)
                continue;

            std::string first_part{word.begin(), word.begin() + idx};
            std::string second_part{word.begin() + idx + 1, word.end()};

            auto p_res = find_if_stop_word(second_part);
            std::string set_second_part = p_res.second;

            if(set_of_number_words.count(first_part) && set_of_number_words.count(set_second_part))
                str_ = replace(str_, word, std::string{first_part+ " " + second_part});
        }
    }

}// namespace text