#include<iostream>

using namespace std;

int list[100001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, K;
  cin >> N >> K;

  int input;
  for(int i = 0; i < N; i++){
    cin >> input;
    list[i] = input;
    if(i == 0) continue;
    list[i] += list[i-1];
  }
  int result = -100000000, sum = 0, index;
  for(int i = 0; i < N-1; i++){
    index = i + K -1;
    if(index >= N)  break;

    sum = list[index];
    if(i != 0){
      sum -= list[i-1];
    }
    if(result < sum) result = sum;
  }
  cout << result;

  return 0;
}