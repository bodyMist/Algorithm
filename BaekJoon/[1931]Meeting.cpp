#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> meeting(100000);
int result = 1;

bool cmp(vector<int> &a, vector<int> &b) {
  if (a[1] == b[1])
    return a[0] < b[0];
  else
    return a[1] < b[1];
}
void greedy(int N) {
  int start = meeting[0][1];

  for (int i = 1; i < N; i++) {
    int current_start = meeting[i][0];
    int current_end = meeting[i][1];

    if (start <= current_start) {
      result++;
      start = current_end;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int start, end, gap;

  for (int i = 0; i < N; i++) {
    cin >> start >> end;
    gap = end - start;
    meeting[i].push_back(start);
    meeting[i].push_back(end);
  }
  sort(meeting.begin(), meeting.begin() + N, cmp);

  greedy(N);

  cout << result;

  return 0;
}