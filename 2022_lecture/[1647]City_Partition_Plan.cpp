#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int mst[100005];
vector<vector<int>> input(1000001);
int result;

int find_parent(int a){
  if(mst[a] == a) return mst[a];

  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b, int c){
  int pa = find_parent(a);
  int pb = find_parent(b);
  mst[pa] = pb;
  result += c;
}

bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}
int main(){
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    mst[i] = i;
  }
  int a, b, c;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    input[i].push_back(a);
    input[i].push_back(b);
    input[i].push_back(c);
  }
  sort(input.begin(), input.begin() + M, cmp);
  int cnt = 0;
  for(int i = 0; i < M; i++){
    a = input[i][0];
    b = input[i][1];
    c = input[i][2];
    int pa = find_parent(a);
    int pb = find_parent(b);
    if( pa != pb ){
      union_set(a,b,c);
      cnt++;
    }
    if(cnt == N-1){
      result -= c;
      break;
    }
  }
  cout << result;
  return 0;
}