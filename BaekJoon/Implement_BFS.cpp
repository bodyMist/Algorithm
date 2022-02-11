
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> vertex(8);
queue<int> Q;
void BFS(int v) {
	bool check[8] = { false, };
	Q.push(v);
	check[v] = true;
	cout << v << " ";
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (int i = 0; i < vertex[t].size(); i++) {
			int current = vertex[t][i];
			if (!check[current]) {
				Q.push(current);
				check[current] = true;
				cout << current << " ";
			}
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vertex[A].push_back(B);
		vertex[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		sort(vertex[i].begin(), vertex[i].end());
		BFS(i);
		cout << "\n";
	}
}