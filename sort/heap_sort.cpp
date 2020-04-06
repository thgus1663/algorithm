#include <iostream>
using namespace std;

int cnt = 0;

void heapify(int *A, int k, int n)
{
	int left = 2*k +1;
	int right = 2*k +2; 
	int bigger =A[k];

	if (right < n)
	{
		if (A[right] >= A[left]) bigger = right; 
		else bigger = left; 
	}
	else if (left < n) bigger = left;  
	else return;

	int tmp = 0;
	if (A[bigger] > A[k]) 
	{
		cnt = cnt + 1;
		tmp = A[bigger];
		A[bigger] = A[k];
		A[k] = tmp;
		heapify(A, bigger, n);
	}
}


void buildheap(int *A, int n)
{
	for (int i = ((n-1)/2); i >= 0; i--) heapify(A, i, n);
}

void heapsort(int *A, int n)
{
	buildheap(A, n);

	int temp;

	cnt = 0;
	int i = n - 1;
	while (i > 0)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, 0, i);
		i = i - 1;
	}
}

int main(void)
{
	int num;
	cin >> num;
	int *A = NULL;
	A = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];

	heapsort(A, num);
	cout << cnt;
}


