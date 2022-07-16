#include "factory.h"

namespace words{

    namespace numbers{

        std::pair<error, vec_numbers> small_order_factory(const word word_inst, 
                                                          const vec_numbers& v_nums);

        std::pair<error, vec_numbers> large_order_factory(const word word_inst, 
                                                          const vec_numbers& v_nums);

        std::pair<error, vec_numbers> number_factory(const word word_inst, 
                                                     const vec_numbers& v_nums) {

            switch (word_inst.order_inst)
            {
            case order::units:
            case order::tens:
                return small_order_factory(word_inst, v_nums);
            case order::hundreds:
            case order::thousands:
            case order::millions:
            case order::billions:
                return large_order_factory(word_inst, v_nums);
            default:
                return {error::error, {}};
            }

        }

        std::pair<error, vec_numbers> small_order_factory(const word word_inst, 
                                                          const vec_numbers& v_nums) {
            vec_numbers v_copy{v_nums};

            v_copy.push_back(number{word_inst, {}}); 

            return {error::ok, v_copy};                                                        
        }

        std::pair<error, vec_numbers> large_order_factory(const word word_inst, 
                                                          const vec_numbers& v_nums) {

            vec_numbers v_copy{v_nums};
            number num{word_inst,{}};
            const int size = v_copy.size();
            bool found_lower_order{false};
            int while_idx{size -1};

            while(while_idx >= 0 && v_nums[while_idx].word_inst.order_inst < word_inst.order_inst){

                num.v_numbers.push_back(v_nums[while_idx]);
                found_lower_order = true;
                while_idx--;
            }

            if(!found_lower_order)
                return {error::error, {}};

            for(int i = size -1; i > while_idx; i--){
                v_copy.pop_back();
            }

            v_copy.push_back(num); 

            return {error::ok, v_copy};  
        }


    } // namespace numbers
} // namespace words