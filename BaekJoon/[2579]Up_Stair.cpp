#include<iostream>
using namespace std;
/*
*  패턴 1: result[i] = stairs[i] + result[i-1] i-1번째에서 올라오기
*  패턴 2: result[i] = stairs[i] + result[i-2] i-2번째에서 올라오기
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
		// i번째 계단을 패턴1로 한다면 --> i-1번째는 패턴2의 값이 허용된다
		result[0][i] = stairs[i] + result[1][i - 1];
		// i번째 계단을 패턴2로 한다면 --> i-2번째는 패턴1과 2 모두 허용이므로 최대값을 대입
		result[1][i] = stairs[i] + max(result[0][i - 2], result[1][i-2]);

	}
	cout << (result[0][N - 1] > result[1][N - 1] ? result[0][N - 1] : result[1][N - 1]);
	return 0;
}