#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> chess;
int N, result;

bool attack(int xj, int yj) {
  int xi, yi;
  for (int t = 0; t < chess.size(); t++) {
    xi = chess[t].first;
    yi = chess[t].second;
    if (xi == xj || yi == yj || xi - xj == yi - yj || xi + yi == xj + yj)
      return true;
  }
  return false;
}
void dp() {
  if (chess.size() == N) {
    result++;
    return;
  }
  int x = chess.size() + 1;
  for (int j = 1; j <= N; j++) {
    if (!attack(x, j)) {
      chess.push_back({x, j});
      dp();
      chess.pop_back();
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> N;
  dp();
  cout << result;
  return 0;
}