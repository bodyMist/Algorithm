#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char first[200];
char second[200];
char third[200];
int LCS[200][200][200];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> first + 1;
	cin >> second + 1;
	cin >> third + 1;
	int firstLength = strlen(first + 1);
	int secondLength = strlen(second + 1);
	int thirdLength = strlen(third + 1);
	int max = 0;
	int lcs = 0;
	for (int i = 1; i <= firstLength; i++) {
		for (int j = 1; j <= secondLength; j++) {
			for (int k = 1; k <= thirdLength; k++) {
				if (first[i] == second[j] && second[j] == third[k]) {
					LCS[i][j][k] = LCS[i - 1][j - 1][k] + 1;
					if (max < LCS[i][j][k]) {
						max = LCS[i][j][k];
					}
				}
				else {
					if (lcs < LCS[i - 1][j][k])	lcs = LCS[i - 1][j][k];
					if (lcs < LCS[i][j - 1][k]) lcs = LCS[i][j - 1][k];
					if (lcs < LCS[i][j][k - 1]) lcs = LCS[i][j][k - 1];
					if (lcs < LCS[i - 1][j - 1][k]) lcs = LCS[i - 1][j - 1][k];

					if (lcs < LCS[i - 1][j - 1][k - 1]) lcs = LCS[i - 1][j - 1][k - 1];
					LCS[i][j][k] = lcs;
				}
			}
		}
	}
	cout << max;
	return 0;
}