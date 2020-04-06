#include <iostream>
using namespace std;

int bubblesort(int *A, int n)
{
	if (n == 1) return 0;

	int count = 0;
	int temp;
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			temp = 0;
			if (A[j] > A[j + 1])
			{
				count = count + 1;
				temp = A[j+1];
				A[j + 1] = A[j];
				A[j] = temp;
			}
		}
	}
	return count;
}

int main(void)
{
	int num;
	cin >> num;
	int *A = NULL;
	A = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];
	   
	cout << bubblesort(A, num) << endl;
}
