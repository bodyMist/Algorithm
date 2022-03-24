#include<iostream>
#include<cstring>
using namespace std;

int area[101][101];
int visit[101][101];

void recursive(int x, int y, int rain){
  if((x < 0 || x > 100) || (y < 0 || y > 100))  return;
  if(visit[x][y] == 1) return;

  visit[x][y] = 1;
  if(area[x-1][y] > rain && visit[x-1][y] == 0){
    recursive(x-1, y, rain);
  }
  if(area[x+1][y] > rain && visit[x+1][y] == 0){
    recursive(x+1, y, rain);
  }
  if(area[x][y-1] > rain && visit[x][y-1] == 0){
    recursive(x, y-1, rain);
  }
  if(area[x][y+1] > rain && visit[x][y+1] == 0){
    recursive(x, y+1, rain);
  }
}
int search(int N, int rain){
  int cnt = 0;
  // 아무 지역도 안 잠길수도 있다
  for(int p = 0; p < N; p++){
    for(int q = 0; q < N; q++){
      if(area[p][q] > rain && visit[p][q] == 0){
        recursive(p,q, rain);
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int N, input, highest = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> input;
      area[i][j] = input;
      highest = highest > input ? highest : input;
    }
  }
  int result = 0, temp = 0;
  for(int i = 0; i < highest; i++){
    temp = search(N,i);
    memset(visit, 0, sizeof(visit));
    result = result < temp ? temp : result;
  }
  cout << result;
  return 0;
}