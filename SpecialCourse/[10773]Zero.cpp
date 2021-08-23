#include<iostream>
using namespace std;
int list[2000000];
int cursor = -1;
void push(int input) {
	cursor++;
	list[cursor] = input;
}
bool isEmpty() {
	return cursor == -1;
}
void pop() {
	if (isEmpty()) return;
	else cursor--;
}
int size() {
	return cursor + 1;
}
int top() {
	return list[cursor];
}
int main() {
	int K;
	cin >> K;
	int input;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 0)	pop();
		else push(input);
	}
	int result = 0;
	for (int i = 0; i < size(); i++) {
		result += list[i];
	}
	cout << result;
	return 0;
}