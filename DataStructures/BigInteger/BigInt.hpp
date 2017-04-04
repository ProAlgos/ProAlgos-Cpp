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
    void operator+(const BigInt&);  // TODO
    void operator+(long long);      // TODO
    void operator-(const BigInt&);  // TODO
    void operator-(long long);      // TODO
    void operator*(const BigInt&);  // TODO
    void operator*(long long);      // TODO
    void operator/(const BigInt&);  // TODO
    void operator/(long long);      // TODO
    void operator%(const BigInt&);  // TODO
    void operator%(long long);      // TODO

    // Arithmetic-assignment operators:
    void operator+=(const BigInt&); // TODO
    void operator+=(long long);     // TODO
    void operator-=(const BigInt&); // TODO
    void operator-=(long long);     // TODO
    void operator*=(const BigInt&); // TODO
    void operator*=(long long);     // TODO
    void operator/=(const BigInt&); // TODO
    void operator/=(long long);     // TODO
    void operator%=(const BigInt&); // TODO
    void operator%=(long long);     // TODO

    // Unary operators:
    BigInt operator-() const;
    BigInt operator++(int); // TODO
    BigInt& operator++();    // TODO
    BigInt operator--(int); // TODO
    BigInt& operator--();    // TODO

    // Relational operators:
    bool operator<(const BigInt&) const;
    bool operator<(long long) const;
    bool operator<=(const BigInt&) const;
    bool operator<=(long long) const;
    bool operator==(const BigInt&) const;
    bool operator==(long long) const;
    bool operator>=(const BigInt&) const;
    bool operator>=(long long) const;
    bool operator>(const BigInt&) const;
    bool operator>(long long) const;
    bool operator!=(const BigInt&) const;
    bool operator!=(long long) const;

    // I/O stream operators:
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
};

#endif
