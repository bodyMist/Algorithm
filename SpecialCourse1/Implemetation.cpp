#include<iostream>
using namespace std;
int list[5] = { 5,12,13,15,20 };
int visit[5];

void subSet(int depth, int N, int cnt) {
	if (depth == N) {
		if (cnt == 3) {
			for (int i = 0; i < N; i++) {
				if (visit[i] == 1)
					cout << list[i] << " ";
			}
		}
		cout << "\n";
		return;
	}
	visit[depth] = 0;
	subSet(depth + 1, N, cnt);
	visit[depth] = 1;
	subSet(depth + 1, N, cnt+1);
}
int main() {
	subSet(0, 5, 0);
	return 0;
}