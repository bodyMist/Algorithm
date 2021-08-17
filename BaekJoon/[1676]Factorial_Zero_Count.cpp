#include<iostream>
using namespace std;

int solve(int N) {
	int count = 0;
	int target = N;
	count += target / 5;
	count += target / 25;
	count += target / 125;
	return count;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << solve(N);

	return 0;
}