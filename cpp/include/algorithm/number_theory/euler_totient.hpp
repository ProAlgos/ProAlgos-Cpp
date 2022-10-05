/*
    Euler's Totient
    ---------------
    Euler's totient function counts the number of positive integers from 1 to given
    number N that are coprime to N. That is, phi(N) is a number of positive integer
    i such that 1 <= i <= N and GCD(i, N) = 1.

    Time complexity
    ---------------
    O(sqrt(N)), where N is number for which Euler totient is calculated.

    Space complexity
    ----------------
    O(1).
*/

#ifndef EULER_TOTIENT_HPP
#define EULER_TOTIENT_HPP

typedef unsigned long long int ULL;

ULL euler_totient(ULL num) {
    if (num < 0){
        return -1;
    }
    ULL count_of_coprimes = num;
    for (ULL i = 2; i * i <= num; i++) {
        if (num % i == 0){
            while(num % i == 0){
                num = num / i;
            }
            count_of_coprimes = count_of_coprimes - (count_of_coprimes / i);
        }
    }

    if (num > 1){
        count_of_coprimes = count_of_coprimes - (count_of_coprimes / num);
    }
    return count_of_coprimes;
}

#endif // EULER_TOTIENT_HPP