#include<iostream>

using namespace std;

int solve(int N, int M) {
	int result = 1;
	for (int i = 1; i <= N; i++) {
		result = result * (M + 1 - i) / i;
	}
	return result;
}
int getMinimum(int N, int M) {
	return (N < M - N ? N : M - N);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T,N,M,result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		N = getMinimum(N, M);
		cout << solve(N, M) << "\n";
	}

	return 0;
}