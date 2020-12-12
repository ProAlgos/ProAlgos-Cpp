/*
    String Hashing Function
    -----------------------
    A string hashing function is used when comparing two strings, by 
    converting both numbers called hashes, we can make the assumption 
    that two strings s and t are equal if and only if their hashes are 
    equal. 

    Time complexity
    ---------------
    O(1), when comparing two strings 

    Space complexity
    ----------------
    O(N), where N is the length of the string

 * */

#ifndef STRING_HASH
#define STRING_HASH
#include <climits>
#include <cstdint>
#include <string>

// Constant value used in polynomial rolling hash function
const int PRIME = 53;  

// Arbitrary large prime number to use as modulo, used to avoid collisions
const long long MOD = 1e9 + 9; 

int compute_hash(std::string const& s) {
    int hash_value = 0;     
    long long prime_power = 1; 

    // Consider strings containing spaces as having hash value of 0
    if(s.find_first_not_of(' ') == std::string::npos) { 
        return 0;
    } else {
        for(char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * prime_power) % MOD;
            prime_power = (prime_power * PRIME) % MOD;
        }
        return hash_value;
    }
}
#endif
