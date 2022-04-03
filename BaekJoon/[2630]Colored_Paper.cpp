#include<iostream>
using namespace std;

int paper[130][130];
int visit[130][130];
int white, blue;

void blueSearch(int x, int y, int N){
  if(N < 1) return;
  int a = x, b = y;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(paper[a][b] != 1){
        blueSearch(x,y,N/2);
        blueSearch(x,y + N/2,N/2);
        blueSearch(x + N/2,y,N/2);
        blueSearch(x + N/2,y + N/2,N/2);
        return;
      }
      b++;
    }
    b= y;
    a++;
  }
  if(a > x)
    blue++;
}
void whtieSearch(int x, int y, int N){
  if(N < 1) return;
  int a = x, b = y;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(paper[a][b] != 0){
        whtieSearch(x,y,N/2);
        whtieSearch(x,y + N/2,N/2);
        whtieSearch(x + N/2,y,N/2);
        whtieSearch(x + N/2,y + N/2,N/2);
        return;
      }
      b++;
    }
    b= y;
    a++;
  }
  if(a > x)
    white++;
}


int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> paper[i][j];
    }
  }
  whtieSearch(0,0,N);
  blueSearch(0,0,N);
  cout << white << endl << blue;

  return 0;
}