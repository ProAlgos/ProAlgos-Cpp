/*
 <Shunting Yard Algorithm>
-------------------
<Converting an infix arithmetic string to a post-fix one, A.K.A. Reverse Polish Notation.
This implementation does not implement functions and solely focuses on simple arithmetic of consisting of [-,+,*,/,^]>

Time complexity
---------------
<O(N*M*P) where N is the size of input vector, i.e. equations, M is the size of the greatest string in the vector, and P is maximum number of operators in the string>

Space complexity
----------------
<O(N+P) = O(N) : where N is the size of input vector, i.e. equations, and  P is maximum number of operators in the string, i.e. stack operations. >
*/

#include "reverse_polish.hpp"
using namespace std;

unordered_map<char, int> OperatorOperations::operator_precedence{ { '-', 2 }, { '+', 2 }, { '*', 3 }, { '/', 3 }, { '^', 4 } };
unordered_map<char, string> OperatorOperations::operator_association{ { '-', "left" }, { '+', "left" }, { '*', "left" }, { '/', "left" }, { '^', "right" } };

std::vector<std::string> OperatorOperations::to_reverse_polish(const std::vector<std::string>& equations)
{

    string equation;
    string temporary_string;
    vector<string> postfixed_equations;
    postfixed_equations.reserve(equations.size());
    stack<char> operators;
    OperatorOperations operations;

    for (int i = 0; i <= (int)equations.size() - 1; i++) {
        equation = equations[i];
        temporary_string = "";
        for (int j = 0; j <= (int)equation.length() - 1; j++) {
            if (isalnum(equation[j])) {
                temporary_string.push_back(equation[j]);
            }
            else if (isblank(equation[j])) {
            }
            else if (equation[j] != '(' && equation[j] != ')' && operator_precedence.find(equation[j]) == operator_precedence.end()) {
                temporary_string.push_back(equation[j]);
            }

            else {
                if (equation[j] == '(') {
                    operators.push(equation[j]);
                }
                else {
                    if (equation[j] == ')') {

                        while (operators.top() != '(') {

                            temporary_string.push_back(operators.top());
                            operators.pop();
                        }
                        operators.pop();
                    }
                    else {
                        if (operators.empty()) {
                            operators.push(equation[j]);
                        }
                        else {
                            while (!operators.empty() && (operators.top() != '(') && (operations.operator_precedence[operators.top()] > operations.operator_precedence[equation[j]] || (operations.operator_precedence[operators.top()] == operations.operator_precedence[equation[j]] && operations.operator_association[operators.top()] == "left"))) {
                                temporary_string.push_back(operators.top());
                                operators.pop();
                            }
                            operators.push(equation[j]);
                        }
                    }
                }
            }
        }

        while (!operators.empty()) {
            temporary_string.push_back(operators.top());
            operators.pop();
        }

        postfixed_equations.push_back(temporary_string);

        for_each(postfixed_equations.begin(), postfixed_equations.end(), [](string character) -> void { cout << character << endl; });
        cout << endl;
    }
    return (postfixed_equations);
}
