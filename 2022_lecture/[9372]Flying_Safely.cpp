#include<iostream>
using namespace std;

int mst[2000];
int find_parent(int a){
  if(a == mst[a]) return a;
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int pa = find_parent(a);
  int pb = find_parent(b);
  mst[pa] = pb;
}
int main(){
  int T;
  cin >> T;
  for(int t = 0; t < T; t++){
    int N, M, result = 0;
    cin >> N >> M;
    int a, b;
    for(int i = 1; i <= N; i++){
      mst[i] = i;
    }
    for(int i = 0; i < M; i++){
      cin >> a >> b;
      if(find_parent(a) != find_parent(b)){
        union_set(a, b);
        result++;
      }
    }
    cout << result << '\n';
  }
  return 0;
}