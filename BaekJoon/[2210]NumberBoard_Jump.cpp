#include <iostream>
#include <stack>
#include <string>
using namespace std;

int arr[5][5];
int result[1000000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int depth, string num) {
  if (depth > 6) {
    int index = stoi(num);
    result[index]++;
    return;
  }
  num += to_string(arr[x][y]);
  for (int i = 0; i < 4; i++) {
    int xi = x, yi = y;
    xi += dx[i];
    yi += dy[i];
    if (x < 0 || x > 4 || y < 0 || y > 4) continue;
    dfs(xi, yi, depth + 1, num);
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      dfs(i, j, 1, "");
    }
  }

  int count = 0;
  for (int i = 0; i < 1000000; i++) {
    if (result[i] > 0) {
      count++;
    }
  }
  cout << count;
  return 0;
}