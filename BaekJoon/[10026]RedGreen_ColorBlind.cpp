#include<iostream>
using namespace std;

char colorArray[200][200];
char check[200][200];
int normalResult, blindResult;
int N;

bool checkPoint(int i, int j){
  return i < 0 || j < 0 || i >= N || j >= N ? false : true;
}
int dfs(int i, int j){
  if(check[i][j] == true)
    return 0;
  char here = colorArray[i][j];
  check[i][j] = true;
  if(checkPoint(i+1, j) && here == colorArray[i+1][j])
    dfs(i+1, j);
  if(checkPoint(i-1, j) && here == colorArray[i-1][j])
    dfs(i-1, j);
  if(checkPoint(i, j+1) && here == colorArray[i][j+1])
    dfs(i, j+1);
  if(checkPoint(i, j-1) && here == colorArray[i][j-1])
    dfs(i, j-1);

  return 1;
}

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> colorArray[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      normalResult += dfs(i,j);
    }
  }

  for(int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if(colorArray[i][j] == 'R')
        colorArray[i][j] = 'G';
      check[i][j] = false;
    }
  }
  
  for(int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      blindResult += dfs(i,j);
    }
  }

  cout << normalResult << " " << blindResult;
  return 0;
}