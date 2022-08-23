#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
  string input;
  cin >> input;
  int M;
  cin >> M;
  stack<char> left;
  stack<char> right;
  for(int i = 0; i < input.length(); i++){
    left.push(input[i]);
  }
  cin.ignore();

  for(int i = 0; i < M; i++){
    string command;
    getline(cin, command);
    char edit = command[0];
    switch(edit){
      case 'L':
        if(!left.empty()){
          right.push(left.top());
          left.pop();
        }
        break;

      case 'D':
        if(!right.empty()){
          left.push(right.top());
          right.pop();
        }
        break;

      case 'B':
        if(!left.empty()){
          left.pop();
        }
        break;

      case 'P':
        left.push(command[2]);
        break;
    }
  }

  while(!left.empty()){
    right.push(left.top());
    left.pop();
  }
  while(!right.empty()){
    cout << right.top();
    right.pop();
  }
  return 0;
}