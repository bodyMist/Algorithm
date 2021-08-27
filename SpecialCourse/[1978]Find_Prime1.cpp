#include<iostream>
#include<algorithm>
using namespace std;

bool result[2001];
int list[2000];
int countPrime(int N) {
	result[0] = false;
	result[1] = false;
	int index;
	for (int i = 1; i <= 2000; i++) {
		if (result[i] == true) {
			index = i * i;
			while (index <= 2000) {
				result[index] = false;
				index += i;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (result[list[i]] == true) count++;
	}
	return count;
}
int main() {
	int N;
	cin >> N;
	fill(result, result + 2000, true);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cout << countPrime(N);
	return 0;
}