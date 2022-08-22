#include<iostream>
#include<vector>
using namespace std;

int main(){
  int testcase;
  cin >> testcase;
  for(int t = 0; t < testcase; t++){
    string input;
    cin >> input;
    int length = input.size();
    int sum = 0, ac = 0;
    for(int i = 0; i < length; i++){
      if(input[i] == 'O'){
        ac++;
        sum += ac;
      }else{
        ac = 0;
      }
    }
    cout << sum << endl;
  }
}