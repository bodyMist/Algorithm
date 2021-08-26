#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int> q;
vector<vector<int>> list(2000);

bool check[2000] = { false , };

int bfs(int start) {
	q.push(start);
	int target, result = 0;
	if (check[start]) return result;

	while (!q.empty()) {
		target = q.front();
		q.pop();
		for (int i = 0; i < list[target].size(); i++) {
			int  current = list[target][i];
			if (check[current]) continue;
			q.push(current);
			check[current] = true;
		}
		result = 1;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, inputA, inputB, result = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> inputA >> inputB;
		list[inputA].push_back(inputB);
		list[inputB].push_back(inputA);
	}
	for (int i = 1; i <= N; i++) {
		if (bfs(i) == 1) result++;
	}
	cout << result;
	return 0;
}