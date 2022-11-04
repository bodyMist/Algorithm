#include <iostream>
using namespace std;

long long padovan[150] = {1, 1, 1, 2, 2};
int main() {
  //점화식 : P(N) = N-1 + N-5 (N >= 4)
  int T;
  cin >> T;

  for (int i = 5; i < 150; i++) {
    padovan[i] = padovan[i - 1] + padovan[i - 5];
  }

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    cout << padovan[N - 1] << endl;
  }
  return 0;
}