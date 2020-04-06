#include <iostream>
using namespace std;

int selectionsort(int *A, int n)
{
	if (n == 1) return 0;

	int max, temp;
	int count = 0;
	for (int i = n - 1; i > 0; i--)
	{
		max = 0;
		temp = 0;
		for (int j = 1; j <= i; j++)
		{
			
			if (A[max] < A[j])
			{
				count = count + 1;
				max = j;
			}
		}
		temp = A[i];
		A[i] = A[max];
		A[max] = temp;
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

	cout << selectionsort(A, num) << endl;


}
