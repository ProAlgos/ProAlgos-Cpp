/*
	Bucket sort
	----------------------
	Distributing the elements of an array into a number of buckets. Bucket sort
	is mainly useful when input is uniformly distributed over a range. Each bucket
	is then sorted individually, either using a different sorting algorithm, or by
	recursively applying the bucket sorting algorithm.

	Time complexity
	---------------
	O(N), where N is the number of elements.

	Space complexity
	----------------
	O(N), where N is the number of elements.
*/

#include <iostream>

using namespace std;

int insertionSort(float a[], const int n) {
	int counter = 0, j;
	for (int i = 0; i < n; i++) {
		float temp = a[i];
		for (j = i; j > 0; j--) {
			if (a[j - 1] > temp) {
				break;
			}
			counter++;
			a[j] = a[j - 1];	//Shift numbers to right
		}
		a[j] = temp;
	}
	return counter;
}

void bucketSort(float a[], const int n) {
	//a started with 1 to n+1
	int max = a[0], maxPer = 0;
	for (int i = 1; i < n + 1; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	while (max != 0) {
		max /= 10;
		maxPer++;
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < maxPer; j++) {
			a[i] /= 10;
		}
	}

	float **b;
	b = new float*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		b[i] = new float[n + 1];
	}
	for (int i = 0; i < n + 1; i++) {
		b[i][0] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		int d = (int)floor(n - n*a[i] + 1), e = b[d][0];
		b[d][e + 1] = a[i];
		b[d][0]++;
	}

	for (int i = 0; i < n; i++) {
		int num = b[i][0];
		float *t;
		t = new float[num];
		for (int j = 1, k = 0; j < num + 1; j++, k++) {
			t[k] = b[i][j];
		}
		insertionSort(t, num);
		for (int j = 1, k = 0; j < num + 1; j++, k++) {
			b[i][j] = t[k];
		}
	}

	//Show the result
	for (int i = 0; i < n + 1; i++) {
		int num = b[i][0];
		for (int j = 1; j < num + 1; j++) {
			cout << b[i][j] << "  ";
		}
	}
	cout << endl;
}

int main() {
	int numberOfInputs;
	float *inputArray;
	cin >> numberOfInputs;
	inputArray = new float[numberOfInputs];
	for (int i = 1; i < numberOfInputs + 3; i++) {
		cin >> inputArray[i];
	}
	bucketSort(inputArray, numberOfInputs);
	return 0;
}