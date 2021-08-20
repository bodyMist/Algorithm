#include<iostream>
using namespace std;
/*
*  ���� 1: result[i] = stairs[i] + result[i-1] i-1��°���� �ö����
*  ���� 2: result[i] = stairs[i] + result[i-2] i-2��°���� �ö����
*/
int result[2][300];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int stairs[300] = { 0, };
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stairs[i];
	}
	result[0][0] = stairs[0];
	result[0][1] = stairs[0] + stairs[1];
	result[1][0] = stairs[0];
	result[1][1] = stairs[1];
	for (int i = 1; i < N; i++) {
		// i��° ����� ����1�� �Ѵٸ� --> i-1��°�� ����2�� ���� ���ȴ�
		result[0][i] = stairs[i] + result[1][i - 1];
		// i��° ����� ����2�� �Ѵٸ� --> i-2��°�� ����1�� 2 ��� ����̹Ƿ� �ִ밪�� ����
		result[1][i] = stairs[i] + max(result[0][i - 2], result[1][i-2]);

	}
	cout << (result[0][N - 1] > result[1][N - 1] ? result[0][N - 1] : result[1][N - 1]);
	return 0;
}