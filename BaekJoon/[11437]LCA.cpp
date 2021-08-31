#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> input(51000);
vector<int> tree(51000);
// �ش� ����� ���̸� ��ȯ
int getDepth(int value) {
	int depth = 1;
	int current = value;
	while (current != 1) {
		current = tree[current];
		depth++;
	}
	return depth;
}
// �ش� ��� �������� ��ǥ ������ �θ� ��带 ��ȯ
int getNode(int depth, int value, int targetDepth) {
	while (depth != targetDepth) {
		value = tree[value];
		depth--;
	}
	return value;
}
// �� ����� ���� �θ� ��ȯ
int getCommonParent(int first, int second) {
	while (first != second) {
		first = tree[first];
		second = tree[second];
	}
	return first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> Q;
	int N, parent, child;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> parent >> child;
		input[child].push_back(parent);
		input[parent].push_back(child);
	}

	// 1(��Ʈ)�� ����� ����� �θ� ����
	for (int i = 0; i < input[1].size(); i++) {
		child = input[1][i];
		tree[child] = 1;
		Q.push(child);
	}
	int current;
	// 1(��Ʈ)�� ����� ������ Ž���ϸ鼭 �θ� ��� ����
	while (!Q.empty()) {
		current = Q.front();
		parent = tree[current];
		Q.pop();
		for (int j = 0; j < input[current].size(); j++) {
			child = input[current][j];
			if (child == parent) continue;
			tree[child] = current;
			Q.push(child);
		}
	}

	int M, first, second;
	int firstDepth, secondDepth;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		firstDepth = getDepth(first);
		secondDepth = getDepth(second);
		if (firstDepth > secondDepth) {
			first = getNode(firstDepth, first, secondDepth);
		}
		else {
			second = getNode(secondDepth, second, firstDepth);
		}
		cout << getCommonParent(first, second) << "\n";
	}
	return 0;
}