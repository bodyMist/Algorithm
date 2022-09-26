#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<pair<int, int>> chart;
int main(){
  int N, result = 0;
  cin >> N;
  int t, p;
  for(int i = 0; i < N; i++){
    cin >> t >> p;
    chart.push_back(make_pair(t, p));
  }
  int rep = pow(2, N+1) - 1;
  for(int i = 1; i <= rep; i++){
    bool check[20] = {0};
    int now = i, sum = 0;
    int index = 1;
    while(now > 0 && index <= N){
      check[index++] = now % 2;
      now /= 2;
    }
    int term = 0, preDay = 1;
    index = 1;
    while(index <= N){
      if(preDay + term - 1 < index && check[index]){
        if(index + chart[index-1].first - 1 <= N){
        sum += chart[index-1].second;
        term = chart[index-1].first;
        preDay = index;
        }
      }
      index++;
    }
    if(result < sum)  result = sum;
  }
  cout << result;
  return 0;
}