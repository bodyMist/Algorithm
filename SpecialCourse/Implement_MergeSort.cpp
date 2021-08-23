#include<iostream>
using namespace std;

int list[20] = { 10,5,6,4,3,2,1,9,8,7 };
void merge(int left, int right) {
	int mid = (left + right) / 2;
	int leftIndex = left;
	int rightIndex = mid + 1;
	int resultIndex = left;
	int temp[20];

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
	partition(0, 10);
	for (int i = 0; i < 11; i++) {
		cout << list[i] << " ";
	}

}