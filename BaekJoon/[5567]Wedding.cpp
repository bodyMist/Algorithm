#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> list(550);
queue<int> q;
int depth[550] = { 0, };
bool check[550] = { false, };
int bfs(int start) {
	int result = 0;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		for (int i = 0; i < list[target].size(); i++) {
			int current = list[target][i];
			if (check[current]) continue;
			depth[current] = depth[target] + 1;
			if (depth[current] > 2)	continue;
			q.push(current);
			check[current] = true;
			result++;
		}
	}
	return result;
}
int main() {
	int N, M, inputA, inputB, result = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> inputA >> inputB;
		list[inputA].push_back(inputB);
		list[inputB].push_back(inputA);
	}
	cout << bfs(1);
	return 0;
}