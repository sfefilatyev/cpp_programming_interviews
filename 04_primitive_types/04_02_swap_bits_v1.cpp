/*** Swap Bits

Implement code that takes as input a 64-bit integer and swaps the bits at indices i and j.
***/

#include <iostream>
#include <cstdlib>  // source of atoi function

int main(int argc, char** argv)
{
    int number = atoi(argv[1]);
    int i = atoi(argv[2]);
    int j = atoi(argv[3]);

    if (number >> i == number >> j)
    {
        // since both bits on position i and j are the same swapping does not change anything.
        std::cout << number << std::endl; 
    }
    else
    {
        int mask = 1 << i | 1 << j;
        number = number ^ mask;
        std::cout << number << std::endl;
    }
}
