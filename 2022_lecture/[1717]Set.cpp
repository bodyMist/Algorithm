#include<iostream>

using namespace std;
int set[1000005];

int find_parent(int a){
  if(a == set[a]) return a;
  
  set[a] = find_parent(set[a]);
  return set[a];
}
void union_set(int a, int b){
  int a_parent = find_parent(a);
  int b_parent = find_parent(b);
  set[b_parent] = a_parent;
}
int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  int oper, a, b;
  for(int i = 0; i <= N; i++){
    set[i] = i;
  }
  for(int i = 0; i < M; i++){
    cin >> oper >> a >> b;
    if(!oper){
      union_set(a,b);
    }else if(oper){
      if(find_parent(a) == find_parent(b))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}