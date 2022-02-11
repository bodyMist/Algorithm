#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check[105] = { false, };
vector<vector<int>> computers(105);
queue<int> q;
void bfs(int start) {
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		for (int i = 0; i < computers[target].size(); i++) {
			int current = computers[target][i];
			if (check[current]) continue;
			q.push(current);
			check[current] = true;
		}
	}
}

int main() {
	int N, M, inputA, inputB, result = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> inputA >> inputB;
		computers[inputA].push_back(inputB);
		computers[inputB].push_back(inputA);
	}
	bfs(1);
	for (int i = 2; i <= N; i++) {
		if (check[i]) result++;
	}
	cout << result;
}