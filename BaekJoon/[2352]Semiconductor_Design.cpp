#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int>> list(41000);
int main() {
	int N, input;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		list[i] = pair<int, int>(i, input);
	}
	//sort(list.begin() + 1, list.begin() + N);
	int LIS[41000];
	fill(LIS, LIS + 41000, 41000);
	int currentIndex;
	for (int i = 1; i <= N; i++) {
		currentIndex = upper_bound(LIS, LIS + N, list[i].second) - LIS;
		LIS[currentIndex] = list[i].second;
	}
	int resultIndex = 0;
	for (int i = 0; i <= N; i++) {
		if (LIS[i] == 41000) break;
		resultIndex++;
	}
	cout << resultIndex;
	return 0;
}