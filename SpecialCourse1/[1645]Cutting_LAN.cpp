#include<iostream>
using namespace std;

long long low = 1, high = 2147483647, mid, ans, temp;
int lan[10000];
int main() {
	int K, N, count;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
	}
	while (low <= high) {
		mid = (low + high) / 2;
		count = 0;
		for (int i = 0; i < K; i++) {
			temp = lan[i];
			while (temp >= mid) {
				temp -= mid;
				count++;
			}
		}
		if (count >= N) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}