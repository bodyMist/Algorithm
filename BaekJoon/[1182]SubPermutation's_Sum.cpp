#include<iostream>
#include<algorithm>
using namespace std;

int list[25];
int visit[25];
int ans[25];
int result = 0;
void perm(int depth, int N, int R, int S, int current) {
	if (depth == R) {
		int sum = 0;
		for (int i = 0; i < R; i++) {
			sum += ans[i];
		}
		if (sum == S)	result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (current <= i) {
			if (visit[i] == 0) {
				visit[i] = 1;
				ans[depth] = list[i];
				perm(depth + 1, N, R, S, i);
				visit[i] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for(int i = 1;i<=N;i++)
		perm(0, N, i, S, 0);

	cout << result;
	return 0;
}