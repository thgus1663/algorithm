#include <iostream>
using namespace std;

int cnt = 0;

int merge(int *A, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	int count = 0;
	int size = r - p + 1;
	int *tmp = NULL;
	tmp = new int[size];
	while (i <= q && j <= r)
	{
		count = count + 1;
		if (A[i] < A[j]) tmp[t++] = A[i++];
		else tmp[t++] = A[j++];		
	}

	while(i<=q) tmp[t++] = A[i++];
	while(j<=r) tmp[t++] = A[j++];

	i = p; t = 0;
	while (i <= r) A[i++] = tmp[t++];

	return count;
}

int mergesort(int *A, int p, int r)
{	
	if (p < r)
	{
		int q = (p + r) / 2;
		mergesort(A, p, q);
		mergesort(A, q + 1, r);
		cnt=cnt+merge(A, p, q, r);
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

	mergesort(A, 0, num-1);
	cout << cnt;	
}
