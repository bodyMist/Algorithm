#include<iostream>
using namespace std;

int list[20000];
int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
  int N;
  cin >> N;
  
  int input;
  for(int i = 0; i < N; i++){
    cin >> input;
    list[input]++;
  }
  for(int i = 0; i < 20000; i++){
    if(list[i] == 0)
      continue;
    for(int j = 0; j < list[i]; j++){
      cout << i << '\n';
    }
  }
  return 0;
}