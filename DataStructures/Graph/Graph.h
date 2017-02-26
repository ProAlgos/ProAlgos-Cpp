#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <cctype>

bool again(const std::string& action) {
    std::cout << "Do you want to " << action << " again? (y/n): ";
    char response;
    std::cin >> response;
    std::cin.ignore(100, '\n');
    response = toupper(response);

    return 'Y' == response;
}

#endif
