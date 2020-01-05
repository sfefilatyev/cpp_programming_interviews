/***
Write a program which takes as input an array of digits encoding a non-negative decimal integer D
and updates the array to represent the integer D+1. For example, if the input  is <1, 2, 9> then
you should update the array to <1, 3, 0>
**/
#include <iostream>
#include <string>  // for std::stoi
#include <algorithm> // for std::copy and std::reverse


std::string incremented_string_integer(std::string &input){
    std::string inc_number(input);
    // Reversing the string so the least significant digit is in the beginning of the array.
    std::reverse(inc_number.begin(), inc_number.end());
    int index = 0;
    int digit = 0;
    int carry = 0;
    while(index < inc_number.length()){
        // returns a character, so to get a digit need to subtract index of '0'
        digit = static_cast<int>(inc_number[index] - '0');
        if (index == 0){  // first element of the array.
            digit++; // +1 is only for the first element.
        }
        else{
            digit += carry;
        }

        if (digit >= 10){
            digit = 0;
            carry = 1;
        }
        else{
            carry = 0;
        }
        inc_number[index] = static_cast<char>('0' + digit);

        index++;
    }

    if (carry == 1){
        inc_number.append("1");
    }
    std::reverse(inc_number.begin(), inc_number.end());
    return inc_number;
    
}

int main(int argc, char **argv){
    std::string number(argv[1]);
    std::cout << "Input number: " << number << std::endl;
    std::cout << "Incremented number: " << incremented_string_integer(number) << std::endl;
    
    return 0;
}
