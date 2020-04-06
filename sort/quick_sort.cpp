#include <iostream>
using namespace std;

int cnt = 0;

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int temp;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			cnt = cnt + 1;
		}
	}

	i++;
	A[r] = A[i];
	A[i] = x;
	cnt = cnt + 1;
	return i;
}

int quicksort(int *A, int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
	return 0;
}



int main(void)
{
	int num;
	cin >> num;
	int *A = NULL;
	A = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];

	quicksort(A, 0, num-1);
	cout << cnt;	
}
