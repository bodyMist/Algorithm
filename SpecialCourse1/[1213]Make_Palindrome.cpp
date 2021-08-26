#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char sentence[100];
char kind[40] = { 0, };	//65 A ~ 90 Z => 0~35
int main() {
	string input;
	getline(cin, input);
	strcpy(sentence, input.c_str());
	int length = input.length();
	int index, failCount = 0;

	for (int i = 0; i < length; i++) {
		index = sentence[i] - 65;
		kind[index]++;
	}
	for (int i = 0; i < 35; i++) {
		if (kind[i] % 2 != 0) {
			failCount++;
		}
		if (failCount > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
	for (int i = 0; i < 35; i++) {
		int count = kind[i] / 2;
		for (int j = 0; j < count; j++) {
			cout << (char)(i + 65);
		}
	}
	for (int i = 0; i < 35; i++) {
		if (kind[i]%2 == 1)
			cout << (char)(i + 65);
	}
	for (int i = 35; i >= 0; i--) {
		int count = kind[i] / 2;
		for (int j = 0; j < count; j++) {
			cout << (char)(i + 65);
		}
	}
	return 0;
}