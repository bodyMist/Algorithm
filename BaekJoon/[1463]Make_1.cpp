#include<iostream>
#include<algorithm>
using namespace std;

int X;
int memoization[1000001] = {0,};
// 3���� ������ �������� : D[N] = D[N/3] + 1
// 2�� ������ �������� : D[N] = D[N/2] + 1
// 1�� ���� : D[N] = D[N-1] + 1


void solve(int N) {
	for (int i = 2; i <= N; i++) {
		// 1�� ����
		memoization[i] = memoization[i - 1] + 1;
		// 1�� ���� ��ο� 2�� ������ ��� �� �� ���� ������ ����
		if (i % 2 == 0)
			memoization[i] = min(memoization[i], memoization[i / 2] + 1);
		// 1�� ���� ��ο� 3���� ������ ��� �� �� ���� ������ ����
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