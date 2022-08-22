#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N, M, result = 0;
  cin >> N >> M;
  vector<string> notHeard;
  string input;
  for(int i = 0; i < N+M; i++){
    cin >> input;
    notHeard.push_back(input);
  }
  
  sort(notHeard.begin(), notHeard.begin()+ N+M);
  
  vector<string> t;
  for(int i = 0; i < N+M-1; i++){
    if(notHeard[i] == notHeard[i+1]){
      result++;
      t.push_back(notHeard[i]);
    }
  }
  cout << result << endl;
  for(int i = 0; i < result; i++){
    cout << t[i] << endl;
  }
  return 0;
}