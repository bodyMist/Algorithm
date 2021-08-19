#include<iostream>
#include<algorithm>
using namespace std;

int X;
int memoization[1000001] = {0,};
// 3으로 나누어 떨어진다 : D[N] = D[N/3] + 1
// 2로 나누어 떨어진다 : D[N] = D[N/2] + 1
// 1을 뺀다 : D[N] = D[N-1] + 1


void solve(int N) {
	for (int i = 2; i <= N; i++) {
		// 1을 뺀다
		memoization[i] = memoization[i - 1] + 1;
		// 1을 빼는 경로와 2로 나누는 경로 중 더 값이 작은걸 선택
		if (i % 2 == 0)
			memoization[i] = min(memoization[i], memoization[i / 2] + 1);
		// 1을 빼는 경로와 3으로 나누는 경로 중 더 값이 작은걸 선택
		if(i%3 == 0)
			memoization[i] = min(memoization[i], memoization[i / 3] + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> X;
	int count = 0;
	solve(X);
	cout << memoization[X];
	return 0;
}