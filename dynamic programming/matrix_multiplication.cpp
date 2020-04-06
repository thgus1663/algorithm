#include<iostream>

using namespace std;


int matrixChain(int n, int *A)
{
	int** m = new int*[n];
	for (int i = 0; i < n; ++i) m[i] = new int[n];

	for (int i = 0; i < n; i++) m[i][i] = 0;

	int j, min, tmp;
	for (int r = 1; r < n; r++) {
		for (int i = 0; i < n - r; i++) {
			j = i + r;
			min = m[i][i] + m[i + 1][j] + (A[i] * A[i + 1] * A[j + 1]);
			for (int k = i + 1; k < j; k++) {
				tmp = m[i][k] + m[k + 1][j] + (A[i] * A[k + 1] * A[j + 1]);
				if (tmp < min) min = tmp;
			}
			m[i][j] = min;
		}
	}

	return m[0][n - 1];
}




int main(void)
{
	int n;
	cin >> n;

	int* A = new int[n+1];
	int i, j;
	for (int a = 0; a < n; a++)
	{
		cin >> i >> j;
		A[a] = i;
		A[a + 1] = j;
	}

	cout<<matrixChain(n, A);
}