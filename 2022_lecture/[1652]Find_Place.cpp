#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  char room[110][100];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> room[i][j];
    }
  }
  int left = 0;
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = 0; j < N; j++){
      if(room[i][j] == 'X'){
        if(sum >= 2)  left++;
        sum = 0;
      }else{
        sum++;
      }
    }
    if(sum >= 2)  left++;
  }

  int right = 0;
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = 0; j < N; j++){
      if(room[j][i] == 'X'){
        if(sum >= 2)  right++;
        sum = 0;
      }else{
        sum++;
      }
    }
    if(sum >= 2)  right++;
  }
  cout << left << " " << right;
  return 0;
}