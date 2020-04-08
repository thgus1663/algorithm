#include<iostream>
#include<queue>
using namespace std;

typedef struct ERecord
{
	int E;
	int P1;
	int P2;

}enode;

int getParent(int *A, int x) {
	if (A[x-1] == x) return A[x - 1];
	

	return A[x - 1] = getParent(A, A[x - 1]);;
}

int* kruskal(int* A, ERecord** ee, int n, int m)
{
	int max;
	
	for (int i = m-1; i>0; i--) {
		max = 0;
		ERecord* temp = new ERecord;
		for (int j = 1; j <= i; j++)
		{
			if (ee[max]->E < ee[j]->E) max = j;
		}
		temp = ee[i];
		ee[i] = ee[max];
		ee[max] = temp;
	}
	
	ERecord** eee = new ERecord*[n - 1];
	for (int i = 0; i < n - 1; i++) {
		eee[i] = new ERecord;
	}
	int min = 0;
	int i = 0;
	while (min<m) {
		A[(ee[min]->P1) - 1] = getParent(A, ee[min]->P1);
		A[(ee[min]->P2) - 1] = getParent(A, ee[min]->P2);
		if (A[(ee[min]->P1) - 1] == A[(ee[min]->P2) - 1]) {
			min = min + 1;
		}
		else {			
			if (A[(ee[min]->P1) - 1] < A[(ee[min]->P2) - 1]) {
				
				A[(ee[min]->P2) - 1] = A[(ee[min]->P1) - 1];
			}
			else {
				
				A[(ee[min]->P1) - 1] = A[(ee[min]->P2) - 1];
				
			}
			eee[i] = ee[min];
			i++;
			min++;
			
		}
	}

	int sum = 0;
	int *AA = NULL;
	AA = new int[n];
	for (int j = 0; j <	n-1; j++) {
		sum = sum + eee[j]->E;
		AA[j]= eee[j]->E;
	}
	AA[n - 1] = sum;
	
	return AA;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	int *A = NULL;
	A = new int[n];

	for (int i = 0; i < n; i++) A[i] = i+1;

	
	
	ERecord** ee = new ERecord*[m];
	
	int num1, num2, num3;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2 >> num3;
		ee[i] = new ERecord;
		
		ee[i]->P1 = num1;
		ee[i]->P2 = num2;
		ee[i]->E = num3;
	}	

	int *AA=kruskal(A, ee, n, m);

	for (int i = 0; i < n; i++) cout << AA[i] << " ";
}

