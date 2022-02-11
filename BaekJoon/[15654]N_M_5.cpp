#include<iostream>
#include<algorithm>
using namespace std;

int list[10];
int visit[10];
int ans[10];
void perm(int depth, int N, int R) {
	if (depth == R) {
		for (int i = 0; i < R; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			ans[depth] = list[i];
			perm(depth + 1, N, R);
			visit[i] = 0;
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
	perm(0, N, M);
	return 0;
}