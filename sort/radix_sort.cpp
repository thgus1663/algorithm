#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

void radixsort(int *A, int n, int k)
{
	queue<int> que[10];
	int d;

	int temp;
	int i = 1;
	for(int h=1; h<=k; h++)
	{
		for (int j = 0; j < n; j++)
		{
			d = (A[j]/ i)% 10;
			que[d].push(A[j]);
		}
		int p = 0;
		for (int j = 0; j < 10; j++)
		{
			while (!que[j].empty())
			{
				temp = que[j].front();
				A[p] = temp;
				p = p + 1;
				que[j].pop();
			}			
		}
		

		i = i * 10;
	}
	for (int w = 0; w < n; w++) cout << A[w] << " ";
}

int main(void)
{
	int num, t;
	cin >> num >> t;
	int *A = NULL;
	A = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];

	radixsort(A, num, t);
}
