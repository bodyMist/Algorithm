#include<iostream>
#include<algorithm>
using namespace std;

int list[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(list, list + 10000, -1);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int rightIndex = 0, leftIndex = 0;
	int sum = 0, count = 0;

	while(leftIndex < N){
		if (sum < M) {
			sum += list[rightIndex++];
		}
		else if (sum >= M) {
			sum -= list[leftIndex++];
		}
		if(sum ==M) {
			count++;
		}
	}
	cout << count;
	return 0;
}