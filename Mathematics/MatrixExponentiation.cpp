#include <bits/stdc++.h>
using namespace std;

const int SIZE = 101;
int exponent;

vector<vector<int>> input(SIZE, vector<int>(SIZE, 0));
vector<vector<int>> result(SIZE, vector<int>(SIZE, 0));
vector<vector<int>> identity(SIZE, vector<int>(SIZE, 0));

void InputMatrix(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << "Enter the element a(" << i << " " << j << "): ";
			cin >> input[i][j];
		}
	}
}

void PrintMatrix(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

// Matrix multiplication: C = A * B
vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B, int n) {
	vector<vector<int>> C(SIZE, vector<int>(SIZE, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

// Recursive matrix exponentiation
vector<vector<int>> MatrixPower(int n, int k) {
	if (k == 0) return identity;

	vector<vector<int>> res = MatrixPower(n, k / 2);
	if (k % 2 == 0)
		return mul(res, res, n);
	else
		return mul(mul(res, res, n), input, n);
}

int main() {
	int n;
	cout << "Enter matrix dimension (n x n): ";
	cin >> n;
	cout << "Enter matrix exponent: ";
	cin >> exponent;

	// Initialize identity matrix
	for (int i = 1; i <= n; ++i)
		identity[i][i] = 1;

	InputMatrix(n);
	result = MatrixPower(n, exponent);

	cout << "Matrix raised to power " << exponent << ":\n";
	PrintMatrix(n);

	return 0;
}
