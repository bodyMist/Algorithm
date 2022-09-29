#include<iostream>
#include<string>
using namespace std;

// 각각 C, H, O 순서
int a[3];
int b[3];
int c[3];

void addChemical(string operand, int *arr){
  for(int i = 0; i < operand.length(); i++){
    char chemical = operand[i];
    int count = 1;
    if(i+1 < operand.length() && '2' <= operand[i+1] && operand[i+1] <= '9')  count = operand[i+1] - '0';

    if(chemical == 'C'){
      arr[0] += count;
    }else if(chemical == 'H'){
      arr[1] += count;
    }else if(chemical == 'O'){
      arr[2] += count;
    }
  }
}
int main(){
  string input;
  getline(cin, input);
  string operandA, operandB, operResult;
  int plusIndex, equalIndex;
  plusIndex = input.find("+");
  equalIndex = input.find("=");

  operandA = input.substr(0,plusIndex);
  operandB = input.substr(plusIndex+1, equalIndex - plusIndex - 1);
  operResult = input.substr(equalIndex+1, input.length() - equalIndex);
  
  addChemical(operandA, a);
  addChemical(operandB, b);
  addChemical(operResult, c);
  
  for(int i = 1; i <= 10; i++){
    for(int j = 1; j <= 10; j++){
      for(int k = 1; k <= 10; k++){
        if(i * a[0] + j * b[0] == k * c[0]){
          if(i * a[1] + j * b[1] == k * c[1]){
            if(i * a[2] + j * b[2] == k * c[2]){
              cout << i << " " << j << " " << k;
              return 0;
            }
          }
        }
      }
    }
  }

  return 0;
}