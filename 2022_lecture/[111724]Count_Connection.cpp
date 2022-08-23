#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph(1001);
int visited[1001];

int bfs(int node){
  if(visited[node])
    return 0;
  queue<int> q;
  q.push(node);
  visited[node] = 1;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i];
      if(!visited[next]){
        q.push(next);
        visited[next] = 1;
      }
    }
  }
  return 1;
}
int main(){
  int N, M, result = 0;
  cin >> N >> M;
  int u, v;
  for(int i = 0; i < M; i++){
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i = 1; i <= N; i++){
    result += bfs(i);
  }
  cout << result;
  return 0;
}