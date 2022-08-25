#include<iostream>
#include<vector>
using namespace std;

int mst[1005];
vector<vector<int>> enemy(1005);
int find_parent(int a){
  if(a == mst[a]) return mst[a];
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int pa = find_parent(a);
  int pb = find_parent(b);
  mst[pa] = pb;
}

int main(){
  int N, M;
  cin >> N >> M;
  
  char relationship;
  int p, q;
  for(int i = 0; i <= N; i++){
    mst[i] = i;
  }
  for(int i = 0; i < M; i++){
    cin >> relationship >> p >> q;
    if(relationship == 'E'){
      enemy[p].push_back(q);
      enemy[q].push_back(p);
    }else if(relationship == 'F'){
      if(find_parent(p) != find_parent(q))
        union_set(p,q);
    }
  }
  for(int i = 1; i <= N; i++){
    if(enemy[i].size() <= 1)  continue;
    for(int j = 0; j < enemy[i].size() - 1; j++){
      for(int k = j+1; k < enemy[i].size(); k++){
        p = enemy[i][j];
        q = enemy[i][k];
        if(find_parent(p) != find_parent(q))
          union_set(p,q);
      }
    }
  }
  int result = 0;
  for(int i = 1; i <= N; i++){
    if(mst[i] == i)
      result++;
  }
  cout <<result;

  return 0;
}