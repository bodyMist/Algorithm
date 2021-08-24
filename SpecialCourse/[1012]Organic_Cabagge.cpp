#include<iostream>
#include<queue>
using namespace std;

int list[51][51] = { 0, };
int moveY[4] = { -1,1,0,0 };
int moveX[4] = { 0,0,-1,1 };
queue<pair<int,int>> Q;
void BFS(int x, int y, int W, int H) {
	Q.push(pair<int,int>(x,y));
	list[x][y] = 0;
	while (!Q.empty()) {
		pair<int, int> current = Q.front();
		int x = current.first;
		int y = current.second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + moveY[i];
			int nx = x + moveX[i];
			if (nx < 0 || ny < 0 || nx > H || ny > W)	continue;
			if (list[nx][ny] == 1) {
				list[nx][ny] = 0;
				Q.push(pair<int, int>(nx, ny));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, M, N, K, A, B, count = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		count = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> A >> B;
			list[B][A] = 1;
		}
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (list[x][y] == 1) {
					BFS(x, y, M, N);
					count++;
				}
			}
		}
		cout << count << "\n";
	}
}