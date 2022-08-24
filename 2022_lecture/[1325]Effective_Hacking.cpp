#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> graph(15000);
vector<int> list;

int bfs(int start){
  queue<int> q;
  int visited[15000] = {0};
  q.push(start);
  visited[start] = 1;
  int cnt = 1;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i];
      if(!visited[next]){
        q.push(next);
        visited[next] = 1;
        cnt++;
      }
    }
  }
  return cnt;
}
int main(){
  int N, M;
  cin >> N >> M;
  int a, b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    graph[b].push_back(a);
  }
  int max = 0;
  for(int i = 1; i <= N; i++){
    int cnt = bfs(i);
    if(max < cnt){
      list.clear();
      list.push_back(i);
      max = cnt;
    }else if(max == cnt){
      list.push_back(i);
      max = cnt;
    }
  }
  for(int i = 0; i < list.size(); i++){
    cout << list[i] << " ";
  }
  return 0;
}