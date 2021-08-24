#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> computers(15000);
queue<int> Q;
int result[15000];
int temp[15000];
int BFS(int v) {
	int result = 0;
	bool check[15000] = { false, };
	Q.push(v);
	check[v] = true;
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (int i = 0; i < computers[t].size(); i++) {
			int current = computers[t][i];
			if (!check[current]) {
				Q.push(current);
				check[current] = true;
				result++;
			}
		}
	}
	return result;
}
bool compare(int i, int j) {
	return i > j ? true : false;
}
int main() {
	int N, M;
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		computers[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		sort(computers[i].begin(), computers[i].end());
		temp[i] = BFS(i);
		result[i] = temp[i];
	}
	sort(temp, temp + N + 1, compare);
	int max = temp[0];
	for (int i = 1; i <= N; i++) {
		if (result[i] != max)
			continue;
		cout << i << " ";
	}
	return 0;
}
