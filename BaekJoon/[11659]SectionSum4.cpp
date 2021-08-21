#include<iostream>
using namespace std;

int list[100000];
int sum[100000];

int solve(int i, int j) {
	int result = 0;
	if (i == 1)	result = sum[j - 1];
	else result = sum[j-1] - sum[i-2];
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, j, input = 0;
	cin >> N >> M;
	for (int t = 0; t < N; t++) {
		cin >> list[t];
		input += list[t];
		sum[t] = input;
	}
	for (int t = 0; t < M; t++) {
		cin >> i >> j;
		cout << solve(i, j) << "\n";
	}
	return 0;
}