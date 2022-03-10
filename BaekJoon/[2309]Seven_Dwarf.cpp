// 입력 : 9개의 자연수, 100이하, 같은 값 없음
// 합이 100이 되는 경우 아무거나 오름차순 출력
// 답이 없는 경우는 없음

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int input[9];
  int sum = 0, tempSum = 0;
  int registerA, registerB;

  for (int i = 0; i < 9; i++){
    cin >> input[i];
    sum += input[i];
  }
  sort(input, input+9);
  tempSum = sum;

  for (int i = 0; i < 8; i++){
    for (int j = i+1; j < 9; j++){
      registerA = i;
      registerB = j;
      tempSum -= (input[i] + input[j]);
      if(tempSum == 100) break;
      tempSum = sum;
    }
    if(tempSum == 100) break;
  }
  for (int i = 0; i < 9; i++){
    if (i == registerA || i == registerB)
      continue;
    cout << input[i] << endl;
  }
  return 0;
}