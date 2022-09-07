#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int result[100000];
vector<vector<int>> graph(140);

void dijkstra(int N){
  priority_queue<pair<int,int>> pq;
  int startWeight = graph[0][0];
  result[0] = startWeight;
  pq.push({-startWeight, 0});
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  while(!pq.empty()){
    int currentNode = pq.top().second;
    int currentWeight = -pq.top().first;
    pq.pop();

    if(result[currentNode] < currentWeight) continue;

    int currentX = currentNode / N;
    int currentY = currentNode % N;
    
    graph[currentX][currentY] = 0;
    for(int i = 0; i < 4; i ++){
      int nextX = currentX + dx[i];
      int nextY = currentY + dy[i];
      if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)  continue;
      if(nextX == 0 && nextY == 0)  continue;
      int nextNode = nextX * N + nextY;
      int cost = currentWeight + graph[nextX][nextY];
      if(result[nextNode] > cost){
        result[nextNode] = cost;
        pq.push({-cost, nextNode});
      }
    }
  }
}
int main(){
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  int cnt = 1;
  while(true){
    int N, input;
    cin >> N;
    if(N == 0) return 0;

    for(int i  = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cin >> input;
        graph[i].push_back(input);
      }
    }
    fill(result, result+(N*N), INF);
    dijkstra(N);
    cout << "Problem " << cnt++ << ": " << result[N*N -1] << '\n';
    
    for(int i = 0; i < N; i++){
      graph[i].clear();
    }
  }
  return 0;
}