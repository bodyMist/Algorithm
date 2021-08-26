#include<iostream>
using namespace std;

long long trees[1000000];
long long mid, temp;
long long low = 1, high = 2000000000, sum, ans;
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
	while (low <= high) {
		sum = 0;
		mid = (low + high) / 2;
		temp = mid;
		for (int i = 0; i < N; i++) {
			if (mid < trees[i]) {
				sum += (trees[i] - mid);
			}
		}
		if (sum >= M) {
			low = mid + 1;
			ans = mid;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}