#include <iostream>
#include <fstream>
#include "processing.h"

void terminal_input() {
    std::string str{};
    std::getline(std::cin, str);
    while(true) {
        std::cout << "type a string with a number in words, or 'exit' to exit\n";
        std::getline(std::cin, str);
        if (str == "exit")
            break;
        auto p_res = text::processor{str}.run();
        if(p_res.first == words::numbers::error::ok) {
            std::cout << p_res.second << "\n";
        }else{
            std::cout << "error on processing text" << "\n";
            break;
        }
    }
}

void file_input() {
    std::string str{};
    std::getline(std::cin, str);
    std::cout << "please provide input file path\n";
    std::string input_file{};
    std::getline(std::cin, input_file);
    std::cout << "please provide output file name\n";
    std::string output_file{};
    std::getline(std::cin, output_file);

    std::ifstream in_stream{input_file};
    if(!in_stream.is_open()){
        std::cout << "error on opening file << " << input_file << "\n";
        return;
    }
    std::string line;

    std::ofstream out_stream{output_file};
    while( std::getline(in_stream, line) ){
        auto p_res = text::processor{str}.run();
        if(p_res.first == words::numbers::error::ok) {
            out_stream << p_res.second << "\n";
        }else{
            std::cout << "error on processing text" << "\n";
            break;
        }
    }

}

int main() {

    std::cout << "please type 1 for file input or 2 for terminal input\n";

    int choice{};
    std::cin >> choice;

    if(choice == 1)
        file_input();
    else if(choice == 2)
        terminal_input();

    return 0;
}