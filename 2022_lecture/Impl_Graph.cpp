#include <iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

vector<vector<int>> graph(100);

void bfs(int start){
  int bfs_visited[100] = {0};
	queue<int> q;
	q.push(start);
	bfs_visited[start] = 1;
	while(!q.empty()){
		int current = q.front();
		cout << current << " ";
		q.pop();
		for(int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i];
			if(!bfs_visited[next]){
				q.push(next);
				bfs_visited[next] = 1;
			}
		}
	}
}

int dfs_visited[100];
void dfs(int current){
  stack<int> s;
  s.push(current);
  dfs_visited[current] = 1;
  cout << current << " ";
  for(int i = 0; i < graph[current].size(); i++){
    if(!dfs_visited[current])
      dfs(graph[current][i]);
  }
}
int main() {
	int N, M;
	cin >> N >> M;
	int left, right;
	for(int i = 0; i < M; i++){
		cin >> left >> right;
		graph[left].push_back(right);
		graph[right].push_back(left);
	}
	for(int i = 1; i <= N; i++){
		bfs(i);
		cout << endl;
	}
  dfs(1);
	return 0;
}