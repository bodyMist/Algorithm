#include<iostream>
#include<queue>
using namespace std;

int field[51][51];
queue<pair<int, int>> s;
int bfs(int x, int y, int M, int N){
  if(!field[x][y])
    return 0;

  field[x][y] = 0;
  s.push({x,y});
  int dX[] = {1, -1, 0, 0};
  int dY[] = {0, 0, 1, -1};

  while(!s.empty()){
    auto next = s.front();
    s.pop();
    int a = next.first;
    int b = next.second;

    for(int i = 0; i < 4; i++){
      int nX = a + dX[i];
      int nY = b + dY[i];
      if(nX < 0 || nY < 0 || nX > M || nY > N)
        continue;
      if(field[nX][nY]){
        s.push({nX,nY});
        field[nX][nY] = 0;
      }
    }
  }
  return 1;
}

int result;

int main(){
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    int M, N, K, result = 0;
    cin >> M >> N >> K;
    int x, y;
    for(int j = 0; j < K; j++){
      cin >> x >> y;
      field[x][y] = 1;
    }

    for(int a = 0; a < M; a++){
      for(int b = 0; b < N; b++){
        result += bfs(a,b,M,N);
      }
    }
    cout << result <<endl;
  }
  return 0;
}