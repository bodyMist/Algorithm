#include<iostream>
using namespace std;

int memoization[1000000] = { 0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		memoization[i] = memoization[i - 1] + 1;

		if (i % 3 == 0) {
			memoization[i] = memoization[i] > memoization[i / 3] + 1 ? memoization[i / 3] + 1 : memoization[i];
		}
		if (i % 2 == 0) {
			memoization[i] = memoization[i] > memoization[i / 2] + 1 ? memoization[i / 2] + 1 : memoization[i];
		}
	}
	cout << memoization[N];
	return 0;
}