#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, char token) {
  vector<string> result;
  int prior = 0, current = 0;
  current = input.find(token);

  while (current != string::npos) {
    string sub = input.substr(prior, current - prior);
    prior = current + 1;
    current = input.find(token, prior);
    result.push_back(sub);
  }
  result.push_back(input.substr(prior, current - prior));
  return result;
}

int main() {
  string input;
  getline(cin, input);
  vector<string> splitResult = split(input, '-');
  vector<int> token;
  for (string t : splitResult) {
    vector<string> plus = split(t, '+');
    int plusSum = 0;
    for (string k : plus) {
      plusSum += stoi(k);
    }
    token.push_back(plusSum);
  }
  int result = token[0];
  for (int i = 1; i < token.size(); i++) {
    result -= token[i];
  }
  cout << result;
  return 0;
}