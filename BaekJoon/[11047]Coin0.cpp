#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
int N, K, result;

void greedy() {
  for (int i = N - 1; i >= 0; i--) {
    int x = K / list[i];
    K -= list[i] * x;
    result += x;
  }
}

int main() {
  cin >> N >> K;
  int input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    list.push_back(input);
  }
  greedy();
  cout << result;
  return 0;
}