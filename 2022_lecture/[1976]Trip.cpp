#include<iostream>
#include<vector>
#include<string>
using namespace std;

int mst[2000];
int find_parent(int a){
  if (a == mst[a])  return mst[a];
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
  for(int i = 0; i <= N; i++){
    mst[i] = i;
  }
  int connect;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> connect;
      if(connect){
        union_set(i, j);
      }
    }
  }
  vector<int> tripList;
  int trip;
  for(int i = 0; i < M; i++){
    cin >> trip;
    tripList.push_back(trip);
  }

  int parent = find_parent(tripList[0]);
  for(int i = 1; i < M; i++){
    if(parent != find_parent(tripList[i])){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}