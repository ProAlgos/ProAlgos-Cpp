/*
<Brain_Kernighan Algorithm>
-------------------
<Write an efficient program to count number of 1s in binary representation of an integer>

Time complexity
---------------
O(log n), where <n is equal to number of 1 in the binary form of input number.>    

*/

#include<iostream>
using namespace std;

/* Function to get no of set bits in binary
   representation of passed binary no. */
unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

/* Program to test function countSetBits */
int main()
{
    int input;
    int num_set_bits;

    cout<<"\nEnter a number : ";
    cin>>input;


    num_set_bits =  countSetBits(input);

    cout<<"\nNumber of set Bits in "<<input<<" is "<<num_set_bits;
    
    return 0;
}