#include<iostream>
#include<cmath>
using namespace std;

int square(int input) {
	return input * input;
}
int result = 5;
void solve(int input) {
	int sum = 0;
	for (int i = (int)sqrt(input); i > 0; i--) {
		sum += square(i);
		if (sum > input) {
			sum -= square(i);
			continue;
		}
		else if (sum == input) {
			result = 1;
		}
		for (int j = i; j > 0; j--) {
			sum += square(j);
			if (sum > input) {
				sum -= square(j);
				continue;
			}
			else if (sum == input) {
				result = result > 2 ? 2 : result;
			}
			for (int k = j; k > 0; k--) {
				sum += square(k);
				if (sum > input) {
					sum -= square(k);
					continue;
				}
				else if (sum == input) {
					result = result > 3 ? 3 : result;
				}
				for (int m = k; m > 0; m--) {
					sum += square(m);
					if (sum > input) {
						sum -= square(m);
						continue;
					}
					else if (sum == input)	result = result > 4 ? 4 : result;

					sum -= square(m);
				}
				sum -= square(k);
			}
			sum -= square(j);
		}
		sum -= square(i);
	}
}
int main() {
	int N;
	cin >> N;
	solve(N);
	cout << result;
	return 0;
}