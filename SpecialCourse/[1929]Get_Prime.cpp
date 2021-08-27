#include<iostream>
#include<algorithm>
using namespace std;

bool result[2000001];

void countPrime(int M, int N) {
	result[0] = false;
	result[1] = false;
	int index;
	for (int i = 1; i <= 1010; i++) {
		if (result[i] == true) {
			index = i * i;
			while (index <= 2000000) {
				result[index] = false;
				index += i;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (result[i] == true)
			cout << i << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M,N;
	cin >> M >> N;
	fill(result, result + 2000000, true);
	countPrime(M, N);
	return 0;
}