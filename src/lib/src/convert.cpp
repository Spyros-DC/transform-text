#include "convert.h"
#include "factory.h"
#include "compose.h"

namespace words{

    namespace numbers{

        long long to_num(order order_inst);

        long long to_num(word word_inst);

        long long to_num(const order order_inst) {
            switch (order_inst) {
                case order::units:
                    return 1;
                case order::tens:
                    return 10;
                case order::hundreds:
                    return 100;
                case order::thousands:
                    return 1000;
                case order::millions:
                    return (1000*1000);
                case order::billions:
                    return (1000*1000*1000);
                default:
                    return 0;
            }
        }

        long long to_num(const word word_inst) {
            return (to_num(word_inst.order_inst) * word_inst.value);
        }

        long long convert_vec_of_nums_to_num(const vec_numbers& v_nums) {
            long long res{0};

            for(const auto& num: v_nums){

                long long loop_res{to_num(num.word_inst)};

                long long internal_res = convert_vec_of_nums_to_num(num.v_numbers);

                if(internal_res)
                    loop_res *= internal_res;

                res += loop_res;
            }

            return res;
        }

        std::pair<error, vec_vec_numbers> convert_words_to_nums(const std::vector<word>& v_words) {

            vec_numbers v_nums{};

            for(const auto& w: v_words){
                auto loop_res = number_factory(w, v_nums);
                if(loop_res.first != error::ok)
                    return {error::error, {}};
                v_nums = loop_res.second;
            }

            return {error::ok, compose_numbers(v_nums)};
        }

    } // namespace numbers
} // namespace words