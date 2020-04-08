#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int cnt = 0;
int summ = 0;

int NaiveMatching(string str1, string str2)
{
	int n = str1.length();
	int m = str2.length();
	bool same = true;
	for (int i = 0; i < n - m + 1; i++) {
		same = true;
		for (int j = 0; j < m; j++) {
			cnt = cnt + 1;
			if (str1[i + j] != str2[j]) {
				same = false;
				break;
			}	
			
		}
	
		if (same) {
			
			summ++;
		}
		
	}
	cout << cnt << " " << summ;

	return 0;
}
 




int main(void)
{
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);

	NaiveMatching(str1, str2);
}

