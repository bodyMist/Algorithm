#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int list[100001];
int temp, sum = 2147000000;

int main() {
	int N;
	cin >> N;	// 용액의 수 2~100000
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	//sort(list, list + N);
	int leftIndex = 0, rightIndex = N-1;
	int leftResult = 0, rightResult = N - 1;

	while (leftIndex < rightIndex) {
		temp = list[leftIndex] + list[rightIndex];
		if (abs(temp) < abs(sum)) {
			sum = temp;
			leftResult = leftIndex;
			rightResult = rightIndex;
		}

		if (temp < 0) leftIndex++;
		else if (temp >= 0) rightIndex--;
	}

	cout << list[leftResult] << " " << list[rightResult];

	return 0;
}