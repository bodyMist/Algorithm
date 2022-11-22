#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> visited;
int paper[500][500];
int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int result, sum;

void dp(int x, int y, int depth) {
  if (depth > 4) return;
  if (x < 0 || x >= N || y < 0 || y >= M) return;
  for (int i = 0; i < visited.size(); i++) {
    auto current = visited[i];
    if (x == current.first && y == current.second) return;
  }
  sum += paper[x][y];
  visited.push_back({x, y});
  if (depth == 4 && sum > result) result = sum;

  // T자 모양 예외 동작
  if (depth == 3) {
    if (visited[0].first == visited[2].first ||
        visited[0].second == visited[2].second) {
      auto second = visited[1];
      int x_temp = second.first;
      int y_temp = second.second;
      for (int i = 0; i < 4; i++) {
        x_temp += dx[i];
        y_temp += dy[i];
        dp(x_temp, y_temp, depth + 1);
        x_temp -= dx[i];
        y_temp -= dy[i];
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    x += dx[i];
    y += dy[i];

    dp(x, y, depth + 1);

    x -= dx[i];
    y -= dy[i];
  }
  sum -= paper[x][y];
  visited.pop_back();
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp(i, j, 1);
      sum = 0;
    }
  }
  cout << result;

  return 0;
}