#include<iostream>
using namespace std;

int stairs[400] = { 0 };
int sum[400] = { 0 };
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	sum[1] = stairs[1];
	sum[2] = sum[1] + stairs[2];
	int A, B;
	for (int i = 3; i <= N; i++) {
		A = sum[i - 2];
		B = stairs[i - 1] + sum[i - 3];
		sum[i] = A < B ? B : A;
		sum[i] += stairs[i];
	}
	cout << sum[N];
	return 0;
}