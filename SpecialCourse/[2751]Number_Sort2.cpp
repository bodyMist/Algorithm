#include<iostream>
using namespace std;
int list[1000000];
int temp[1000000];
void merge(int left, int right) {
	int mid = (left + right) / 2;
	int leftIndex = left;
	int rightIndex = mid + 1;
	int resultIndex = left;

	while (leftIndex <= mid && rightIndex <= right) {
		if (list[leftIndex] <= list[rightIndex])	temp[resultIndex++] = list[leftIndex++];
		else	temp[resultIndex++] = list[rightIndex++];
	}
	while (leftIndex <= mid)
		temp[resultIndex++] = list[leftIndex++];
	while (rightIndex <= right)
		temp[resultIndex++] = list[rightIndex++];

	for (int i = left; i <= right; i++) {
		list[i] = temp[i];
	}
}
void partition(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	partition(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << list[i]<<"\n";
	}
	return 0;
}