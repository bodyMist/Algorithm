#include<iostream>
#include<queue>
using namespace std;

class Contestant {
public:
	int sequence;	// 1~N ��° ����
	int get = 0;	// ������� ���� ������ ����
	int need;		// �ʿ��� ������ ����
};

int main() {
	Contestant list[1000];
	queue<Contestant> line;
	int result[1000] = { 0, };
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		list[i].sequence = i;
		cin >> list[i].need;
		line.push(list[i]);
	}
	while (!line.empty()) {
		count++;
		Contestant temp = line.front();
		temp.get++;
		line.pop();
		if (temp.need > temp.get) {
			line.push(temp);
		}
		else
			result[temp.sequence] = count;
	}
	for (int i = 0; i < N; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}