/***
Impelement integer to string convresion function. For example, if the input to the function
is the integer 314, it should return the string "314".
***/

#include <iostream>
#include <string> // std::stoi function
#include <algorithm> // std::reverse

std::string convert_int_to_string(int num){
    std::string result;
    int sign = num >= 0 ? 1 : -1;
    num = num / sign;
    while(num){
        // char-converted reminder of division by 10
        char reminder = static_cast<char>(num % 10) + '0';
        num = num / 10; // integer division
        result.push_back(reminder);
    }
    if (result.size() == 0){
        result.push_back('0');
        return result;
    }
    if (sign < 0){
        result.push_back('-');
    }
    std::reverse(result.begin(), result.end());
    return result;
    
}

int main(int argc, char* argv[])
{
    std::string int_str(argv[1]);
    // Pretending that we recieved integer type from the input to check the follow-up logic.
    int num = std::stoi(int_str);
    std::cout << "Input number:" << num << std::endl;
    std::cout << "Converted string: " << convert_int_to_string(num) << std::endl;
    return 0;
}
