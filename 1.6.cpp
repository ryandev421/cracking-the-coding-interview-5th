#include <iostream>
#include <vector>
using namespace std;

void rotateOutline(vector<vector<int> > &matrix, int sy, int sx, int size)
{
	for (int i = 0; i < size-1; i++) {
		int temp = matrix[sy][sx + i];
		matrix[sy][sx + i] = matrix[sy+i][sx+size-1];
		matrix[sy+i][sx+size-1] = matrix[sy + size -1][sx + size - 1 - i];
		matrix[sy + size - 1][sx + size - 1 - i] = matrix[sy + size -1 - i][sx];
		matrix[sy + size - 1 - i][sx] = temp;
	}
}

void rotateMatrix(vector<vector<int> > &matrix, int n)
{
	for (int i = 0; i < n/2; i++) {
		rotateOutline(matrix, i, i, n - i*2);
	}
}

int main()
{
	int n = 11;
	vector<vector<int> > matrix;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			row.push_back(i*n + j + 1);
		}
		matrix.push_back(row);
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	rotateMatrix(matrix, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}