#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> input;

int binarySearch(int target, vector<int>& list, int start, int end) {
  int index = (start + end) / 2;

  if (target > list[index]) {
    return binarySearch(target, list, index + 1, end);
  } else if (target < list[index]) {
    return binarySearch(target, list, start, index);
  } else {
    return index;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int coordinate;
  for (int i = 0; i < N; i++) {
    cin >> coordinate;
    input.push_back(coordinate);
  }
  vector<int> temp(input.begin(), input.end());
  vector<int> list;
  sort(temp.begin(), temp.end());

  for (int i = 0; i < N; i++) {
    if (i > 0 && temp[i] == temp[i - 1]) {
      continue;
    }
    list.push_back(temp[i]);
  }

  for (int i = 0; i < N; i++) {
    int target = input[i];
    cout << binarySearch(target, list, 0, list.size()) << ' ';
  }

  return 0;
}