#include<iostream>
using namespace std;

int mst[10005];
int fee[10005];
int find_parent(int a){
  if(a == mst[a]) return a;
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int pa = find_parent(a);
  int pb = find_parent(b);
  if(fee[pa] > fee[pb]) mst[pa] = pb;
  else  mst[pb] = pa;
}
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++){
    mst[i] = i;
    cin >> fee[i];
  }
  int v, w;
  for(int i = 0; i < M; i++){
    cin >> v >> w;
    if(v == w)  continue;
    union_set(v, w);
  }
  int result = 0;
  for(int i = 1; i <= N; i++){
    if(i == mst[i]){
      result += fee[i];
    }
  }
  if(result <= K)  cout << result;
  else cout << "Oh no";
  return 0;
}