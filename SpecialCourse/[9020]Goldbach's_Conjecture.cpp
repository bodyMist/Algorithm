#include<iostream>
using namespace std;

bool result[10001];

void getPrime(int N) {
	result[0] = false;
	result[1] = false;
	int index;
	for (int i = 1; i <= 1000; i++) {
		if (result[i] == true) {
			index = i * i;
			while (index <= 10000) {
				result[index] = false;
				index += i;
			}
		}
	}
	int sum = 0;
	for (int i = N / 2; i >= 2; i--) {
		if (result[i] == false) continue;
		for (int j = N/2; j <= N-2; j++) {
			if (result[j] == false) continue;
			sum = i + j;
			if (sum == N) {
				cout << i << " " << j << "\n";
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(result, result + 10000, true);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		getPrime(N);
	}
	return 0;
}