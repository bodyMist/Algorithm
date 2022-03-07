// 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
// 2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
// 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이

// 입력
// N은 홀수, (1~500,000). 절댓값이 4000을 넘지 않는 정수들 N개 입력
// 출력
// 1. 산술평균, 소수점 첫째 자리 반올림
// 2. 중앙값
// 3. 최빈값, 다수일 경우 두번째로 작은값
// 4. 범위

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int N, input;
	cin >> N;
	double average = 0;
	int median = 0, frequent = 0, domain = 0;
	int array[8001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> input;
		array[input + 4000]++;
		average += input;
	}

	average = round(average/N);
  if(average == 0) average = unsigned(average);

	int medianCount = 0, medianIndex = 0;
	for (int i = 0; i < 8001; i++) {
		medianCount += array[i];
		if (medianCount >= N / 2 + 1) {
			medianIndex = i - 4000;
			break;
		}
	}
	median = medianIndex;

	int frequentIndex = 0, frequentCount = 0;
	for (int i = 0; i < 8001; i++) {
		if (frequentCount < array[i]) {
			frequentCount = array[i];
		}
	}
	int equalFrequentCount = 0;
	for (int i = 0; i < 8001; i++) {
		if (array[i] == frequentCount) {
			equalFrequentCount++;
			frequentIndex = i;
		}
		if (equalFrequentCount == 2) {
			frequent = i - 4000;
			break;
		}
	}
	if (equalFrequentCount == 1)
		frequent = frequentIndex - 4000;

	int minimum = 0, maximum = 0;
	for (int i = 0; i < 8001; i++) {
		if (array[i] != 0)
			maximum = i;
	}
	for (int i = 8000; i >= 0; i--) {
		if (array[i] != 0)
			minimum = i;
	}
	domain = maximum - minimum;

	cout << average << endl << median << endl << frequent << endl << domain << endl;

	return 0;
}