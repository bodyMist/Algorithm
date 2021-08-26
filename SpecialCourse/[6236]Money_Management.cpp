#include<iostream>
using namespace std;

int money[100000];
int ans, low = 1, high = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, mid, temp, count;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}
	while (low <= high) {
		count = 1;
		mid = (low + high) / 2;
		temp = mid;

		for (int i = 0; i < N; i++) {
			if (temp < money[i]) {
				temp = mid;
				count++;
			}
			if (temp < money[i])
			{
				count = M + 1;
				break;
			}
			temp -= money[i];
		}
		if (count <= M) {
			high = mid - 1;
			ans = mid;
		}
		else
			low = mid + 1;
	}
	cout << ans;
	return 0;
}