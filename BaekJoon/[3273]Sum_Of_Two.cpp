#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a[200000];
	for(int i =0;i <N;i++){
		cin >> a[i];
	}
  sort(a,a+N);
	
	int target;
	cin >> target;
	int sum = 0, result = 0;
	
	int l = 0, r = N-1;
	while(l < r){
    int sum = a[l] + a[r];
    if(sum == target){
      result++;
      l++;
      r--;
    }
    else if(sum > target)
      r--;
    else
      l++;
  }
	
	cout << result;
	return 0;
}