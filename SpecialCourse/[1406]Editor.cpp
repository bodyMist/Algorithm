#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

char sentence[200000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> s1, s2;
	string input;
	int N, M, cursor;
	getline(cin, input);
	strcpy(sentence, input.c_str());
	N = input.length();
	cin >> M;
	char command, target;
	for (int i = 0; i < N; i++) {
		s1.push(sentence[i]);
	}
	for (int i = 0; i < M; i++) {
		cin >> command;
		if(command == 'P'){
			cin >> target;
			s1.push(target);
		}
		else if (command == 'L') {
			if (s1.empty())
				continue;
			s2.push(s1.top());
			s1.pop();
		}
		else if (command == 'D') {
			if (s2.empty())
				continue;
			s1.push(s2.top());
			s2.pop();
		}
		else if (command == 'B') {
			if (s1.empty())
				continue;
			s1.pop();
		}
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
	return 0;
}