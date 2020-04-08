#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int cnt = 0;
int cnt1 = 0;

int BoyerMoore(string str1, string str2)
{
	
	int n = str1.length();
	int m = str2.length();

	
	
	
	int *jump = NULL;
	jump = new int[m];
	for (int i = 0; i < m - 1; i++) {
		jump[i] = m-i-1;
	}
	jump[m - 1] = m;

	int i = 0;
	int j;
	int k;
	while (i < n - m + 1) {
		j = m - 1;
		k = i + m - 1;
		while (j >= 0 && str1[k] == str2[j]) {
			cnt++;
			j--;
			k--;
		}
		if (j == -1) cnt1++;

		int jj = 0;
		for (int h = m - 1; h >= 0; h--) {
			if (str2[h] == str1[i + m - 1]) {
				jj = jump[h];
				break;
			}
		}
		if (jj == 0) jj = m;

		i = i + jj;
	}

	cout << cnt << " " << cnt1;


	return 0;
}
 




int main(void)
{
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);



	BoyerMoore(str1, str2);
}

