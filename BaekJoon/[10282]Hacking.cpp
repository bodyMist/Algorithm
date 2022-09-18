#include<iostream>
#include<vector>
#include<queue>
#define INF 2e9
using namespace std;

vector<vector<pair<int,int>>> graph(10001);

void dijkstra(int N, int start){
  int result[10001] = {0};
  priority_queue<pair<int,int>> q;
  for(int i = 1; i <= N; i++){
    result[i] = INF;
  }
  result[start] = 0;
  int nodeCount = 0, costCount = 0;
  q.push({0, start});
  while(!q.empty()){
    int currentCost = -q.top().first;
    int currentNode = q.top().second;
    q.pop();
    if(result[currentNode] < currentCost) continue;

    for(int i = 0; i < graph[currentNode].size(); i++){
      int nextNode = graph[currentNode][i].first;
      int nextCost = graph[currentNode][i].second;
      int cost = currentCost + nextCost;
      if(result[nextNode] > cost){
        result[nextNode] = cost;
        q.push({-cost, nextNode});
      }
    }
  }
  for(int i = 1; i <= N; i++){
    if(result[i] != INF && costCount < result[i])
      costCount = result[i];
    if(result[i] != INF)
      nodeCount++;
    graph[i].clear();
  }
  cout << nodeCount << " " << costCount << '\n';
}
int main(){
  int testcase;
  cin >> testcase;
  for(int t = 0; t < testcase; t++){
    int n, d, c;
    cin >> n >> d >> c;
    int a, b, s;
    for(int i = 0; i < d; i++){
      cin >> a >> b >> s;
      graph[b].push_back({a,s});
    }
    dijkstra(n, c);
  }
}