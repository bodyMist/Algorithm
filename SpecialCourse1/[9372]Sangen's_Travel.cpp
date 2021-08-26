#include<iostream>
using namespace std;

int list[20000];

int findSet(int p) {
	int start = p;
	int temp = start;
	while (p != list[p]) {
		p = list[p];
	}
	while (temp != list[temp]) {
		temp = list[start];
		list[start] = p;
		start = temp;
	}
	return p;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 20000; i++) {
		list[i] = i;
	}
	int T, N, M, A, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			list[A] = B;
		}
	}

	return 0;
}