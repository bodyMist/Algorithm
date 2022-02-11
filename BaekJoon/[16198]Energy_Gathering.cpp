#include<iostream>
#include<vector>
using namespace std;

vector<int> list;

int recursive(vector<int> temp, int index) {
	if (index == 0 || index == temp.size()-1) return 0;
	int sum = 0, A = 0, B;
	sum += temp[index - 1] * temp[index + 1];
	temp.erase(temp.begin() + index);
	for (int i = 1; i < temp.size() - 1; i++) {
		B = recursive(temp, i);
		if (A < B) A = B;
	}
	sum += A;
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, input;
	cin >> N;
	vector<int> temp;
	int result = 0, current = 0;;
	for (int i = 0; i < N; i++) {
		cin >> input;
		list.push_back(input);
	}
	for (int i = 1; i < N - 1; i++) {
		temp = list;
		current = recursive(temp, i);
		if (result < current)
			result = current;			
	}
	cout << result;

	return 0;
}