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
			// '+'�����ڰ� �Էµ� ��
			// ������ ���ÿ� push
			oper.push(sentence[index]);
		}
		else if (sentence[index] == '-') {
			// '-'�����ڰ� �Էµ� ��, ������ ������ ����ִٸ� push
			// ������ ���ÿ� '-'�� �ִٸ� ������ ������ ����
			// �ǿ����� ���ÿ��� ���� ������ ���� ��갪���� ����
			if (oper.empty())	oper.push(sentence[index]);
			else if(oper.top() == '-')

		}else if (48 <= word <= 57) {
			// ���ڰ� �Էµɶ� 
		}
			

	}

}