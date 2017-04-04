// BigInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "BigInt.hpp"

bool is_valid_number(const std::string& num);
void notify_invalid_input(const std::string& input);

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	// COMPLETE
	// constructor tests (incl. utility methods)
	BigInt large_int(s);
	BigInt large_int2(large_int);
	BigInt int_test(4);
	BigInt str_test = "789";
	BigInt int_test2 = -777;
	std::cout << large_int << ' ' << large_int2 << ' ' << int_test << ' ' << str_test << ' ' << int_test2;
	*/
	
	/*
	// COMPLETE
	// cin test
	BigInt cin_test;
	std::cout << "Please enter number for BigInt cin_test: ";
	std::cin >> cin_test;
	std::cout << cin_test;
	*/
	
	/*
	// COMPLETE
	// unary negation tests
	// DON'T FORGET TO TEST ++ ON A NEGATIVE NUMBER ONCE SUBTRACTION IS IMPLEMENTED
	BigInt unary_test1 = "5";
	std::cout << "The negation of " << unary_test1 << " is: " << -unary_test1 << '\n';
	*/

	/*
	// INCOMPLETE
	// unary increment tests
	BigInt unary_test1 = 5;
	std::cout << "++" << unary_test1 << " is: ";
	std::cout << ++unary_test1 << '\n';
	BigInt unary_test2 = 1;
	std::cout <<  unary_test2 << "++" << " is: ";
	std::cout << unary_test2++ << " on return from operation, but\n";
	std::cout << "after return from operation previous BigInt is now: " << unary_test2 << '\n';
	*/	
	
	/*
	// COMPLETE
	// arithmetic + test (BigInt + BigInt)
	BigInt add_test1 = -1;
	BigInt add_test2 = -9;
	BigInt add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	add_test1 = -1;
	add_test2 = -99;
	add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	add_test1 = -1;
	add_test2 = -9999;
	add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	add_test1 = -100;
	add_test2 = -100900;
	add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	add_test1 = -100;
	add_test2 = -100500;
	add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	
	// COMPLETE
	// arithmetic + test (BigInt + long long)
	BigInt add_test1 = -1;
	int add_test2 = -9;
	BigInt add_result = add_test1 + add_test2;
	std::cout << add_test1 << " + " << add_test2 << " = " << add_result << '\n';
	*/

	
	// COMPLETE
	// aritmetic * test (BigInt * BigInt and long long params)
	BigInt mul_test1 = 10;
	BigInt mul_test2 = 10;
	BigInt result = mul_test1 * mul_test2;
	std::cout << mul_test1 << " * " << mul_test2 << " is: " << result << '\n';
	mul_test1 = -10;
	mul_test2 = -5;
	result = mul_test1 * mul_test2;
	std::cout << mul_test1 << " * " << mul_test2 << " is: " << result << '\n';
	mul_test1 = 0;
	mul_test2 = -10;
	result = mul_test1 * mul_test2;
	std::cout << mul_test1 << " * " << mul_test2 << " is: " << result << '\n';
	std::cout << mul_test1 << " * 10 is: " << mul_test1 * 10 << '\n';
	std::cout << mul_test1 << " * 9999 is: " << mul_test1 * 9999 << '\n';
	


	/*
	// COMPLETE
	// arithmetic-assignment += test (BigInt and long long params)
	BigInt aa_test1 = 7;
	BigInt aa_test2 = 4;
	int aa_int_test = 5;
	std::cout << aa_test1 << " set equal to " << aa_test1 << " + " << aa_test2 << " is: ";
	aa_test1 += aa_test2;
	std::cout << aa_test1 << '\n';
	std::cout << aa_test1 << " set equal to " << aa_test1 << " + " << aa_int_test << " is: ";
	aa_test1 += aa_int_test;
	std::cout << aa_test1 << '\n';
	*/	

	/*
	// COMPLETE
	// arithmetic-assignment *= test (BigInt and long long params)
	BigInt aa_test1 = 2;
	BigInt aa_test2 = 5;
	int aa_int_test = 10;
	std::cout << aa_test1 << " set equal to " << aa_test1 << " * " << aa_test2 << " is: ";
	aa_test1 *= aa_test2;
	std::cout << aa_test1 << '\n';
	std::cout << aa_test1 << " set equal to " << aa_test1 << " * " << aa_int_test << " is: ";
	aa_test1 *= aa_int_test;
	std::cout << aa_test1 << '\n';
	*/

	return 0;
}


