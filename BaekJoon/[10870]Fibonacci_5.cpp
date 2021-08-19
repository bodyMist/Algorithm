#include<iostream>
using namespace std;

int memoization[21] = { 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		memoization[i] = memoization[i - 2] + memoization[i - 1];
	}
	cout << memoization[N];
	return 0;
}