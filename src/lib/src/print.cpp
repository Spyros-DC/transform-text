#include "print.h"

std::ostream& operator<<(std::ostream& os, const order& ord) {
    if(ord == order::units)
        os << " units ";
    else if(ord == order::tens)
        os << " tens ";
    else if(ord == order::hundreds)
        os << " hundreds ";
    else if(ord == order::thousands)
        os << " thousands ";
    else if(ord == order::millions)
        os << " millions ";
    else if(ord == order::billions)
        os << " billions ";
        
    return os;
}

std::ostream& operator<<(std::ostream& os, const word& w) {
    os << " order: " << w.order_inst << "\n";
    os << " value: " << w.value << "\n";

    return os;
}


std::ostream& operator<<(std::ostream& os, const number& num) {
    os << num.word_inst;
    int idx{1};
    for(auto elem: num.v_numbers){
        os << "elem :" << idx << "\n";
        os << elem;
        idx++;
    }
    return os;
}