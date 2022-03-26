#include<iostream>
using namespace std;

int permutation[8] = {1,2,3,4,5,6,7,8};
int arr[8];
int visit[8];

void perm(int N, int r, int index){
  if(r == index){
    for(int i = 0; i < N; i++){
      cout << arr[i] << " ";
    }
      cout << "\n";
  }else{
    for(int i = 0; i < N; i++){
      if(visit[i] == 0){
        arr[index] = permutation[i];
        visit[i] = 1;
        perm(N,r,index+1);
        visit[i] = 0;
      }
    }
  }
}


int main(){
  int N;
  cin >> N;
  perm(N, N, 0);

  return 0;
}