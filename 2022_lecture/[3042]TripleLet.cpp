#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, result = 0;
  cin >> N;
  char arr[100][100];
  vector<pair<int,int>> list;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
      if('A' <= arr[i][j] && arr[i][j] <= 'Z')
        list.push_back(make_pair(i,j));
    }
  }
  int length = list.size();
  for(int i = 0; i < length; i++){
        int xi = list[i].first;
        int xj = list[i].second;
    for(int j = i + 1; j < length; j++){
        int yi = list[j].first;
        int yj = list[j].second;
      for(int k = j + 1; k < length; k++){
        int zi = list[k].first;
        int zj = list[k].second;
        if( ((xj-yj) * (yi-zi)) == ((xi-yi) * (yj-zj)))
          result++;
      }
    }
  }
  cout << result;
  return 0;
}