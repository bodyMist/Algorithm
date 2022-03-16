#include<iostream>
#include<stack>
using namespace std;

stack<pair<int,int>> melody;
stack<pair<int,int>> stock;

int main(){
  int N, P;
  cin >> N >> P;
  int first, second;
  pair<int, int> input;
  pair<int, int> top;
  int result = 0;
  for(int i = 0; i < N; i++){
    cin >> first >> second;
    input = {first, second};
    

    while(true){
      if(melody.empty()){
        melody.push(input);
        result++;
        break;
      }
      top = melody.top();

      if(top.first != first){
        stock.push(top);
        melody.pop();
      }
      else if(top.second > second){
        melody.pop();
        result++;
      }
      else if(top.second < second){
        melody.push(input);
        result++;
        break;
      }else{
        break;
      }
    }

    while(stock.empty() == false){
      melody.push(stock.top());
      stock.pop();
    }
  }
  
  cout << result;
  return 0;
}