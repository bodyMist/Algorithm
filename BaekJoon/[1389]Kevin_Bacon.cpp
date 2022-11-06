#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int dis[101][101];
int sum[101];

int N, M;

void floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      if (i == k) continue;
      for (int j = 1; j <= N; j++) {
        if (j == k || j == i) continue;
        int current = dis[i][j];
        int a = dis[i][k];
        int b = dis[k][j];
        if (a == INF || b == INF) continue;
        if (current > a + b) {
          dis[i][j] = a + b;
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  int from, to;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dis[i][j] = INF;
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> from >> to;
    dis[from][to] = 1;
    dis[to][from] = 1;
  }

  floyd();

  int min = 1e9, result = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (dis[i][j] == INF) continue;
      sum[i] += dis[i][j];
    }
    if (min > sum[i]) {
      min = sum[i];
      result = i;
    }
  }
  cout << result;
  return 0;
}