#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int minCount = 50000;
void bfs(vector<vector<int>> graph){
  queue<int> q;
  for(int i = 1; i <= N; i++){
    vector<int> visit(1500);
    q.push(i);
    visit[i] = 1;
    int count = 0;
    while(!q.empty()){
      int here = q.front();
      q.pop();
      for(int j = 0; j < graph[here].size(); j++){
        int next = graph[here][j];
        if(!visit[next]){
          q.push(next);
          visit[next] = 1;
          count++;
        }
      }
    }
    if(count < minCount)
      minCount = count;
  }
  cout << minCount <<endl;
}

int main(){
  int testcase;
  cin >> testcase;
  for(int t = 0; t < testcase; t++){
    cin >> N >> M;
    vector<vector<int>> graph(1500);
    for(int i = 0; i < M; i++){
      int a,b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    bfs(graph);
    minCount = 50000;
  }
  return 0;
}