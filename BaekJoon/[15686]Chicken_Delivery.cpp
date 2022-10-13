#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> client;
vector<pair<int, int>> chicken;
vector<int> selection;
bool visited[50];
int minSum = 1e9;

void distance() {
  for (int i = 0; i < client.size(); i++) {
    for (int j = 0; j < chicken.size(); j++) {
      int x = chicken[j].first - client[i][0];
      int y = chicken[j].second - client[i][1];
      int sum = (x > 0 ? x : -x) + (y > 0 ? y : -y);
      client[i].push_back(sum);
    }
  }
}
void bruteforce(int count, int M, int t) {
  if (count == M) {
    int sum = 0;
    for (int i = 0; i < client.size(); i++) {
      int current = 0, currentMin = 1e9;
      for (int j = 0; j < selection.size(); j++) {
        int index = selection[j];
        current = client[i][index + 2];
        if (current < currentMin) currentMin = current;
      }
      sum += currentMin;
    }
    if (minSum > sum) minSum = sum;
    return;
  }
  for (int i = t; i < chicken.size(); i++) {
    if (!visited[i]) {
      visited[i] = true;
      selection.push_back(i);
      bruteforce(count + 1, M, i + 1);
      selection.pop_back();
      visited[i] = false;
    }
  }
}

void solve(int M) {
  distance();
  bruteforce(0, M, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, input;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> input;
      if (input == 1) {
        client.push_back({i, j});
      } else if (input == 2) {
        chicken.push_back({i, j});
      }
    }
  }
  solve(M);
  cout << minSum;
  return 0;
}