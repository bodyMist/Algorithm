#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

int graph[1002][1002];
int main(){
  int N, M, X;
  cin >> N >> M >> X;
  int start, end, weight;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(i == j)  {
        graph[i][j] = 0;
        continue;
      }
      graph[i][j] = INF;
    }
  }
  for(int i = 0; i < M; i++){
    cin >> start >> end >> weight;
    graph[start][end] = weight;
  }
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      if(i == k)  continue;
      for(int j = 1; j <= N; j++){
        if(j == k || j == i)  continue;
        int a = graph[i][j];
        int b = graph[i][k] + graph[k][j];
        if(a > b) graph[i][j] = b;
      }
    }
  }
  int max = 0, cost;
  for(int i = 1; i <= N; i++){
    if(graph[i][X] == INF || graph[X][i] == INF)  continue;
    cost = graph[i][X] + graph[X][i];
    if(max < cost) max = cost;
  }
  cout << max;
  return 0;
}