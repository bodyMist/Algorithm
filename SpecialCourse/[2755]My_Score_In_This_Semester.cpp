#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int N, index, grade,  gradeSum = 0;
	double resultSum = 0, achieve = 0;
	char score[3];
	cin >> N;
	string input;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		index = 0;
		achieve = 0;
		getline(cin, input);
		index = input.find(' ');
		grade = atoi(input.substr(index+1).c_str());
		index = input.find(' ', index + 1);
		strcpy(score, input.substr(index + 1).c_str());
		if (score[0] == 'A')	achieve = 4;
		else if (score[0] == 'B') achieve = 3;
		else if (score[0] == 'C') achieve = 2;
		else if (score[0] == 'D') achieve = 1;
		else if (score[0] == 'F') achieve = 0;
		if (score[1] == '+') achieve += 0.3;
		else if (score[1] == '-') achieve -= 0.3;
		gradeSum += grade;
		resultSum += achieve * grade;
	}
	double result = round(resultSum / gradeSum * 100) / 100.00;
	cout << fixed;
	cout.precision(2);
	cout << result;
	return 0;
}