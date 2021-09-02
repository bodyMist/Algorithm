#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> tree(10010);
int check[10010];
int checkCount;
int getCommonParent(int a, int b) {
	if (a == b) return a;
	checkCount++;
	while (tree[a] != 0 || tree[b] != 0) {
		if (tree[a] != 0) {
			if (check[a] == checkCount)	return a;
			check[a] = checkCount;
			a = tree[a];
		}
		if (tree[b] != 0) {
			if (check[b] == checkCount)	return b;
			check[b] = checkCount;
			b = tree[b];
		}
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, A, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N - 1; j++) {
			cin >> A >> B;
			tree[B] = A;
		}
		cin >> A >> B;
		cout << getCommonParent(A, B) << "\n";
		fill(tree.begin(), tree.end(), 0);
	}
	return 0;
}