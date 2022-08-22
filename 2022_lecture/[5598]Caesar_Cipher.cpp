#include<iostream>
using namespace std;

int main(){
  char input[2000];
  cin >> input;
  for(int i = 0; input[i] != '\0'; i++){
    input[i] -= 3;
    if(input[i] < 'A')
      input[i] += 26;
    cout << input[i];
  }
  return 0;
}