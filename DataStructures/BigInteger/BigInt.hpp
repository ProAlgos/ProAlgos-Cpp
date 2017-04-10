#ifndef BIG_INT_HPP
#define BIG_INT_HPP

#include <iostream>

class BigInt {
    std::string value;
    char sign;
public:
    // Constructors:
    BigInt();
    BigInt(const BigInt&);
    BigInt(std::string);
    BigInt(long long);
    // TODO: add support for unsigned long long

    // Assignment operators:
    void operator=(const BigInt&);
    void operator=(long long);
    void operator=(std::string);

    // Arithmetic operators:
    BigInt operator+(const BigInt&);  
    BigInt operator+(long long);
    BigInt operator-(const BigInt&);  
    BigInt operator-(long long);      
    BigInt operator*(const BigInt&); 
    BigInt operator*(long long);      
    void operator/(const BigInt&);  // TODO
    void operator/(long long);      // TODO
    void operator%(const BigInt&);  // TODO
    void operator%(long long);      // TODO

    // Arithmetic-assignment operators:
    void operator+=(const BigInt&);
    void operator+=(long long);
    void operator-=(const BigInt&); 
    void operator-=(long long);     
    void operator*=(const BigInt&); 
    void operator*=(long long);     
    void operator/=(const BigInt&); // TODO
    void operator/=(long long);     // TODO
    void operator%=(const BigInt&); // TODO
    void operator%=(long long);     // TODO

    // Unary operators:
    BigInt operator-();
    BigInt operator++(int); 
    BigInt operator++();    
    BigInt operator--(int); 
    BigInt operator--();    

    // Relational operators:
    bool operator>(const BigInt&);	
    bool operator>(long long);		
    bool operator>=(const BigInt&); 
    bool operator>=(long long);		
    bool operator<(const BigInt&);	
    bool operator<(long long);		
    bool operator<=(const BigInt&);	
    bool operator<=(long long);		
    bool operator==(const BigInt&);	
    bool operator==(long long);		
    bool operator!=(const BigInt&);	
    bool operator!=(long long);		

    // I/O stream operators:
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
};

#endif