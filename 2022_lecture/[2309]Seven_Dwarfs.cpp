#include<iostream>
#include<algorithm>
using namespace std;

int list[10];
int main(){
  int sum = 0;
  for(int i = 0; i < 9; i++){
    cin >> list[i];
    sum += list[i];
  }
  sort(list, list+9);
  int tempSum = sum;
  int x, y;
  for (int i = 0; i < 8; i++){
    for (int j = i+1; j < 9; j++){
      x = i;
      y = j;
      tempSum -= (list[i] + list[j]);
      if(tempSum == 100) break;
      tempSum = sum;
    }
    if(tempSum == 100) break;
  }
  
  for (int i = 0; i < 9; i++){
    if (i == x || i == y)
      continue;
    cout << list[i] << endl;
  }

  return 0;
}