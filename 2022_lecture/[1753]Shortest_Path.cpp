#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

vector<vector<pair<int, int>>> graph(20005);
priority_queue<pair<int, int>> pq;
int result[20005];

void dijkstra(int start){
  result[start] = 0;
  pq.push({0, start});
  while(!pq.empty()){
    int currentNode = pq.top().second;
    int currentWeight = -pq.top().first;
    pq.pop();
    if(result[currentNode] < currentWeight) continue;

    for(int i = 0; i < graph[currentNode].size(); i++){
      int nextNode = graph[currentNode][i].first;
      int nextWeight = graph[currentNode][i].second;
      
      int cost = currentWeight + nextWeight;
      if(result[nextNode] > cost){
        result[nextNode] = cost;
        pq.push(make_pair(-cost, nextNode));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);

  fill(result, result+20005, INF);
  int V, E, K;
  cin >> V >> E >> K;

  int u, v, w;
  for(int i = 0; i < E; i++){
    cin >> u >> v >> w;
    graph[u].push_back({v,w});
  }
  dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)
			cout << "INF" << "\n";
		else
			cout << result[i] << "\n";
	}
  return 0;
}