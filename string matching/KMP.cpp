#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int cnt = 0;
int cnt1 = 0;

int KMP(string str1, string str2)
{
	
	int n = str1.length();
	int m = str2.length();

	
	int j = 0;
	int k = -1;
	int *pie = NULL;
	pie = new int[m + 1];
	pie[0] = -1;
	while (j <= m) {
		if (k == -1 || str2[j] == str2[k]) {
			j++;
			k++;
			pie[j] = k;
		}
		else k = pie[k];

	}

	int i = 0;
	j = 0;

	while (i < n) {
		cnt++;
		if (j == -1 || str1[i] == str2[j]) {
			i++;
			j++;
		}
		else j = pie[j];

		if (j == m) {
			cout << cnt<<endl;
			cnt1++;
			j = pie[j];
		}
	}

	if (cnt1 == 0) cout << "fail";

	return 0;
}
 




int main(void)
{
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);



	

	KMP(str1, str2);
}

