#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int testcase;
  cin >> testcase;
  for(int i = 0; i < testcase; i++){
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    // case1 : 원이 일치할 경우 -> 모두 동일해야함 -> 교차점 무한대이므로 -1 출력
    // case2 : 원이 두 점으로 교차하는경우 -> r1 + r2 > 중점 거리 && r1 - r2 < 중점 거리
    // case3 : 원이 접하는 경우. 외접 -> r1 + r2 = 중점 거리
    // case4 : 원이 접하는 경우, 내접 -> r1 - r2 = 중점 거리
    // case5 : 원이 만나지 않는 경우 -> r1 + r2 < 중점 거리
    int central_distance = pow(x1-x2, 2) + pow(y1-y2, 2);
    int radius_gap = (r1 - r2)*(r1 - r2);
    int radius_distance = (r1 + r2) * (r1 + r2);

    if(central_distance == 0 && radius_gap == 0){
      cout << -1 << endl;
    }else if(central_distance == radius_distance || central_distance == radius_gap){
      cout << 1 << endl;
    }else if(central_distance < radius_distance && central_distance > radius_gap){
      cout << 2 << endl;
    }else{
      cout << 0 << endl;
    }
  }
  return 0;
}