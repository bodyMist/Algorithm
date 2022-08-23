#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<vector<int>> graph(2000);
void bfs(int start){
  int bfs_visited[2000] = {0};
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

int dfs_visited[2000];
stack<int> s;
void dfs(int current){
  s.push(current);
  dfs_visited[current] = 1;
  cout << current << " ";
  for(int i = 0; i < graph[current].size(); i++){
    int next = graph[current][i];
    if(!dfs_visited[next])
      dfs(next);
  }
}

int main(){
  int N, M, V;
  cin >> N >> M >> V;

  int left, right;
  for(int i = 0; i < M; i++){
    cin >> left >> right;
    graph[left].push_back(right);
    graph[right].push_back(left);
  }

  for(int i = 1; i <= N; i++){
    sort(graph[i].begin(), graph[i].end());
  }
  dfs(V);
  cout << '\n';
  bfs(V);

  return 0;
}