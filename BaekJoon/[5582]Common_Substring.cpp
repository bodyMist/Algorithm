#include<iostream>
#include<cstring>
using namespace std;

char first[5000];
char second[5000];
int LCS[5000][5000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> first + 1;
	cin >> second + 1;
	int firstLength = strlen(first+1);
	int secondLength = strlen(second+1);
	int max = 0;
	for (int i = 1; i <= firstLength; i++) {
		for (int j = 1; j <= secondLength; j++) {
			if (first[i] == second[j]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				if (max < LCS[i][j])
					max = LCS[i][j];
			}
			else
				LCS[i][j] = 0;

			//cout << LCS[i][j];
		}
		//cout << endl;
	}
	cout << max;
	return 0;
}