#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> graph(105);
int weight[105];
int visited[105];

int n, targetX, targetY, m, result;

void bfs(int start){
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    result++;
    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i];
      if(!visited[next]){
        q.push(next);
        visited[next] = 1;
        weight[next] = weight[current] + 1;
      }
    }
  }
}
int main(){
  cin >> n >> targetX >> targetY >> m;
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs(targetX);
  cout << (weight[targetY] != 0 ? weight[targetY] : -1);
  return 0;
}