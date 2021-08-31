#include<iostream>
using namespace std;


// memo[i] = memo[i-1]+1 + memo[i-2]+2 + memo[i-3]+3
int memo[100000] = { 1,1, 2 };
int main() {
	int T,N;
	cin >> T;
	for (int i = 3; i < 100000; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i-3];
	}
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << memo[N] << "\n";
	}
	return 0;
}