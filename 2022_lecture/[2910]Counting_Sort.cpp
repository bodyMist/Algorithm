#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int, pair<int, int>> m;
bool cmp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){
  if(a.second.first == b.second.first) return a.second.second < b.second.second;
  return a.second.first > b.second.first;
}

int main(){
  int N, C;
  cin >> N >> C;
  int input;
  for(int i = 0; i < N; i++){
    cin >> input;
    if(m.find(input) != m.end()){
      m.find(input)->second.first++;
    }
    m.insert({input, {1,i}});
  }
  vector<pair<int, pair<int,int>>> list(m.begin(), m.end());
  sort(list.begin(), list.end(), cmp);

  for(int i = 0; i < list.size(); i++){
    for(int j = 0; j < list[i].second.first; j++){
      cout << list[i].first << " ";
    }
  }
  return 0;
}