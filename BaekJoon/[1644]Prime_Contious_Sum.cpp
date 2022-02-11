#include<iostream>
#include<algorithm>
using namespace std;

bool result[5000000];
int primeList[5000000];
int listSize;
void getPrime() {
	int index;
	for (int i = 2; i < 3000; i++) {
		if (result[i] == true) {
			index = i * i;
			while (index < 5000000) {
				result[index] = false;
				index += i;
			}
		}
	}
	for (int i = 2; i < 5000000; i++) {
		if (result[i] == true) {
			primeList[listSize++] = i;
		}
	}
}
int main() {
	fill(result, result + 5000000, true);
	int N;
	cin >> N;
	result[0] = false;
	result[1] = false;
	getPrime();
	int sum = 0, count = 0;
	int leftIndex = 0, rightIndex = 0;
	while (leftIndex < listSize) {
		if (sum < N)	sum += primeList[rightIndex++];
		else if (sum >= N)	sum -= primeList[leftIndex++];
		if (sum == N) count++;
	}

	cout << count;
	return 0;
}