#include<iostream>
#include<vector>
#define INF 2147000000
using namespace std;
vector<pair<int, int>> graph[600]; // 노드, 비용 pair

int result[600]; // 최단 거리 테이블

bool solve(int N) {
	bool change = false;
	int currentIndex;
	
	// 노드의 갯수인 N번 만큼 돌기
	for (int i = 0; i < N; i++) {
		// 각 노드가 가지고 있는 간선 돌아주기
		for (currentIndex = 1; currentIndex <= N; currentIndex++) {
			for (int j = 0; j < graph[currentIndex].size(); j++) {

				int currentCost = result[currentIndex]; // 현재 노드 값
				int targetNode = graph[currentIndex][j].first; // 다음 노드
				int targetCost = currentCost + graph[currentIndex][j].second; // 다음 노드까지의 비용			

				// 현재 노드가 한번이라도 계산된적 있는 값이라면
				// 현재 노드와 연결된 노드들의 비용을 최신화
				if (result[targetNode] > targetCost) {
					result[targetNode] = targetCost;
				}
			}
		}
	}
	for (currentIndex = 1; currentIndex <= N; currentIndex++) {
		for (int j = 0; j < graph[currentIndex].size(); j++) {

			int currentCost = result[currentIndex]; // 현재 노드 값
			int targetNode = graph[currentIndex][j].first; // 다음 노드
			int targetCost = currentCost + graph[currentIndex][j].second; // 다음 노드까지의 비용

			// 교체가 일어나면 음수가중치 사이클이 존재
			if (result[targetNode] > targetCost) {
				change = true;
				return change;
			}
		}
	}
	return change;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int TC, N, W, M, S, E, T;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M >> W;

		// 노드값들 전부 INF로 채우기
		fill(result, result + 600, INF);

		// 도로는 무방향 = 양방향
		for (int j = 0; j < M; j++) {
			cin >> S >> E >> T;
			graph[S].push_back({ E,T });
			graph[E].push_back({ S,T });
		}
		//웜홀은 방향이 있으며 -T로 값을 입력
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T;
			graph[S].push_back({ E, -T });
		}

		if (solve(N))	cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}