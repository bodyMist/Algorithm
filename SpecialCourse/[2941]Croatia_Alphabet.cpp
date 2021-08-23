#include<iostream>
#include<cstring>
#include<string>
using namespace std;

char alphabet[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	getline(cin, input);
	strcpy(alphabet, input.c_str());
	int length = input.length();
	int result = 0;
	for (int i = 0; i < length; i++) {
		if (alphabet[i] == 'c' && alphabet[i + 1] == '=') {
			result++;
			i++;
		}
		else if (alphabet[i] == 'c' && alphabet[i + 1] == '-') {
			result++;
			i++;
		}
		else if (alphabet[i] == 'd' && alphabet[i + 1] == 'z' && alphabet[i + 2] == '=') {
			result++;
			i += 2;
		}
		else if (alphabet[i] == 'd' && alphabet[i + 1] == '-') {
			result++;
			i++;
		}
		else if (alphabet[i] == 'l' && alphabet[i+1] == 'j') {
			result++;
			i++;
		}
		else if (alphabet[i] == 'n' && alphabet[i + 1] == 'j') {
			result++;
			i++;
		}
		else if (alphabet[i] == 's' && alphabet[i + 1] == '=') {
			result++;
			i++;
		}
		else if (alphabet[i] == 'z' && alphabet[i + 1] == '=') {
			result++;
			i++;
		}
		else {
			result++;
		}
	}
	cout << result;
	return 0;
}