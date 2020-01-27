/**
Implement string to integer conversion function. For example, if the input to the
funcion is the string "-314", the function should return the integer -314.
**/

#include <iostream>
#include <string>  // std::stoi
#include <algorithm> // std::reverse

int string_to_int_conversion(std::string & str_num){
    int sign = 1;
    int index = 0; // index to start processing of a string.
    int num = 0;
    if (str_num[0] == '-'){
        sign = -1;
        index = 1;
    }
    while(index < str_num.size()){
        num = num * 10;
        num += static_cast<int>(str_num[index] - '0');
        index++;
    }
    num *= sign;
    return num;
}

int main(int argc, char* argv[]){
    std::string str_num(argv[1]);
    std::cout << "Input string: " << str_num << std::endl;   
    std::cout << "Output number: " << string_to_int_conversion(str_num) << std::endl;
    return 0;
}
