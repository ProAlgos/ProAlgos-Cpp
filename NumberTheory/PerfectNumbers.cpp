/*
    Perfect number:
    Checks if a given number is perfect. Could be used to generate a 
    sequence of perfect numbers
    Time complexity:
    O(N), where N is the number being checked 
    Space complexity:
    O(1), constant amount of space needed
*/

#include <iostream>

using namespace std;

ULL is_perfect(int num) {
	int sum = 1;
	for(int divisor = 2; divisor <= num/2; divisor++)
	{
		if(num % divisor == 0)
			sum += divisor;
	}
	if(divisor == sum)
		return 1;
	return 0;
}

int main() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	if(is_perfect(num))
		cout << num << " is perfect" << endl;
	else 
		cout << num << " is not perfect" << endl;
}