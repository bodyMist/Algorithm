#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> input(120000);
vector<pair<int, int>> tree(120000);
int par[120000][21];
queue<int> Q;

/*
* �̰� �ٽ� �� �����غ���!
*/
int getCommonParent(int x, int y) {
	//
	if (tree[x].second > tree[y].second)
		swap(x, y);

	for (int i = 20; i >= 0; i--) {
		if (tree[y].second - tree[x].second >= (1 << i))
			y = par[y][i];
	}
	if (x == y)return x;
	for (int i = 20; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, parent, child;
	cin >> N;
	for (int j = 0; j < N - 1; j++) {
		cin >> parent >> child;
		input[parent].push_back(child);
		input[child].push_back(parent);
	}

	// ����� Ʈ���� �ܹ���(�θ� ����Ű����) Ʈ���� �ٲ۴�(BFS �̿�)
	// tree<parent, depth>
	tree[1].second = 1;
	Q.push(1);
	int current, depth;
	while (!Q.empty()) {
		current = Q.front();
		parent = tree[current].first;
		depth = tree[current].second;
		Q.pop();
		for (int j = 0; j < input[current].size(); j++) {
			child = input[current][j];
			if (child == parent) continue;
			tree[child].first = current;
			par[child][0] = current;
			tree[child].second = depth + 1;
			Q.push(child);
		}
	}

	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= N; i++) {
			// parent = i�� ����� 2^(j-1)��° �θ���
			parent = par[i][j - 1];
			// i�� ����� 2^j ��° �θ���� parent�� 2^(j-1)��° �θ���
			par[i][j] = par[parent][j - 1];
		}
	}

	cin >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		cout << getCommonParent(A, B) << "\n";
	}
	return 0;
}