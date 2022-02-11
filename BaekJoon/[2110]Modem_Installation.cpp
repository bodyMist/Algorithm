#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> house;
long long low = 1, high = 2147483647, ans, mid, temp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C, count, input;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());
	while (low <= high) {
		mid = (low + high) / 2;
		count = 1;
		for (int i = 0; i < N; i++) {
			temp = lower_bound(house.begin() + i, house.end(), house[i] + mid) - house.begin();
			if (temp != house.size()) {
				count++;
				i = temp-1;
			}
		}

		if (count >= C) {
			low = mid + 1;
			ans = mid;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}