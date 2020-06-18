#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	const int n = 3;
	const int m = 4;
	double matrix[n][m] = { {-2,1,-3,-8},
						   {3,1,-6,-9},
						   {1,1,2,5} };
	cout << "Введенная матрица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < m - 2; i++) {
		double a;
		a = matrix[i][i];
		for (int j = i + 1; j < n; j++) {
			matrix[j][i] /= a;
			cout << matrix[j][i] << endl;
		}
		for (int j = i + 1; j < n; j++) {
			for (int t = i + 1; t < m; t++) {
				matrix[j][t] += matrix[i][t] * matrix[j][i];
			}
			matrix[j][i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = n-1; i >=0; i--) {
		double a;
		a = matrix[i][i];
		cout << a << endl;
	}
	double arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	cout << endl;
	arr[n - 1] = matrix[n - 1][m - 1] / matrix[n - 1][m - 2];
	for (int i = n - 2; i >= 0; i--) {
		arr[i] = matrix[i][m - 1];
		for (int j = m - 2; j > i; j--) {
			arr[i] = arr[i] - matrix[i][j] * arr[j];
		}
		arr[i] /= matrix[i][i];
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << endl;
	}
	return 0;
}