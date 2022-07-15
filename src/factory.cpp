#include "factory.hpp"

namespace words{

    namespace numbers{

        std::pair<error, std::vector<number> > small_order_factory(word word_inst, 
                                                                   const std::vector<number>& v_numbers);

        std::pair<error, std::vector<number> > large_order_factory(word word_inst, 
                                                                   const std::vector<number>& v_numbers);

        std::pair<error, std::vector<number> > number_factory(const word word_inst, 
                                                              const std::vector<number>& v_numbers) {

            switch (word_inst.order_inst)
            {
            case order::units:
            case order::tens:
                return small_order_factory(word_inst, v_numbers);
                break;
            case order::hundreds:
            case order::thousands:
            case order::millions:
            case order::billions:
                return large_order_factory(word_inst, v_numbers);
                break;
            
            default:
                return {error::error, {}};
                break;
            }

        }

        std::pair<error, std::vector<number> > small_order_factory(word word_inst, 
                                                                   const std::vector<number>& v_numbers) {
            std::vector<number> v_copy{v_numbers};

            v_copy.push_back(number{word_inst, {}}); 

            return {error::ok, v_copy};                                                        
        }

        std::pair<error, std::vector<number> > large_order_factory(word word_inst, 
                                                                   const std::vector<number>& v_numbers) {

            std::vector<number> v_copy{v_numbers};

            if(v_copy.empty())
                return {error::error, {}};

            const int size{v_copy.size()};

            bool found_lower_order{false};

            number num{word_inst,{}};

            int idx{size -1};

            while(v_numbers[idx].word_inst.order_inst < word_inst.order_inst){

                num.v_numbers.push_back(v_numbers[idx]);
                found_lower_order = true;
                idx--;
            }

            if(!found_lower_order)
                return {error::error, {}};

            for(int i = size -1; i > idx; idx--){
                v_copy.pop_back();
            }

            v_copy.push_back(num); 

            return {error::ok, v_copy};  


        }


    } // namespace numbers
} // namespace words