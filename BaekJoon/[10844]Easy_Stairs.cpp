#include<iostream>
using namespace std;

// N==1, 1 2 3 4 5 6 7 8 9
// N==2, 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98
// N==3, 101 121 123 210 212 232 234 ...789 ... 898 987 989  
long long memo[200][10] = {0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		memo[1][i] = 1;
	}
	for (int i = 2; i <= N; i++){
		for (int j = 0; j <= 9; j++) {
			if (j == 0) memo[i][j] = memo[i-1][1];
			else if (j == 9) memo[i][j] = memo[i-1][8];
			else memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j + 1];
			memo[i][j] %= 1000000000;
		}
	}
	long long result = 0;
	for (int i = 0; i <= 9; i++) {
		result += memo[N][i];
		result %= 1000000000;
	}
	cout << result;
	return 0;
}