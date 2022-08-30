#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<vector<double>> d;
int mst[1000005];
vector<vector<double>> coordinate(105);

int find_parent(int a){
  if(a == mst[a]) return mst[a];
  mst[a] = find_parent(mst[a]);
  return mst[a];
}
void union_set(int a, int b){
  int pa = find_parent(a);
  int pb = find_parent(b);
  mst[pb] = pa;
}

bool cmp(vector<double> &a, vector<double> &b){
  return a[2] < b[2];
}
int main(){
  int N;
  cin >> N;
  double a, b;
  for(int i = 1; i <= N; i++){
    mst[i] = i;
    cin >> a >> b;
    coordinate[i].push_back(a);
    coordinate[i].push_back(b);
  }
  double curX, curY, nextX, nextY, distance;
  for(int i = 1; i <= N; i++){
    curX = coordinate[i][0];
    curY = coordinate[i][1];
    for(int j = 1; j <= N; j++){
      if(i == j)  continue;

      nextX = coordinate[j][0];
      nextY = coordinate[j][1];
      distance = sqrt(pow((curX-nextX), 2) + pow((curY-nextY), 2));
      d.push_back({(double)i,(double)j,distance});
    }
  }

  sort(d.begin(), d.begin() + d.size(), cmp);

  int cnt = 0;
  int x, y, px, py;
  double result = 0;
  for(int i = 0; i < d.size(); i++){
    if(cnt == N-1)  break;
    x = d[i][0];
    y = d[i][1];
    px = find_parent(x);
    py = find_parent(y);
    if(px != py){
      union_set(x, y);
      result += d[i][2];
      cnt++;
    }
  }

  printf("%.2f", result);
  return 0;
}