#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> graph(1001);
int visited[1001];

int sum = 0;

void bfs(int node){
  queue<int> q;
  q.push(node);
  visited[node] = 1;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i];
      if(!visited[next]){
        sum++;
        q.push(next);
        visited[next] = 1;
      }
    }
  }
}
int main(){
  int N, M;
  cin >> N >> M;
  int u, v;
  for(int i = 0; i < M; i++){
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  bfs(1);
  cout << sum;
  return 0;
}