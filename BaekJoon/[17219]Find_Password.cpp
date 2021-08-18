#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	cin.ignore();
	map<string, string> connection;
	string input, site, password;
	int splitIndex = 0;
	for (int i = 0; i < N; i++) {
		getline(cin, input);
		splitIndex = input.find(' ');
		site = input.substr(0, splitIndex);
		password = input.substr(splitIndex + 1, input.length());
		connection.insert(pair<string, string>(site, password));
	}
	for (int i = 0; i < M; i++) {
		getline(cin, input);
		map<string, string>::iterator it = connection.find(input);
		cout << it->second << "\n";
	}
	return 0;
}