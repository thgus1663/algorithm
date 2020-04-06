#include <iostream>
using namespace std;



int insertionsort(int *A, int n)
{
	if (n == 1) return 0;

	int count = 0;
	int temp, loc;
	for (int i = 1; i < n; i++)
	{
		temp = A[i];
		loc = i - 1;
		while (loc >= 0 && A[loc] > temp)
		{
			A[loc + 1] = A[loc];
			loc = loc - 1;
			count = count + 1;
		}
		A[loc + 1] = temp;
		count = count + 1;
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

	cout << insertionsort(A, num) << endl;
}
