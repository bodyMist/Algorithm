#include<iostream>
using namespace std;

int ans[10];
void perm(int depth, int N, int R) {
	if (depth == R) {
		for (int i = 0; i < R; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		ans[depth] = i;
		perm(depth + 1, N, R);
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	perm(0, N, M);

	return 0;
}