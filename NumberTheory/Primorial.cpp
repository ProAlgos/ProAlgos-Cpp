/*
    Primorial
    ---------
    Calculate the product of all the prime numbers up to a given prime number.
    Given a prime number N, or the index of a prime number N, we calculate the
    primorial value of this prime number.    
    The 15th primorial is 614889782588491410(18 in length). It fits in a
    unsigned long long variable.
    The 15th prime number is 47(starting with 2 as the first prime number).
    
    
    Time complexity
    ---------------
    prime number case : O(N * sqrt(N)), where N is the prime number up to which
    we calculate the primorial.
    prime number index case : O(N * sqrt(M)), where N is the index of the prime
    number and M is the prime number with index N.

    Space complexity
    ----------------
    O(1), constant amount of extra space
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef unsigned long long int ULL;

bool isNumberPrime(const unsigned int number)
{
    const unsigned int numberSqrt = (int)sqrt(number);
    for(unsigned int i = 2; i <= numberSqrt; ++i)
        if(number % i == 0)
            return false;
    return true;
}

void getPrimeNumber(short &primeNumber)
{
    do{
        cout << "Enter a prime number(2 - 47):";
        cin >> primeNumber;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
    }while((int) primeNumber < 2 || (int)primeNumber > 47 || 
        !isNumberPrime(primeNumber));
}

void getPrimeNumberIndex(short &primeNumberIndex)
{
    do{
        cout << "Enter a prime number index(1 - 15):";
        cin >> primeNumberIndex;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
    }while((int) primeNumberIndex < 1 || (int)primeNumberIndex > 15);
}

void getOption(char &option)
{
    do{
        cout << "1. Input a prime number\n";
        cout << "2. Input a prime number index\n";
        cout << "Select an option(1,2):";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }while(option != '1' && option != '2');
}

ULL primorial(const short primeNumber)
{
    ULL primorialValue = 2;
    for(short i = 3; i <= primeNumber; ++i)
        if(isNumberPrime(i))
            primorialValue *= i;
    return primorialValue;
}

ULL primorialWithIndex(const short primeNumberIndex)
{
    short number = 3, counter = 1;
    ULL primorialValue = 2;
    
    while(counter < primeNumberIndex)
    {
        if(isNumberPrime(number))
        {
            primorialValue *= number;
            ++counter;
        }
            
        ++number;
    }
    
    return primorialValue;
}

void applyOption(const char option)
{
    if(option == '1')
    {
        short primeNumber;
        getPrimeNumber(primeNumber);
        cout << "The primorial value of " << primeNumber << " is " <<
            primorial(primeNumber);
    }
    else // if not '1' then it is definitly '2'
    {
        short primeNumberIndex;
        getPrimeNumberIndex(primeNumberIndex);
        cout << "The primorial value of the prime number with index " <<
            primeNumberIndex << " is " << primorialWithIndex(primeNumberIndex);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);   // don't sync C++ streams with C streams

    char option = 0;
    getOption(option);
    applyOption(option);
    
    return 0;
}
