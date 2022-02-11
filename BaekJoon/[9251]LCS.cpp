#include<iostream>
#include<cstring>
using namespace std;

char first[1010];
char second[1010];
int LCS[2000][2000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> first + 1;
	cin >> second + 1;
	int firstLength = strlen(first + 1);
	int secondLength = strlen(second + 1);
	int max = 0;
	for (int i = 1; i <= firstLength; i++) {
		for (int j = 1; j <= secondLength; j++) {
			if (first[i] == second[j]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				if (max < LCS[i][j])	max = LCS[i][j];
			}
			else
				LCS[i][j] = LCS[i][j - 1] > LCS[i - 1][j] ? LCS[i][j - 1] : LCS[i - 1][j];
		}
	}
	cout << max;
}