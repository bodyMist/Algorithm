#include<iostream>
using namespace std;

int list[200][200];
int route[200][200];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}
	int current;
	route[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			current = list[i][j];
			if (i + current <= N && j + current <= N) {
				route[i + current][j] = route[i][j]*2;
				route[i][j + current] = route[i][j]*2;
			}
			else if (i + current <= N) {
					route[i + current][j] = route[i][j];
			}
			else if (j + current <= N) {
					route[i][j + current] = route[i][j];
			}
		}
	}
	cout << route[N][N];
	return 0;
}