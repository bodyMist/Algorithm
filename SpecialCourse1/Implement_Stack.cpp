#include<iostream>
using namespace std;

class Stack {
private:
	int* list;
	int cursor;
public:
	Stack(int size) { 
		list = new int(size);
		cursor = -1;
	}
	void push(int input) {
		cursor++;
		list[cursor] = input;
	}
	int pop() {
		int result = list[cursor--];
		return result;
	}
	bool isEmpty() {
		return cursor == -1 ? true : false;
	}
	int size() {
		return cursor + 1;
	}
	int top() {
		return list[cursor];
	}
};

int main() {
	Stack s(10);
	s.push(5);
	s.push(3);
	s.push(9);
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	s.push(7);
	s.push(2);
	s.push(8);
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	return 0;
}