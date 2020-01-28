/**
Impelement a function for reversing the words in a string.
**/

#include <iostream>
#include <string>
#include <algorithm> // std::reverse
#include <cctype> // std::isalnum()

std::string reverse_all_words(std::string str1){
    std::string str(str1);
    std::reverse(str.begin(), str.end());
    return str;
    int start_range = 0;
    int end_range = 0;
    while(end_range < str.size()) {
        end_range = str.find(" ", start_range);
        if(end_range == std::string::npos)
            break;
        std::reverse(str.begin() + start_range, str.begin() + end_range);
        start_range = end_range + 1;
    }
    // Reverse the last word.
    std::reverse(str.begin() + start_range, str.begin() + end_range);
    return str;
}


int main(int argc, char* argv[]){
    std::string str(argv[1]);
    //std::cout << "Enter a sentence of several words:" << std::endl;
    //std::cin >> str;
    std::cout << str << std::endl;
    std::cout << "Sentence with reversed words is:" << std::endl;
    std::cout << reverse_all_words(str) << std::endl;
    return 0;
}
