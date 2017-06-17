/*
     Perfect number:
     Checks if a given number is perfect. Could be used to generate a 
     sequence of perfect numbers
     Time complexity:
     O(sqrt(N)), where N is the number being checked 
     Space complexity:
     O(1), constant amount of space needed
 */
 
 #include <iostream>
 #include <math.h>
 using namespace std;
 
typedef unsigned long long int ULL;

 bool is_perfect(ULL num) {
 	ULL sum = 1;
 	ULL divisor;
 	for(divisor = 2; divisor <= sqrt(num); divisor++)
 	{
 		if(num % divisor == 0)
 			sum += divisor + num / divisor;
 	}
 	if(num == sum)
 		return true;
 	return false;
 }
 
 int main() {
 	ULL num;
 	cout << "Enter a positive integer less than 2^64 : ";
 	cin >> num;
 	if(is_perfect(num))
 		cout << num << " is perfect" << endl;
 	else 
 		cout << num << " is not perfect" << endl;
 }
