#include <iostream>
using namespace std;

void countingsort(int *A, int *B, int n)
{
	int min = A[0];
	int max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] < min) min = A[i];
		if (A[i] > max) max = A[i];
	}
	int k = max - min + 1;
	int *C = NULL;
	C = new int[k];
	for (int i = 0; i < k; i++) C[i] = 0;
	for (int i = 0; i < n; i++) C[A[i] - min]++;
	for (int i = 1; i < k; i++) C[i] = C[i] + C[i - 1];
	for (int j = 0; j < k; j++) cout << C[j] << " ";
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[A[i] - min]] = A[i];
		C[A[i] - min]--;
	}
}



int main(void)
{
	int num;
	cin >> num;
	int *A = NULL;
	A = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];
	int *B = NULL;
	B = new int[num];

	countingsort(A, B, num);
	
}
