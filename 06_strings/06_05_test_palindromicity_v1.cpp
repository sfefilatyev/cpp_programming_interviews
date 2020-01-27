/**
Implement a function which takes as input a string s and returns true if s is palindromic string.
For the purpose of this problem, a palindromic string is a string which, when all non-alphanumeric
characters are removed, reads the same front to back ignoring the case.
**/

#include <iostream>
#include <string>
#include <locale> // std::tolower()
#include <cctype> // std::isalnum()


bool is_palindromic_string(std::string& str){
    int idx1 = 0;
    int idx2 = str.size() -1;
    while(idx1 < idx2){
        while(!std::isalnum(str[idx1]) && idx1 < idx2){
            idx1++;
        }
        while(!std::isalnum(str[idx2]) && idx1 < idx2){
            idx2--;
        }
        if (std::tolower(str[idx1]) != std::tolower(str[idx2]))
              return false;
        idx1++;
        idx2--;
    }
    return true;
}


int main(int argc, char* argv[]){
    std::string str;
    std::cout << "Enter a sentence:" << std::endl;
    std::cin >> str;
    std::cout << std::endl;
    if(is_palindromic_string(str))
        std::cout << "String is palindromic" << std::endl;
    else
        std::cout << "String is NOT palindromic" << std::endl;
}
