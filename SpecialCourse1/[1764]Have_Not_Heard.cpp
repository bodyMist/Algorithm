#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	string input;
	cin >> N >> M;
	cin.ignore();
	vector<string> list;
	for (int i = 0; i < N + M; i++) {
		getline(cin, input);
		list.push_back(input);
	}
	sort(list.begin(), list.begin() + (N + M));
	int result = 0;
	for (int i = 0; i < N+M; i++) {
		if (i != 0 && list[i] == list[i - 1])
			result++;
	}
	cout << result << "\n";
	for (int i = 0; i < N + M; i++) {
		if (i != 0 && list[i] == list[i - 1])
			cout << list[i] << "\n";
	}
	return 0;
}