/*
    Utility functions
    -----------------
*/

bool is_valid_number(const std::string& num) {
    for (char digit : num)
        if (digit < '0' || digit > '9')
			if (digit != '+' && digit != '-')
				return false;

    return true;
}

void notify_invalid_input(const std::string& input) {
    std::cout << "Invalid input! Expected an integer, got \'" << input << "\'.\n";
}


/*
    Constructors
    ------------
*/

BigInt::BigInt() {
    value = "0";
    sign = '+';
}

BigInt::BigInt(const BigInt& num) {
    value = num.value;
    sign = num.sign;
}

BigInt::BigInt(const std::string num) {
    if (num[0] == '+' || num[0] == '-') {     // check for sign
        std::string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        }
        else {
            notify_invalid_input(num);
            exit(EXIT_FAILURE);
        }
    }
    else {      // if no sign is specified
        if (is_valid_number(num)) {
            value = num;
            sign = '+';    // positive by default
        }
        else {
            notify_invalid_input(num);
            exit(EXIT_FAILURE);
        }
    }
}

BigInt::BigInt(const long long num) {
    value = std::to_string(num);
    if (num < 0) {
        sign = '-';
        value = value.substr(1);    // remove minus sign from value
    }
    else
        sign = '+';
}


/*
	I/O stream operators
	--------------------
*/

std::istream& operator>>(std::istream& in, BigInt& num) {
	std::string input;
	in >> input;
	num = BigInt(input);  // remove sign from value and set sign, if exists

	return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& num) {
    if (num.sign == '-')
        out << num.sign;
    out << num.value;

    return out;
}


/*
    Assignment operators
    --------------------
*/

void BigInt::operator=(const BigInt& num) {
    value = num.value;
    sign = num.sign;
}

void BigInt::operator=(const long long num) {
    BigInt temp(num);
    value = temp.value;
    sign = temp.sign;
}

void BigInt::operator=(const std::string num) {
    BigInt temp(num);
    value = temp.value;
    sign = temp.sign;
}


/*
	Unary operators
    ---------------
*/

BigInt BigInt::operator-() {
    BigInt temp;

    temp.value = value;
    if (value != "0") {
        if (sign == '+')
            temp.sign = '-';
        else
            temp.sign = '+';
    }

    return temp;
}

BigInt BigInt::operator++() {
	return *this += 1;
}

BigInt BigInt::operator++( int ) {
	BigInt temp = *this;
	++*this;
	return temp;
}


/*
	Arithmetic operators
    ---------------
*/

BigInt BigInt::operator+(const BigInt& rhs) {
	BigInt result;
	std::string lhs_string;
	std::string rhs_string;
	bool carry = false;

	if (value.size() >= rhs.value.size()) {		// assign largest int to lhs and smallest to rhs
		lhs_string = value;
		rhs_string = rhs.value;
	}
	else {
		lhs_string = rhs.value;
		rhs_string = value;
	}
	result.value = lhs_string;	//preload result with largest integer
	

	if (sign == rhs.sign) {	// both integers are positive or both integers are negative
		result.sign = sign;	
		int offset = result.value.size()-1;;	// used to find location of digit to replace
		while (!lhs_string.empty() && !rhs_string.empty()) {	// process addition operation until all digits of smallest integer have been processed
			char added_char = (lhs_string.back() + rhs_string.back()) - 48;
			
			if (carry == 1) {
				added_char += 1; 
				carry = false;
			}
			if (added_char > 57) {
				added_char -= 10;
				carry = true;
			}
			result.value[offset] = added_char;
			--offset;
			lhs_string.pop_back();
			rhs_string.pop_back();
		}


		while (carry) {		// if there is a carry, continue processing addition until all digits of the largest int are completely processed
			if (lhs_string.empty()) {
				result.value.insert(0, "1");
				carry = false;
			}
			else {
				if (lhs_string.back() == '9') {		// check for additional carrying
					result.value[lhs_string.size()-1] = '0';
					//carry = true;
					lhs_string.pop_back();
				}
				else {								// add carried 1 if no additional carrying
					++result.value[lhs_string.size()-1];
					carry = false;
					lhs_string.pop_back();
				}
			}
		}
	}
	//else { perform subtraction operation }

	return result;
}

