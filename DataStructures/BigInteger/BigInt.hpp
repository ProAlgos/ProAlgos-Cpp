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
    BigInt operator/(const BigInt&);
    BigInt operator/(long long);
    BigInt operator%(const BigInt&);
    BigInt operator%(long long);

    // Arithmetic-assignment operators:
    void operator+=(const BigInt&);
    void operator+=(long long);
    void operator-=(const BigInt&);
    void operator-=(long long);
    void operator*=(const BigInt&);
    void operator*=(long long);
    void operator/=(const BigInt&);
    void operator/=(long long);
    void operator%=(const BigInt&);
    void operator%=(long long);

    // Unary operators:
    BigInt operator-();
    BigInt operator++(int);
    BigInt operator++();
    BigInt operator--(int);
    BigInt operator--();

    // Relational operators:
    bool operator>(const BigInt&) const;
    bool operator>(long long) const;
    bool operator>=(const BigInt&) const;
    bool operator>=(long long) const;
    bool operator<(const BigInt&) const;
    bool operator<(long long) const;
    bool operator<=(const BigInt&) const;
    bool operator<=(long long) const;
    bool operator==(const BigInt&) const;
    bool operator==(long long) const;
    bool operator!=(const BigInt&) const;
    bool operator!=(long long) const;

    // I/O stream operators:
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
};

#endif