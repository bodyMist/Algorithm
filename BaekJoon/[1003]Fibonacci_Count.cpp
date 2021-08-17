#include<iostream>
using namespace std;

int zeroCount = 0;
int oneCount = 0;
int memoization[41][2] = { {1,0},{0,1} };

void fibonacci(int x) {
    memoization[x][0] = memoization[x - 1][0] + memoization[x - 2][0];
    memoization[x][1] = memoization[x - 1][1] + memoization[x - 2][1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    for (int i = 2; i < 41; i++) {
        fibonacci(i);
    }
    for (int i = 0; i < T; i++) {
        zeroCount = 0;
        oneCount = 0;
        cin >> N;
        cout << memoization[N][0] << " " << memoization[N][1] << "\n";
    }
    return 0;
}