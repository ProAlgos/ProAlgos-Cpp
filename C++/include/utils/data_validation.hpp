/*
    Various utility functions used for data validation
*/
#include <string>
#include <random>
#include <ctime>
#define UP_A 65
#define UP_Z 91

#define LOW_A 97
#define LOW_Z 122

std::string to_upper_case(std::string &s){
    std::string upper;
    for(int i = 0; i<s.length();i++){
        if( s.at(i) >= LOW_A && s.at(i) <= LOW_Z){
            upper+=(s.at(i) - 32);
        }else{
            upper += s.at(i);
        }
    }
    return upper;
}

std::string to_lower_case(std::string &s){
    std::string lower;
    for(int i = 0; i<s.length();i++){
        if( s.at(i) >= UP_A && s.at(i) <= UP_Z){
            lower+=(s.at(i) + 32);
        }else{
            lower += s.at(i);
        }
    }
    return lower;
}

double get_random_double(double min, double max){
    std::mt19937 generator;
    generator.seed(std::time(0));    
    std::uniform_real_distribution<double> random_double(min,max);
    double random_double_value = random_double(generator);
    return random_double_value;
}

int get_random_int(int min, int max){
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> random_int(min,max);
    int random_integer = random_int(generator);
    return random_integer;
}