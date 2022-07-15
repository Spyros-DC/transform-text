#include "src/lib/include/compose.h"

namespace words{

    namespace numbers{

        vec_vec_numbers compose_numbers(const vec_numbers& v_nums) {

            vec_vec_numbers res{};

            vec_numbers v_nums_to_add{};
            for(const auto& num: v_nums){

                if(v_nums_to_add.empty()){
                    v_nums_to_add.push_back(num);
                    continue;
                }
                
                order num_order{num.word_inst.order_inst};
                order last_added_num_order{v_nums_to_add.back().word_inst.order_inst};
                if(last_added_num_order > num_order){
                    v_nums_to_add.push_back(num);
                }else{
                    res.push_back(v_nums_to_add);
                    v_nums_to_add.clear();
                    v_nums_to_add.push_back(num);
                }
            }
            if(!v_nums_to_add.empty())
                res.push_back(v_nums_to_add);

            return res;
        }

    } // namespace numbers
} // namespace words