/***
Write a program that takes two arrays representing integers, and returns an integer representing their product.
For example, since 193707721 x -761838257287 = -147573952589676412927, if the inputs are <1, 9, 3, 7, 0, 7, 7, 1> 
and <-7, 6, 1, 8, 3, 8, 2, 8, 7>, your function should return the following array: 
<-1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7>.
***/

#include <vector>
#include <iostream> 
#include <iterator> // std::ostream
#include <string>   // std::stoi
#include <algorithm> // std::reverse, std::copy

std::vector<int> multiply_two_integer_arrays(std::vector<int> num1, std::vector<int>num2)
{
    std::vector<int> result(num1.size() + num2.size(), 0);
    int sign = (num1[0] < 0 ^ num2[0] < 0) ? -1 : 1;
    if (sign < 0){
        num1[0] = std::abs(num1[0]);
        num2[0] = std::abs(num2[0]);
    }

    for (int i = num1.size() - 1; i>=0; --i){
        for(int j = num2.size() - 1; j>=0; --j) {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10; // integer divide
            result[i + j + 1] %= 10; // modulus (reminder of division by 10)
        }
    }

    while (result[0] == 0){
        result.erase(result.begin());
    }

    result[0] *= sign;
    return result;
}

std::vector<int> convert_string_to_int_array(std::string str){
    std::vector<int> converted;
    int sign = str[0] == '-' ? -1 : 1;
    int start_index = sign > 0 ? 0 : 1; // starting processing int characters after 'minus' sign.
    for (int i = start_index; i < str.length(); ++i){
        converted.push_back(static_cast<int>(str[i] - '0'));
    }
    converted[0] *= sign;
    return converted;
}

int main(int argc, char* argv[])
{
    if(argc != 3){
        std::cout << "Please provide two integers as string arguments to the program" << std::endl;
        return -1;
    }
    
    std::string num1_str(argv[1]);
    std::string num2_str(argv[2]);

    std::cout << "Number 1: " << num1_str << std::endl;
    std::cout << "Number 2: " << num2_str << std::endl;

    std::vector<int> num1 = convert_string_to_int_array(num1_str);
    std::cout << "Converted num1 = ";
    std::copy(num1.begin(), num1.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << std::endl;

    std::vector<int> num2 = convert_string_to_int_array(num2_str);
    std::cout << "Converted num2 = ";
    std::copy(num2.begin(), num2.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << std::endl;

    std::vector<int> product = multiply_two_integer_arrays(num1, num2);
    std::cout << "Product: ";
    std::copy(product.begin(), product.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << std::endl;
    
}
