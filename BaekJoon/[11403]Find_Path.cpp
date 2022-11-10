#include <iostream>
#include <vector>
using namespace std;

int graph[101][101];

int N;
void floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      if (k == i) continue;
      for (int j = 1; j <= N; j++) {
        if (k == j) continue;
        int current = graph[i][j];
        int firstStep = graph[i][k];
        int secondStep = graph[k][j];
        if (firstStep == 0 || secondStep == 0) continue;
        if (current == 0 || current > firstStep + secondStep)
          graph[i][j] = firstStep + secondStep;
      }
    }
  }
}

int main() {
  int input;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> input;
      if (input == 1) {
        graph[i][j] = 1;
      }
    }
  }
  floyd();
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[i][j] >= 1) {
        cout << 1 << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}