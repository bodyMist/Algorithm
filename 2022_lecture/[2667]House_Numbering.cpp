#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

char str[30][30];
int N;

int bfs(int x, int y){
  queue<pair<int, int>> q;
  str[x][y] = '0';
  q.push({x,y});

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int cnt = 1;

  while(!q.empty()){
    auto current = q.front();
    q.pop();
    int a = current.first;
    int b = current.second;

    for(int i = 0; i < 4; i++){
      int nX = a + dx[i];
      int nY = b + dy[i];
      if(nX < 0 || nY < 0 || nX > N || nY > N){
        continue;
      }
      if(str[nX][nY] == '1'){
        q.push({nX, nY});
        str[nX][nY] = '0';
        cnt++;
      }
    }
  }
  return cnt;
}
int main(){
  int sum = 0;
  vector<int> result;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> str[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(str[i][j] == '1')
        result.push_back(bfs(i,j));
    }
  }
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << '\n';
  }

  return 0;
}