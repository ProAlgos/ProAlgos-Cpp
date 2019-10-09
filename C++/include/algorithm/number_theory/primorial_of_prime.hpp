/*
    PRIMORIAL VALUE OF A PRIME NUMBER
    ---------------------------------------------
    Find the Primorial value of a prime number P(n), given the value of the prime number.
    The Primorial for a prime number,P(n) is the product of all prime numbers less than 
    or equal to the P(n).


    Time Complexity
    ---------------------------------------------
    O(N^(3/2)), where N is the prime number, whose Primorial to be calculated.


    Space Complexity
    ---------------------------------------------
    O(1)
*/

#ifndef PRIMORIAL_OF_PRIME_HPP
#define PRIMORIAL_OF_PRIME_HPP

typedef unsigned long long int ULL;



/* A function to check where a number(num) is prime or not,
    accordingly it just returns the true or false*/

bool check_prime(int num){
    bool flag = true;           

    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            flag = false;
    }

    return flag;        //flag is an indicator if num if prime-or-not.
}



const int MAX_PRIME_NUM = 53;             //as primorial_of_prime(53) goes beyond the range of ULL.



/* The function which takes the prime number P(n) as input,
    and return its primorial value. 
    Moreover, if the input value is not prime,or its primorial value is beyond the range of ULL, it will return -1 value.
*/

ULL primorial_of_prime(const int prime_value){

    if(check_prime(prime_value) != true){           //checking is the input value is not prime.
        return -1;
    }

    ULL primorial = 1;                            

    for(int i = 2; i <= prime_value; i++){
        
        if(check_prime(i) == true){
            primorial *= i;
        }
    }

    return primorial;                             //returning the calculated primorial value.
}


#endif      