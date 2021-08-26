#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;
vector<pair<int,int>> graph[25000]; // 노드, 비용 pair
priority_queue<pair<int,int>> waiting; // 비용, 노드 pair

int result[25000]; // 최단 거리 테이블

void solve(int start) {
	result[start] = 0;
	waiting.push({ 0, start });
	
	while (!waiting.empty()) {
		int currentNode = waiting.top().second; // 현재 노드까지의 노드
		int currentCost = -waiting.top().first; // 현재 비용
		waiting.pop();

		// 이미 최단경로를 체크한 노드인 경우 패스
		if (result[currentNode] < currentCost)	continue; 

		// 현재 노드와 연결된 경로들 검사하기
		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i].first;

			// 현재 노드까지의 비용 + 해당 경로의 비용을 합한 것이
			int cost = currentCost + graph[currentNode][i].second;
			// 최단경로 테이블의 비용보다 작다면 최신화 & 큐에 넣기
			if (result[nextNode] > cost) {
				result[nextNode] = cost;
				waiting.push(make_pair(-cost, nextNode));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(result, result + 25000, INF);
	int V, E, start, u, v, w;
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	solve(start);
	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)
			cout << "INF" << "\n";
		else
			cout << result[i] << "\n";
	}

	return 0;
}