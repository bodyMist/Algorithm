#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N;
int graph[51][51];
void floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      if (i == k) continue;
      for (int j = 1; j <= N; j++) {
        if (j == i || j == k) continue;

        int current = graph[i][j];
        int a = graph[i][k];
        int b = graph[k][j];
        if (current > a + b) {
          graph[i][j] = a + b;
        }
      }
    }
  }
}

int main() {
  cin >> N;
  int left, right;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      graph[i][j] = INF;
      if (i == j) graph[i][j] = 0;
    }
  }
  while (true) {
    cin >> left >> right;
    if (left == -1 && right == -1) break;
    graph[left][right] = 1;
    graph[right][left] = 1;
  }

  floyd();

  for (int i = 1; i <= N; i++) {
    int max = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      if (max < graph[i][j]) {
        max = graph[i][j];
        graph[i][0] = max;
      }
    }
  }
  int count = 0, criteria = N + 1;
  vector<int> result;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[j][0] == i) {
        count++;
        result.push_back(j);
      }
    }
    if (!result.empty()) {
      criteria = i;
      break;
    }
  }
  cout << criteria << " " << count << "\n";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}