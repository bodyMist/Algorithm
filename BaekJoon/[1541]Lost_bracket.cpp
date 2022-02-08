#include<iostream>
#include<string>
#include<stack>
using namespace std;
char sentence[60];

int plus(int a, int b) {}

int main() {
	string input;
	char word;
	stack<char> oper;
	stack<int> operand;

	getline(cin, input);
	strcpy(sentence, input.c_str());
	int length = strlen(sentence);
	int index = 0, numberCount = 1, number = 0;

	while (sentence[index] != '\0') {
		if (sentence[index] == '+') {
			// '+'연산자가 입력될 때
			// 연산자 스택에 push
			oper.push(sentence[index]);
		}
		else if (sentence[index] == '-') {
			// '-'연산자가 입력될 때, 연산자 스택이 비어있다면 push
			// 연산자 스택에 '-'가 있다면 연산자 스택을 비우고
			// 피연산자 스택에서 값을 꺼내어 현재 계산값에서 빼기
			if (oper.empty())	oper.push(sentence[index]);
			else if(oper.top() == '-')

		}else if (48 <= word <= 57) {
			// 숫자가 입력될때 
		}
			

	}

}