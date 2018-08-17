/*
	Sparse Matrix Multiplication
	--------------
	Sparse matrices, which are common in scientific applications, are matrices
	in which most elements are zero. To save space and running time it is
	critical to only store the nonzero elements. A standard representation of
	sparse matrices in sequential languages is to use an array with one element
	per row each of which contains a linked-list of the nonzero values in that
	row along with their column number.
	This code takes each index-value pair (i,v) in the sparse row, multiplies v
	with the i th value of x, and sums the results, It can write matrices and
	calculate matrix transpose.
	
	Time complexity
	---------------
	O(column + element), where column is matrix column numbers and element is
	number of non-zero elements
	
	Space complexity
	----------------
	O(2N)
*/

#include <iostream>
#include <iomanip>

class sparseMatrix{
private:
public:
	//Sum values is about sum of each array in table
	//SN(Sum Number) is for checking the index in result matrix
	int *col, *row, *value, *SN, colSum, rowSum, valueSum;
	////
	sparseMatrix(int num) {
		col = new int[num];
		row = new int[num];
		value = new int[num];
		SN = new int[num];

		valueSum = num;
		for (int i = 0; i < num; i++) {
			col[i] = 0;
			row[i] = 0;
			value[i] = 0;
			SN[i] = 0;	//It's important
		}
	}

	sparseMatrix mult(sparseMatrix a);
	void write();
protected:
};

sparseMatrix transpose(sparseMatrix a);

void sparseMatrix::write() {
	std::cout << std::setw(5) << std::setfill(' ') << rowSum << " ";
	std::cout << std::setw(5) << std::setfill(' ') << colSum << " ";
	std::cout << std::setw(5) << std::setfill(' ') << valueSum << " \n";
	std::cout << std::setw(20) << std::setfill('-') << "-";
	std::cout << "\n";

	for (int i = 0; i < valueSum; i++) {
		std::cout << std::setw(5) << std::setfill(' ') << row[i] << " ";
		std::cout << std::setw(5) << std::setfill(' ') << col[i] << " ";
		std::cout << std::setw(5) << std::setfill(' ') << value[i] << " \n";
	}
}

sparseMatrix sparseMatrix::mult(sparseMatrix a) {
	sparseMatrix result(0);
	result.rowSum = rowSum;
	result.colSum = a.colSum;
	for (int i = 0; i < valueSum; i++) {

		while (SN[i] != a.colSum) {
			for (int j = 0; j < a.valueSum; j++) {
				if (SN[i] == a.col[j]) {
					//If you find the true indexes in this and a matix:
					bool check = false;
					for (int k = 0; k < result.valueSum; k++) {
						//[ORDER:] result.valueSum*a.valueSum*a.colSum*+valueSum [MEANS:] C.Terms*B.Terms*B.Cols*A.Terms
						if (result.row[k] == row[i] && result.col[k] == a.col[j] && result.col[k] == SN[i] && col[i] == a.row[j]) {
							result.value[k] += value[i] * a.value[j];
							check = true;
							break;
							//std::cout<<i<<" "<<j<<" "<<value[i]<<" "<<a.value[j]<<" "<<k<<"\n";
						}
					}
					if (check == false && col[i] == a.row[j]) {
						result.row[result.valueSum] = row[i];
						result.col[result.valueSum] = SN[i];
						result.value[result.valueSum] = value[i] * a.value[j];
						result.valueSum++;

						//std::cout<<i<<" "<<j<<" "<<value[i]<<" "<<a.value[j]<<" "<<result.valueSum<<"\n";
					}
				}
			}
			SN[i]++;
		}
	}
	return result;
}

sparseMatrix transpose(sparseMatrix a) {
	sparseMatrix b(a.valueSum);
	b.rowSum = a.colSum;
	b.colSum = a.rowSum;
	b.valueSum = a.valueSum;
	if (a.valueSum > 0) {
		int currentB = 0;
		for (int j = 0; j < a.colSum; j++) {
			for (int i = 0; i < a.valueSum; i++) {
				if (a.col[i] == j) {
					b.row[currentB] = j;
					b.col[currentB] = a.row[i];
					b.value[currentB] = a.value[i];
					currentB++;
				}
			}
		}
	}
	return b;
}

int main() {
	int r, c, v;
	std::cin >> r >> c >> v;
	sparseMatrix a(v);
	a.rowSum = r;
	a.colSum = c;
	a.valueSum = v;

	for (int i = 0; i < v; i++) {
		std::cin >> a.row[i] >> a.col[i] >> a.value[i];
	}

	std::cin >> r >> c >> v;
	sparseMatrix b(v);
	b.rowSum = r;
	b.colSum = c;
	b.valueSum = v;

	for (int i = 0; i < v; i++) {
		std::cin >> b.row[i] >> b.col[i] >> b.value[i];
	}
	//a.write();
	//std::cout<<"\n\n";
	//transpose(a).write();

	std::cout << "\nYou are entered\n\n";
	a.write();
	std::cout << "\nAnd\n\n";
	b.write();
	
	a.mult(b).write();
	return 0;
}