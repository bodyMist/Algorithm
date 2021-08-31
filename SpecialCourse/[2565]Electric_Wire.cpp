#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int>> A(600);
int resultIndex;
int main() {
	/*
	* 1 1
	* 2 4
	* 3 2
	* 4 3
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int LIS[200];
	int N, max = 0;
	cin >> N;
	int left, right;
	for (int i = 1; i <= N; i++) {
		cin >> left >> right;
		A[i] = pair<int, int>(left, right);
	}
	sort(A.begin() + 1, A.begin() + N + 1);
	fill(LIS, LIS + 200, 600);
	int currentIndex;
	for (int i = 1; i <= N; i++) {
		currentIndex = upper_bound(LIS, LIS + N, A[i].second) - LIS;
		LIS[currentIndex] = A[i].second;
	}
	int resultIndex = 0;
	for (int i = 0; i <= N; i++) {
		if (LIS[i] == 600) break;
		resultIndex++;
	}
	cout << N - resultIndex;
	return 0;
}