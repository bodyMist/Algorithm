#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int mst[10005];
vector<vector<int>> edges(100001);

int find_parent(int a){
  if(a == mst[a]) return a;
  
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int a_parent = find_parent(a);
  int b_parent = find_parent(b);
  mst[b_parent] = a_parent;
}

bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}
int main(){
  int V,E, result = 0;
  cin >> V >> E;
  for(int i = 0; i <= V; i++){
    mst[i] = i;
  }
  int a, b, weight;
  for(int i = 0; i < E; i++){
    cin >> a >> b >> weight;
    edges[i].push_back(a);
    edges[i].push_back(b);
    edges[i].push_back(weight);
  }
  sort(edges.begin(), edges.begin()+E, cmp);

  int cnt = 0;
  for(int i = 0; i <= E; i++){
    a = edges[i][0];
    b = edges[i][1];
    weight = edges[i][2];
    if(find_parent(a) == find_parent(b))
      continue;
    else{
      union_set(a, b);
      result += weight;
      cnt++;
    }
    if(cnt == V-1){
      cout << result;
      return 0;
    }
  }
  return 0;
}