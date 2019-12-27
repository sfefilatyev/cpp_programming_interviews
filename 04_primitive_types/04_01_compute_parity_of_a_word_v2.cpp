/***
How would you compute number of very large 64-bits word?
Parity of a binary word is 1 if the number of 1s in the word is odd, otherwise parity is 0.
For example, the parity of 1011 is 1, and the parity of 10001000 is 0.
***/
#include <iostream>
#include <string>

int get_word_parity(int number)
{
    int parity = 0;
    while(number)
    {
        parity = parity ^ 1;
        number = number & (number - 1);
    }
    return parity;
}

int main(int argc, char** argv)
{
   std::string number_str = std::string(argv[1]);
   int number = std::stoi(number_str);
   std::cout << get_word_parity(number) << std::endl; 
   return 0;
}
