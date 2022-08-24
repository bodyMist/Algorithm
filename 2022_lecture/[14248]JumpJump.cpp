#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
vector<int> graph(150000);
int cnt = 1;

void bfs(int start){
  int visited[150000] = {0};
  queue<int> q;
  q.push(start);
  visited[start] = 1;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    int distance = graph[current];
    int right = current + distance;
    int left = current - distance;
    if(right <= N && !visited[right]){
      q.push(right);
      visited[right] = 1;
      cnt++;
    }
    if(left >= 1 && !visited[left]){
      q.push(left);
      visited[left] = 1;
      cnt++;
    }
  }
}

int main(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> graph[i];
  }
  int start;
  cin >> start;
  bfs(start);
  cout << cnt;
  return 0;
}