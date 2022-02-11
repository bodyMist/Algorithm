#include<iostream>
#include<vector>
using namespace std;

vector<int> list;
int LIS[1100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, input, max = 0;
	cin >> N;
	list.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> input;
		list.push_back(input);
	}
	for (int i = 1; i <= N; i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1;
		}
		//cout << LIS[i] << " ";
		if (max < LIS[i]) max = LIS[i];
	}
	cout << max;
	return 0;
}