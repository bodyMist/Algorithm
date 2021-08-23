#include<iostream>
using namespace std;

int list[10] = { 9,6,3,8,5,2,7,4,1,10 };
void quicksort(int left, int right) {
	int LEFT = left;
	int RIGHT = right;
	int pivot = list[(left + right)/2];
	while (left <= right) {
		while (list[left] < pivot) left++;
		while (list[right] > pivot) right--;
		if (left <= right) {
			int temp = list[left];
			list[left] = list[right];
			list[right] = temp;
		}
		else {
			list[(left + right) / 2] = list[right];
			list[right] = pivot;
		}
	}
	quicksort(LEFT, right);
	quicksort(left, RIGHT);
}

int main() {
	quicksort(0, 9);
	for (int i = 0; i < 10; i++) {
		cout << list[i] << " ";
	}
	return 0;
}