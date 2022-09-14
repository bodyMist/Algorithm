#include<iostream>
#define INF 1e9
using namespace std;

long long node[101][101];
int N, M;
void floyd(){
  for(int k = 1; k <= N; k++){
    for(int i =1; i <= N; i++){
      if(i == k)  continue;
      for(int j = 1; j <= N; j++){
        if(j == i || j == k)  continue;
        long long cost = node[i][k] + node[k][j];
        if(cost < node[i][j]){
          node[i][j] = cost;
        }
      }
    }
  }
}
int main(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(i == j){
        node[i][j] = 0;
        continue;
      }
      node[i][j] = INF;
    }
  }
  int start, end, weight;

  for(int i = 0; i < M; i++){
    cin >> start >> end >> weight;
    if(node[start][end] > weight)
      node[start][end] = weight;
  }

  floyd();

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(node[i][j] == INF) node[i][j] = 0;
      cout << node[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}