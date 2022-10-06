#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int answer[10];
int visited[10];
vector<int> arr;

int N, d;
bool flag = false;
int convert(int* value, int d) {
  int result = 0, p;
  for (int i = d - 1; i >= 0; i--) {
    p = pow(d, d - i - 1);
    result += value[i] * p;
  }
  return result;
}
void recursive(int index, int n, int d) {
  if (index == d) {
    int current = convert(answer, d);
    if (current > N && !flag) {
      cout << current;
      flag = true;
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    answer[index] = arr[i];
    if (answer[0] == 0) continue;
    visited[i] = 1;
    recursive(index + 1, n, d);
    visited[i] = 0;
  }
}

int main() {
  cin >> N >> d;

  for (int i = 0; i < d; i++) {
    arr.push_back(i);
  }
  recursive(0, d, d);
  if (!flag) cout << -1;
  return 0;
}