#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string to_upper_case(string& inputString) {
	string result = inputString;
	for (int i = 0; i < inputString.length(); ++i) {
		result.at(i) = toupper(inputString.at(i));
	}
	return result;
}

string to_lower_case(string& inputString) {
	string result = inputString;
	for (int i = 0; i < inputString.length(); ++i) {
		result.at(i) = tolower(inputString.at(i));
	}
	return result;
}

double randValue1(double min, double max) {
	double result = ((double)rand() / RAND_MAX) * (max - min) + min;
	return result;
}

int randValue2(int min, int max) {
	int result = rand() % (max - min + 1) + min;
	return result;
}

//Unit Testing in Main
int main ()
{
	string result1;
	string result2;
	double result3;
	int result4;

	string test1 = "Uppercase Test String";
	string test2 = "Lowercase Test String";

	cout << test1 << endl;
	cout << test2 << endl;

	result1 = to_upper_case(test1);
	result2 = to_lower_case(test2);

	cout << result1 << endl;
	cout << result2 << endl;

	double minInput1 = 1;
	double maxInput1 = 100;

	int minInput2 = 1;
	int maxInput2 = 100;

	result3 = randValue1(minInput1, maxInput1);
	result4 = randValue2(minInput2, maxInput2);

	cout << result3 << endl;
	cout << result4 << endl;


	
}


