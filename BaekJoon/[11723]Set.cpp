#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Set {
public:
	vector<int> box;
	void add(int input);
	void remove(int input);
	int check(int input);
	void toggle(int input);
	void all();
	void empty();
};
int getOperand(string command) {
	int start = command.find(' ') + 1;
	int end = command.find('\0') - 1;
	int input = atoi(command.substr(start, end).c_str());
	return input;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Set box;
	string command;
	int count;
	cin >> count;
	cin.ignore();
	for (int i = 0; i < count; i++) {
		getline(cin, command);
		if (command.find("add") != string::npos) {
			box.add(getOperand(command));
		}else if (command.find("remove") != string::npos) {
			box.remove(getOperand(command));
		}else if (command.find("check") != string::npos) {
			if (box.check(getOperand(command)) > -1)	cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if (command.find("toggle") != string::npos) {
			box.toggle(getOperand(command));
		}else if (command.find("all") != string::npos) {
			box.all();
		}else if (command.find("empty") != string::npos) {
			box.empty();
		}
	}
	return 0;
}

void Set::add(int input) {
	int maxIndex = box.size();
	for (int i = 0; i < maxIndex + 1; i++) {
		if (i == box.size() || box[i] > input) {
			box.insert(box.begin() + i, input);
		}else if (box[i] < input)
			continue;
		else
			break;
	}
}
void Set::remove(int input) {
	int index = check(input);
	if (index > -1)
		box.erase(box.begin() + index);
}
int Set::check(int input) {
	for (int i = 0; i < box.size(); i++) {
		if (box[i] == input)
			return i;
	}
	return -1;
}
void Set::toggle(int input) {
	int index = check(input);
	if (index > -1)
		remove(input);
	else
		add(input);
}
void Set::all() {
	box.clear();
	for (int i = 0; i < 20; i++) {
		box.push_back(i+1);
	}
}
void Set::empty() {
	box.clear();
}