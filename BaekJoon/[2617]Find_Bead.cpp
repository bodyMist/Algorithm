#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;
int result[100];
int weight[100][100];
int N, M;

void floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      if (i == k) continue;
      for (int j = 1; j <= N; j++) {
        if (i == j || j == k) continue;
        int current = weight[i][j];
        int firstStep = weight[i][k];
        int secondStep = weight[k][j];
        if (firstStep == 0 || secondStep == 0) continue;
        if (current < firstStep + secondStep)
          weight[i][j] = firstStep + secondStep;
      }
    }
  }
}

int main() {
  cin >> N >> M;

  int light, heavy;
  for (int i = 0; i < M; i++) {
    cin >> heavy >> light;
    weight[light][heavy] = 1;
  }
  floyd();
  for (int i = 1; i <= N; i++) {
    int forwardCount = 0, backwardCount = 0;
    for (int j = 1; j <= N; j++) {
      if (weight[i][j] > N / 2) {
        result[i] = 1;
        result[j] = 1;
      }
      if (weight[i][j] > 0) forwardCount++;
      if (weight[j][i] > 0) backwardCount++;
    }
    if (forwardCount > N / 2) result[i] = 1;
    if (backwardCount > N / 2) result[i] = 1;
  }
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (result[i] > 0) count++;
  }
  cout << count;

  return 0;
}