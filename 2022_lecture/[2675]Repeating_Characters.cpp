#include<iostream>
using namespace std;

int main(){
  int testcase;
  cin >> testcase;
  for(int i = 0; i < testcase; i++){
    int R;
    cin >> R;
    char input[21];
    cin >> input;

    for(int j = 0; input[j] != '\0'; j++){
      for(int k = 0; k < R; k++){
        cout << input[j];
      }
    }
    cout << endl;
  }
  return 0;
}