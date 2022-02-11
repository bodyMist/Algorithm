#include<iostream>
using namespace std;

int list[1000001];
int findSet(int p) {
	int start = p;
	int temp;
	while (p != list[p])
		p = list[p];
	while (start != p) {
		temp = start;
		start = list[start];
		list[temp] = p;
	}
	return p;
}
void unionSet(int a, int b) {
	int ap = findSet(a);
	int bp = findSet(b);
	list[bp] = ap;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, command, A, B, result;
	int findA, findB;
	for (int i = 0; i <= 1000000; i++) {
		list[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> command >> A >> B;
		if (command == 0)
			unionSet(A, B);
		else if (command == 1) {
			findA = findSet(A);
			findB = findSet(B);
			if (findA == findB)	cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
	return 0;
}