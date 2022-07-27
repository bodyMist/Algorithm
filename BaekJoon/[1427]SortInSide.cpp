#include<iostream>
using namespace std;

void merge(int A[], int p, int q, int r){
  int i = p, j = q+1, k = p;
  int temp[15]={0};

  while(i <= q && j <= r){
    if(A[i] <= A[j])
      temp[k++] = A[i++];
    else
      temp[k++] = A[j++];
  }
    while(i <= q){
      temp[k++] = A[i++];
    }
    while(j <= r){
      temp[k++] = A[j++];
    }
    for(int t = p; t <= r; t++){
      A[t] = temp[t];
    }
}
void merge_sort(int A[], int l, int r){
  if(l < r){
    int q = (l+r) / 2;
    merge_sort(A, l, q);
    merge_sort(A, q+1, r);
    merge(A, l, q, r);
  }
}

int main(){
  int input, index = 0;
  cin >> input;
  int digit[15];
  while(input > 0){
    digit[index++] = input % 10;
    input /= 10;
  }
  merge_sort(digit, 0, index-1);
  for(int i = index-1; i >= 0; i--){
    cout << digit[i];
  }
  return 0;
}