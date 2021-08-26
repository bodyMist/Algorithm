#include<iostream>
#include<algorithm>
using namespace std;
long long low = 1, high = 100000, sum, ans, mid, temp;
int target[10000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}
	cin >> M;

	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid > target[i]) {
				sum += target[i];
				temp = temp < target[i] ? target[i] : temp;
			}
			else {
				sum += mid;
				temp = mid;
			}
		}

		if (sum <= M) {
			low = mid + 1;
			ans = ans < temp ? temp : ans;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}