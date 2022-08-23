#include<iostream>
#include<stack>
using namespace std;

int main(){
  string input;
  cin >> input;

  stack<char> s;
  int result = 0, temp = 1;
  for(int i = 0; i < input.length(); i++){
    char pointer = input[i];
    switch(pointer){
      case '(':
        s.push(pointer);
        temp *= 2;
        break;

      case '[':
        s.push(pointer);
        temp *= 3;
        break;

      case ')':
        if (input[i - 1] == '(') {
          result += temp;
        }
        if(!s.empty() && s.top() == '(')
          s.pop();
        temp /= 2;
        break;

      case ']':
        if (input[i - 1] == '[') {
          result += temp;
        }
        if(!s.empty() && s.top() == '[')
          s.pop();
        temp /= 3;
        break;
    }
  }

  if(!s.empty())  cout << "0";
  else  cout << result;

  return 0;
}