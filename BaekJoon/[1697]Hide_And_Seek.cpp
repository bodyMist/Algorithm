#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> list(100001);
queue<int> q;

bool check[1000001] = { false, };
int number[100001] = {};

void bfs(int start, int end) {
	q.push(start);
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		for (int i = 0; i < list[target].size(); i++) {
			int current = list[target][i];
			if (check[current]) continue;
			q.push(current);
			
		}
	}
}
int getMax(int i, int j) { return i < j ? j : i; }
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < 100001; i++) {
		if (i != 0)
			list[i].push_back(i - 1);
		if (i != 100000)
			list[i].push_back(i + 1);
		if (i <= 500000)
			list[i].push_back(2 * i);
	}
	bfs(N, K);


	return 0;
}