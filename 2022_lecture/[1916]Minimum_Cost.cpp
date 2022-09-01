#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<vector<pair<int,int>>> graph(1001);
priority_queue<pair<int,int>> pq;

int result[1001];
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
      int cost = currentWeight + graph[currentNode][i].second;
      
      if(result[nextNode] > cost){
        result[nextNode] = cost;
        pq.push({-cost, nextNode});
      }
    }
  }
}

int main(){
  int N, M, start, end;
  cin >> N >> M;

  int u, v, w;
  for(int i = 0; i < M; i++){
    cin >> u >> v >> w;
    graph[u].push_back({v,w});
  }
  fill(result, result + N + 1, INF);
  cin >> start >> end;
  dijkstra(start);
  cout << result[end];
  return 0;
}