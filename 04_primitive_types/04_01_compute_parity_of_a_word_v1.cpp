/*** Compute parity of  a word.

The partiy of a binary word is 1 if the number of 1s is in the word is odd; otherwise, it is 0. For example, the parity of 1011 is 1, and the parity of 10001000 is 0.
***/

#include <iostream>
#include <string>  // std::stoi
#include <cstdlib> // std::atoi

int main(int argc, char** argv)
{
    int number = std::atoi(argv[1]);
    int one_bits = 0;

    while (number){
        if (number & 1)
            one_bits++;
        number = number >> 1;
    }

    if (one_bits % 2 == 1)
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;

    return 0;
}
