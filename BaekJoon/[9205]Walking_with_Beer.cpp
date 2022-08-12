#include<iostream>
#include<queue>
using namespace std;

void bfs(vector<pair<int,int>> points, vector<int> visit){
  queue<pair<int,int>> q;
  q.push(points.at(0));
  int length = points.size();
  while(!q.empty()){
    pair<int,int> here = q.front();
    q.pop();
    if(here.first == points.back().first && here.second == points.back().second){
      cout << "happy" << endl;
      return;
    }
    for(int i = 0; i < length; i++){
      if(!visit[i] && abs(here.first - points[i].first) + abs(here.second - points[i].second) <= 1000){
        q.push(points[i]);
        visit[i] = 1;
      }
    }
  }
  cout << "sad" << endl;
}

int main(){
  int T;
  cin >> T;

  for(int t = 0; t < T; t++){
    int n;
    cin >> n;
    vector<pair<int,int>> point;
    vector<int> visit(200);
    
    for(int i = 0; i < n+2; i++){
      int a,b;
      cin >> a >> b;
      point.push_back(make_pair(a,b));
    }
    bfs(point, visit);
  }
  return 0;
}