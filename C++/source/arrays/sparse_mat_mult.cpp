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
	O(column + element), where column is matrxi column numbers and element is
	number of non-zero elements
	Space complexity
	----------------
	O(2N)
*/
#include <iostream>
#include <iomanip>
using namespace std;
class sparse_matrix {
private:
public:
	//Sum values is about sum of each array in table
	//SN(Sum Number) is for checking the index in result matrix
	int *col, *row, *value, *source, col_sum, row_sum, value_sum;
	sparse_matrix(int num) {
		col = new int[num];
		row = new int[num];
		value = new int[num];
		source = new int[num];
		value_sum = num;
		for (int i = 0; i < num; i++) {
			col[i] = 0;
			row[i] = 0;
			value[i] = 0;
			source[i] = 0;	//It's important
		}
	}
	sparse_matrix mult(sparse_matrix a);
	void write();
protected:
};
sparse_matrix transpose(sparse_matrix a);
void sparse_matrix::write() {
	cout << setw(5) << setfill(' ') << row_sum << " ";
	cout << setw(5) << setfill(' ') << col_sum << " ";
	cout << setw(5) << setfill(' ') << value_sum << " \n";
	cout << setw(20) << setfill('-') << "-";
	cout << "\n";
	for (int i = 0; i < value_sum; i++) {
		cout << setw(5) << setfill(' ') << row[i] << " ";
		cout << setw(5) << setfill(' ') << col[i] << " ";
		cout << setw(5) << setfill(' ') << value[i] << " \n";
	}
}
sparse_matrix sparse_matrix::mult(sparse_matrix a) {
	sparse_matrix result(0);
	result.row_sum = row_sum;
	result.col_sum = a.col_sum;
	for (int i = 0; i < value_sum; i++) {
		while (source[i] != a.col_sum) {
			for (int j = 0; j < a.value_sum; j++) {
				if (source[i] == a.col[j]) {
					//If you find the true indexes in this and a matix:
					bool check = false;
					for (int k = 0; k < result.value_sum; k++) {
						//[ORDER:] result.value_sum*a.value_sum*a.col_sum*+value_sum [MEANS:] C.terms*B.terms*B.cols*A.terms
						if (result.row[k] == row[i] && result.col[k] == a.col[j] && result.col[k] == source[i] && col[i] == a.row[j]) {
							result.value[k] += value[i] * a.value[j];
							check = true;
							break;
							//cout<<i<<" "<<j<<" "<<value[i]<<" "<<a.value[j]<<" "<<k<<"\n";
						}
					}
					if (check == false && col[i] == a.row[j]) {
						result.row[result.value_sum] = row[i];
						result.col[result.value_sum] = source[i];
						result.value[result.value_sum] = value[i] * a.value[j];
						result.value_sum++;
						//cout<<i<<" "<<j<<" "<<value[i]<<" "<<a.value[j]<<" "<<result.valueSum<<"\n";
					}
				}
			}
			source[i]++;
		}
	}
	return result;
}
sparse_matrix transpose(sparse_matrix input_mat) {
	sparse_matrix output_mat(input_mat.value_sum);
	output_mat.row_sum = input_mat.col_sum;
	output_mat.col_sum = input_mat.row_sum;
	output_mat.value_sum = input_mat.value_sum;
	if (input_mat.value_sum > 0) {
		int current_mat = 0;
		for (int j = 0; j < input_mat.col_sum; j++) {
			for (int i = 0; i < input_mat.value_sum; i++) {
				if (input_mat.col[i] == j) {
					output_mat.row[current_mat] = j;
					output_mat.col[current_mat] = input_mat.row[i];
					output_mat.value[current_mat] = input_mat.value[i];
					current_mat++;
				}
			}
		}
	}
	return output_mat;
}
int main() {
	int rows, cols, values;
	cin >> rows >> cols >> values;
	sparse_matrix first_mat(values);
	first_mat.row_sum = rows;
	first_mat.col_sum = cols;
	first_mat.value_sum = values;
	for (int i = 0; i < values; i++) {
		cin >> first_mat.row[i] >> first_mat.col[i] >> first_mat.value[i];
	}
	cin >> rows >> cols >> values;
	sparse_matrix second_mat(values);
	second_mat.row_sum = rows;
	second_mat.col_sum = cols;
	second_mat.value_sum = values;
	for (int i = 0; i < values; i++) {
		cin >> second_mat.row[i] >> second_mat.col[i] >> second_mat.value[i];
	}
	//a.write();
	//cout<<"\n\n";
	//transpose(a).write();
	cout << "\nYou are entered\n\n";
	first_mat.write();
	cout << "\nAnd\n\n";
	second_mat.write();

	first_mat.mult(second_mat).write();
	return 0;
}