#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> list(100001);
queue<int> q;

int bfs(int start, int end) {
	q.push(start);
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		for (int i = 0; i < list[target].size(); i++) {
			int current = list[target][i];
			if(current == end)
		}
	}
}
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < 100001; i++) {
		list[i].push_back(i - 1);
		list[i].push_back(i + 1);
		list[i].push_back(2 * i);
	}
	

	return 0;
}