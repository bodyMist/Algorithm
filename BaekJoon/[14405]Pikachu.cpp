#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char sentence[6000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool result = true;
	string input;
	getline(cin, input);
	strcpy(sentence, input.c_str());
	int length = input.length();
	for (int i = 0; i < length; i++) {
		if (sentence[i] == 'p' && sentence[i + 1] == 'i')
			i++;
		else if (sentence[i] == 'k' && sentence[i + 1] == 'a')
			i++;
		else if (sentence[i] == 'c' && sentence[i + 1] == 'h' && sentence[i + 2] == 'u')
			i += 2;
		else {
			result = false;
			break;
		}
	}
	if (result)	cout << "YES";
	else cout << "NO";
	return 0;
}