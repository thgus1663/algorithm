#include<iostream>
#include<queue>
using namespace std;


int dfs(int **A, int s, int n, bool *visited)
{
	
	visited[s - 1] = true;

	cout << s << " ";

	//int* result = new int[n];
	//result[0] = s;
	//int num = 1;

	//queue<int> q;
	//q.push(s);
	//int u;
	

		for (int i = 0; i < n; i++) {
			if (A[s - 1][i] == 1 && visited[i] == false) {
				dfs(A, i + 1, n, visited);
			}
		}

	

	

	return 0;
}




int main(void)
{
	int n, m;
	cin >> n;
	cin >> m;

	int** mat = new int*[n];
	for (int i = 0; i < n; ++i) mat[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 0;
		}
	}
	
	int num1, num2;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		mat[num1 - 1][num2 - 1] = 1;
		mat[num2 - 1][num1 - 1] = 1;
	}

	int start;
	cin >> start;

	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	dfs(mat, start, n, visited);

}

