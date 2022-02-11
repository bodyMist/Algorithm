#include <iostream>
using namespace std;

long long list[10000000];
void setData(long long index, long long value) {
	value = value - list[index];
	while (index != 0) {
		list[index] += value;
		index /= 2;
	}
}
// section : 해당 index가 포함하는 범위, left&right : 우리가 필요로 하는 범위
long long segTree(long long index, long long sectionLeft, long long sectionRight, long long left, long long right) {
	// 적중 값 반환하기
	if (left <= sectionLeft && sectionRight <= right)	return list[index];
	// 필요한 범위 밖 예외처리
	if (sectionLeft > right)	return 0;
	if (sectionRight < left) return 0;


	long long value1 = segTree(index * 2, sectionLeft, (sectionLeft + sectionRight) / 2, left, right);
	long long value2 = segTree(index * 2 + 1, (sectionLeft + sectionRight) / 2 + 1, sectionRight, left, right);

	return value1 + value2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K, start = 1, temp;
	cin >> N >> M >> K;
	while (start < N) {
		start *= 2;
	}
	temp = start;
	long long data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		setData(temp++, data);
	}

	long long a, b, c, result = 0;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			setData(start + b-1, c);
		}
		else if (a == 2) {
			result = segTree(1, 0, start-1, b-1, c-1);
			cout << result<<"\n";
		}
	}
	return 0;
}