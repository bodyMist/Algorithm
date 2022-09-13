#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

long long node[501];
int edge[6000][3];
int N, M;

void bellman(){
  node[1] = 0;
  int start, end, weight;
  long long cost;
  for(int i = 1; i <= N; i++){
    for(int j = 0; j < M; j++){
      start = edge[j][0];
      end = edge[j][1];
      weight = edge[j][2];
      if(node[start] == INF)  continue;
      cost = node[start] + weight;
      if(cost < node[end]){
        node[end] = cost;
      }
    }
  }
  for(int i = 0; i < M; i++){
    start = edge[i][0];
    end = edge[i][1];
    weight = edge[i][2];

    if(node[start] == INF)  continue;
    cost = node[start] + weight;
    if(cost < node[end]){
      node[end] = cost;
      cout << -1;
      return;
    }
  }
  for(int i = 2; i <= N; i++){
    if(node[i] == INF){
      cout << -1 << '\n';
      continue;
    }
    cout << node[i] << '\n';
  }
}
int main(){
  cin >> N >> M;
  fill(node, node+N+1, INF);
  int A, B, C;
  for(int i = 0; i < M; i++){
    cin >> A >> B >> C;
    edge[i][0] = A;
    edge[i][1] = B;
    edge[i][2] = C;
  }

  bellman();

  return 0;
}