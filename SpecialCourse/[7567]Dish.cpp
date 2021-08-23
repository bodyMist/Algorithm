#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	char dish[51];
	getline(cin, input);
	strcpy(dish, input.c_str());
	int length = input.length();
	int result = 10;
	for (int i = 0; i < length; i++) {
		if (i == 0)
			continue;
		if (dish[i - 1] == dish[i])
			result += 5;
		else
			result += 10;
	}
	cout << result;
	return 0;
}