#include<iostream>
#include<queue>
using namespace std;


int bfs(int **A, int s, int n)
{
	bool* visited = new bool[n];	
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[s - 1] = true;

	int* result = new int[n];
	result[0] = s;
	int num = 1;

	queue<int> q;
	q.push(s);
	int u;
	while (q.empty() != true) {
		u = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (A[u - 1][i] == 1 && visited[i] == false) {
				visited[i] = true;
				result[num] = i + 1;
				num = num + 1;
				q.push(i + 1);
			}
		}

	}

	for (int i = 0; i < n; i++) cout << result[i] << " ";

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

	bfs(mat, start, n);

}

