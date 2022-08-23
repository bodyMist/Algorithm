#include<iostream>
using namespace std;

int list[1000005];
int temp[1000005];

void merge(int left, int val, int right){
  int i = left, j = val+1, k = left;
  while(i <= val && j <= right){
    if(list[i] <= list[j])
      temp[k++] = list[i++];
    else
      temp[k++] = list[j++];
  }

  while(i <= val){
    temp[k++] = list[i++];
  }
  while(j <= right){
    temp[k++] = list[j++];
  }
  for(int t = left; t <= right; t++){
    list[t] = temp[t];
  }
}
void merge_sort(int left, int right){
  if(left < right){
    int val = (left + right) / 2;
    merge_sort(left, val);
    merge_sort(val + 1, right);
    merge(left, val, right);
  }
}
int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> list[i];
  }
  merge_sort(0, N-1);
  for(int i = 0; i < N; i++){
    cout << list[i] << "\n";
  }
  return 0;
}