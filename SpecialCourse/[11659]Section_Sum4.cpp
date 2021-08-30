#include<iostream>
using namespace std;

int list[200000];
int memoization[200000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, A, B, result;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	memoization[0] = list[0];
	for (int i = 1; i < N; i++) {
		memoization[i] = list[i] + memoization[i - 1];
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		if (A != 1)
			result = memoization[B - 1] - memoization[A - 2];
		else
			result = memoization[B - 1];
		cout << result << "\n";
	}
	return 0;
}