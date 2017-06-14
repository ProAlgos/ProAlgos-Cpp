/*
    Perfect number:
    prints up to N perfect numbers
    Time complexity:
    O(N), where N is the number being checked 
    Space complexity:
    O(1), constant amount of space needed
*/

#include <iostream>
#include <math.h>

using namespace std;

bool is_perfect(int num) {
	int sum = 1;
	for(int divisor = 2; divisor <= sqrt(num); divisor++)
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
	cout << "The number of perfect numbers you want printed: ";
	cin >> num;
	for(int count = 1; count < num; count++)
	//start from one to prevent false positive with 0
	{
		if(is_perfect(num))
			cout << num << endl;
	}
}
