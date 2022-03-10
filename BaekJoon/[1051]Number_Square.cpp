// NxM 만큼의 숫자들로 이루어진 직사각형
// 직사각형 내부에서 정사각형 만들어서 꼭짓점이 모두 같도록
// 후보 중에 정사각형이 가장 큰 놈이 답
// N,M <= 50

#include<iostream>
using namespace std;


int main(){
  int N,M;
  char line[51];
  int input[50][50];
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> line;
    for(int j = 0; j < M; j++){
      input[i][j] = line[j]-'0';
    }
  }
  int smaller = N > M ? M : N;
  int result = 1;

  for(int i = smaller; i > 0; i--){
    for(int j = 0; j+i < N; j++){
      for(int k = 0; k+i < M; k++){
        if(input[j][k] == input[j][k+i]){
          if(input[j][k] == input[j+i][k]){
            if(input[j][k] == input[j+i][k+i]){
              result = i + 1;
              cout << result * result;
              return 0;
            }
          }
        }
      }
    }
  }

  cout << result;
  return 0;
}