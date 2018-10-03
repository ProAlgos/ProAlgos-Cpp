#ifndef REVERSE_POLISH_HPP_
#define REVERSE_POLISH_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>

class OperatorOperations {
	public:
		std::vector <std::string> to_reverse_polish (const std::vector <std::string> &);
		static std::unordered_map<char, int> operator_precedence;
	    static std::unordered_map<char, std::string> operator_association;
};

#endif /* REVERSE_POLISH_HPP_ */
