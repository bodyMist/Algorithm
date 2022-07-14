#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<vector<int>> graph(100, vector<int> (100, 1000000));
stack<int> s;


int main(){
  int N, M;
  cin >> N >> M;
  int from, to;
  for(int i = 0; i < M; i++){
    cin >> from >> to;
    graph[from][to] = 1;
  }

  return 0;
}