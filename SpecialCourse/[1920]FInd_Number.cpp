#include<iostream>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> numbers;
	int N, A, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		numbers.insert(A);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> A;
		if (numbers.find(A) == numbers.end())
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}