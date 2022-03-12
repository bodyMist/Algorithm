// 팔방면으로 이동가능(Land가 있다면)
// 

#include<iostream>
#include<cstring>
using namespace std;
int island[51][51];

void recursive(int x, int y, int h, int w){
  if (x < 0 || x > h || y < 0 || y > w) return;
  
  island[x][y] = 0;
  if(island[x][y + 1] == 1){
    recursive(x,y+1,h,w);
  }
  if(island[x][y-1] == 1){
    recursive(x,y-1,h,w);
  }
  if(island[x+1][y] == 1){
    recursive(x+1,y,h,w);
  }
  if(island[x-1][y] == 1){
    recursive(x-1,y,h,w);
  }
  if(island[x-1][y-1] == 1){
    recursive(x-1,y-1,h,w);
  }
  if(island[x-1][y+1] == 1){
    recursive(x-1,y+1,h,w);
  }
  if(island[x+1][y-1] == 1){
    recursive(x+1,y-1,h,w);
  }
  if(island[x+1][y+1] == 1){
    recursive(x+1,y+1,h,w);
  }
}

int main(){
  int w, h, result = 0;
  while(true){
  //fill(island, island+51, -1);
    memset(island, -1, sizeof(island));
    cin >> w >> h;
    if(w == 0 && h == 0) return 0;

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> island[i][j];
      }
    }
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(island[i][j] == 1){
          result++;
          recursive(i,j,h,w);
        }
      }
    }
    cout << result << endl;
    result = 0;
  }
}