#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> tree(100001);
int parents[100001] = { 0, };
bool check[100001] = { false, };
queue<int> q;
void bfs(int start) {
	q.push(start);
	int target, upper = 1;
	while (!q.empty()) {
		target = q.front();
		upper = target;
		q.pop();
		for (int i = 0; i < tree[target].size(); i++) {
			int  current = tree[target][i];
			if (check[current]) continue;
			q.push(current);
			check[current] = true;
			parents[current] = upper;
		}
	}
}

int main() {
	int N, inputA, inputB;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> inputA >> inputB;
		tree[inputA].push_back(inputB);
		tree[inputB].push_back(inputA);
	}
	bfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parents[i] << "\n";
	}
}