#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int lcs(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();
	
	int** c = new int*[m+1];
	for (int i = 0; i <= m; ++i) c[i] = new int[n+1];

	for (int i = 0; i <= m; i++) c[i][0] = 0;
	for (int j = 0; j <= n; j++) c[0][j] = 0;


	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
			else {
				if (c[i - 1][j] > c[i][j - 1]) c[i][j] = c[i - 1][j];
				else c[i][j] = c[i][j - 1];
			}
		}
	}

	return c[m][n];
}




int main(void)
{
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);

	cout<<lcs(str1, str2);
}

