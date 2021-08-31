#include<iostream>
using namespace std;

// N=1, 1+2	
// N=2, 1+4+2
// N=3, 1+6+6+2
// N=4, 1+8+22+8+2
// N=5, 1+10+
// 3 7 15 41
int memo[100005] = {0,3};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		memo[i] = (memo[i - 1] * 2 - 1) % 9901;
	}
	cout << memo[N];
	return 0;
}