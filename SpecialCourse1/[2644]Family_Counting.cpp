#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> family(200);
queue<int> q;
int visit[200] = { 0, };
bool check[200] = { false, };
int bfs(int start, int end) {
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < family[t].size(); i++) {
			int current = family[t][i];
			if (check[current])	continue;
			visit[current] = visit[t] + 1;
			q.push(current);
			check[current] = true;
			if (current == end)
				return visit[current];
		}
	}
	return -1;
}
int main() {
	int N, M, inputA, inputB;
	cin >> N >> inputA >> inputB >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		family[A].push_back(B);
		family[B].push_back(A);
	}
	cout << bfs(inputA, inputB);
	return 0;
}