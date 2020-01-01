/***
Implemented naively, quicksort has large run times and deep function call stack on arrays with
many duplicates because the subarrays may differ greatly in size. One solution is to re-order 
the array so that all eleemnts less than pivot appear first, followed by elements equal to the 
pivot, followed by elements greater than the pivot. This is known as Dutch national flag 
partitioning, because the Dutch national flag consists of three horizontal bands, each in a 
different color. 

Write a program that takes an array A an dan index i into A, and re-arranges 
the elements such that all elements less than A[i] appear first, followed by elements equal to 
the pivot, followed by elements greater than the pivot.
***/

#include <algorithm> // std::copy
#include <iostream>
#include <iterator> //std::ostream_iterator
#include <vector>
#include <string> // std::stoi

using namespace std;

int main(int argc, char** argv)
{
    int pivot_index = stoi(argv[1]);
    vector<int> A{1, 6, 3, 4, 5, 2, 7};
    cout << "Input array: " ;
    std::copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));    
    cout << endl;
    int pivot_value = A[pivot_index];
    int lower_index = 0, equal_index = 0, larger_index = A.size();
    while (equal_index < larger_index){
        if (A[equal_index] < pivot_value){
            int temp = A[lower_index];
            A[lower_index] = A[equal_index];
            A[equal_index] = temp;
            equal_index++;
            lower_index++;
        }
        else if (A[equal_index] == pivot_value){
            equal_index++;
        }
        else{ // A[equal_index] > pivot_value
            lower_index--;
            int temp = A[lower_index];
            A[lower_index] = A[equal_index];
            A[equal_index] = temp;
        }
    }
    cout << "Re-arranged array: ";
    std::copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

