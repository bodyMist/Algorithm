#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int maze[105][105];
char line[105];
queue<pair<int,int>> q;

void bfs(int N, int M){
  q.push({0,0});
  int depth = 1;
  int queueSize = q.size();
  maze[0][0] = 0;

  while(!q.empty()){
    for(int i = 0; i < queueSize; i++){
      pair<int,int> currentNode = q.front();
      q.pop();
      int currentX = currentNode.first;
      int currentY = currentNode.second;
      if(currentX != 0 && maze[currentX-1][currentY] == 1){
        q.push({currentX-1,currentY});
        maze[currentX-1][currentY] = 0;
      }
      if(currentY != 0 && maze[currentX][currentY-1] == 1){
        q.push({currentX,currentY-1});
        maze[currentX][currentY-1] = 0;
      }
      if(maze[currentX+1][currentY] == 1){
        q.push({currentX+1,currentY});
        maze[currentX+1][currentY] = 0;
      }
      if(maze[currentX][currentY+1] == 1){
        q.push({currentX,currentY+1});
        maze[currentX][currentY+1] = 0;
      }
      if(currentX == N-1 && currentY == M-1){
        cout << depth;
        return;
      }
    }
  queueSize = q.size();
  depth++;
  }
}


int main(){
  int N, M;
  string input;
  cin >> N >> M;
  cin.ignore();
  for(int i = 0; i < N; i++){
    getline(cin, input);
    strcpy(line, input.c_str());
    for(int j = 0; j < M; j++){
      maze[i][j] = line[j] - '0';
    }
  }
  bfs(N,M);
  return 0;
}