BigInt BigInt::operator+(long long num) {
	BigInt rhs(num);
	BigInt result = *this + rhs;
	return result;
}

BigInt BigInt::operator*(const BigInt& rhs) {
	BigInt result;
	std::string multiplier;
	std::string initial_value;
	int magnitude = 1;

	if (value.size() >= rhs.value.size()) {		// assign largest int to initial_value and smallest int to magnitude to improve performance
		initial_value = value;
		multiplier = rhs.value;
	}
	else {
		initial_value = rhs.value;
		multiplier = value;
	}

	if (value == "0" || rhs.value == "0")	// zero case
		result = 0;
	else {
		while (!multiplier.empty()) {
			for (int i = (multiplier.back() - 48)*magnitude; i > 0; --i) {
				result += initial_value;
			}
			multiplier.pop_back();
			magnitude *= 10;
		}
	}
	
	if (sign ==  '+' && rhs.sign == '+' || sign == '-' && rhs.sign == '-')	//set sign, keep 0 positive
		result.sign = '+';
	else if (result.value == "0")
		result.sign = '+';
	else 
		result.sign = '-';

	return result;
}

BigInt BigInt::operator*(long long num) {
	BigInt rhs(num);
	BigInt result = *this * rhs;
	return result;
}


/*
    Arithmetic-assignment operators
    -------------------------------
*/

BigInt BigInt::operator+=(const BigInt& rhs) {
	*this = *this + rhs;
	return *this;
}

BigInt BigInt::operator+=(long long num) {
	*this = *this + num;
	return *this;
}

BigInt BigInt::operator*=(const BigInt& rhs) {
	*this = *this * rhs;
	return *this;
}

BigInt BigInt::operator*=(long long num) {
	*this = *this * num;
	return *this;
}


/*
//    Relational operators
    --------------------


bool BigInt::operator>(const BigInt& num) {
    if (sign == num.sign)
        return (value > num.value);
    else
        return (sign == '+');
}

bool BigInt::operator>(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value > temp.value);
    else
        return (sign == '+');
}

bool BigInt::operator>=(const BigInt& num) {
    if (sign == num.sign)
        return (value >= num.value);
    else
        return (sign == '+');
}

bool BigInt::operator>=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value >= temp.value);
    else
        return (sign == '+');
}

bool BigInt::operator<(const BigInt& num) {
    if (sign == num.sign)
        return (value < num.value);
    else
        return (sign == '-');
}

bool BigInt::operator<(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value < temp.value);
    else
        return (sign == '-');
}

bool BigInt::operator<=(const BigInt& num) {
    if (sign == num.sign)
        return (value <= num.value);
    else
        return (sign == '-');
}

bool BigInt::operator<=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value <= temp.value);
    else
        return (sign == '-');
}

bool BigInt::operator==(const BigInt& num) {
    if (sign == num.sign)
        return (value > num.value);

    return false;
}

bool BigInt::operator==(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value == temp.value);

    return false;
}

bool BigInt::operator!=(const BigInt& num) {
    if (sign == num.sign)
        return (value != num.value);

    return true;
}

bool BigInt::operator!=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value != temp.value);

    return true;
}

*/

#ifdef DEBUG
int main() {
    BigInt num;

    num = -51311531;

    if (-num == 51311531)
        std::cout << "Big integer : " << num << "\n";
}

#endif

