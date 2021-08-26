#include<iostream>
#include<set>
using namespace std;

set<int> numbers;
int N, A, B, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		numbers.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A;
			numbers.insert(A);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> B;
			if (numbers.find(B) == numbers.end())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
	}
	return 0;
}