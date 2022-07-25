#include<iostream>
using namespace std;

void merge(int sub[], int p, int q, int r){
  int i = p;
  int j = q+1;
  int k = p;
  int temp[2000] = {0};

  while(i <= q && j <= r){
    if(sub[i] <= sub[j])
      temp[k++] = sub[i++];
    else
      temp[k++] = sub[j++];
  }
  
  while(i <= q)
    temp[k++] = sub[i++];
  while(j <= r)
    temp[k++] = sub[j++];
  for(int t = p; t <= r; t++)
    sub[t] = temp[t];
}
void merge_sort(int sub[], int p, int r){
  if (p < r) {
    int q = (p+r) / 2;
    merge_sort(sub,p,q);
    merge_sort(sub,q+1,r);
    merge(sub, p, q, r);
  }
}

int main(){
  int N;
  cin >> N;
  int p[2000] = {0};
  for(int i = 0; i < N; i++){
    cin >> p[i];
  }
  merge_sort(p,0,N-1);
  
  int result = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j <=i; j++){
      result += p[j];    
    }
  }
  cout << result;

  return 0;
}