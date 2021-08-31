#include<iostream>
using namespace std;

long long memo[10000] = { 0, 1, 2 };
// 1 2 3 5 
int main() {
	int N;
	cin >> N;
	for (int i = 3; i <= 1000; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	}
	cout << memo[N];
	return 0;
}