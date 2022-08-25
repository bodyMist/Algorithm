#include<iostream>
#include<map>
using namespace std;

int mst[210000];
int result[210000];

map<string,int> name;
int find_parent(int a){
  if (a == mst[a])  return mst[a];
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int pa = find_parent(a);
  int pb = find_parent(b);
  mst[pa] = pb;
  result[pb] += result[pa];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int T;
  cin >> T;
  for(int t = 0; t < T; t++){
    int cnt = 0;
    int F;
    cin >> F;
    string a, b;
    for(int i = 0; i < 210000; i++){
      mst[i] = i;
      result[i] = 1;
    }
    for(int i = 0; i < F; i++){
      cin >> a >> b;
      auto iterA = name.find(a);
      auto iterB = name.find(b);
      int indexA, indexB;

      if(iterA == name.end()){
        name.insert({a, ++cnt});
        indexA = cnt;
      }else{
        indexA = iterA->second;
      }
      
      if(iterB == name.end()){
        name.insert({b, ++cnt});
        indexB = cnt;
      }else{
        indexB = iterB->second;
      }
      if(find_parent(indexA) != find_parent(indexB)){
        union_set(indexA, indexB);
      }

      int pa = find_parent(indexA);
      cout << result[pa] << '\n';
    }
    fill(mst, mst+210000, 0);
    name.clear();
  }
  return 0;
}