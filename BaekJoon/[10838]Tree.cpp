#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

// tuple<int,int,int> -> parent, weight, depth
vector<pair<int, int>> tree(500100);
set<int> weight;
int check[200000];
int checkCount;

int getCommonParent(int a, int b) {
	int count = 0;
	if (a == b) return a;

	checkCount++;
	while (count <=1000) {
		if (a != 0) {
			if (check[a] == checkCount) {
				return a;
			}
			check[a] = checkCount;
			a = tree[a].first;
		}
		if (b != 0) {
			if (check[b] == checkCount) {
				return b;
			}
			check[b] = checkCount;
			b = tree[b].first;
		}
		count++;
	}
	return 0;
}

// a노드와 b노드의 최단경로 상의 모든 가중치 c로 수정
void paint(int a, int b, int c) {
	int commonParent = getCommonParent(a, b);
	while (a != commonParent) {
		tree[a].second = c;
		a = tree[a].first;
	}
	while (b != commonParent) {
		tree[b].second = c;
		b = tree[b].first;
	}
}

// a 노드의 부모 노드를 b로 바꾼다. b는 a의 자식에 속하지 않는다(서로를 부모로 가리키지 않음)
// a의 원래 부모가 p일때, new edge(a,b)는 edge(a,p)의 가중치를 갖는다
void move(int a, int b) {
	tree[a].first = b;
}

// a노드와 b 노드의 최단경로 사이의 서로 다른 가중치 개수를 출력
void count(int a, int b) {
	int commonParent = getCommonParent(a, b);
	while (a != commonParent) {
		weight.insert(tree[a].second);
		a = tree[a].first;
	}
	while (b != commonParent) {
		weight.insert(tree[b].second);
		b = tree[b].first;
	}
	cout << weight.size() << "\n";
	weight.clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;

	// <parent, weight>
	for (int i = 0; i < N; i++) {
		tree[i] = make_pair<int, int>(0, 0);
	}
	int r, a, b, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> a >> b;
		if (r == 1) {
			cin >> c;
			paint(a, b, c);
		}
		else if (r == 2) {
			move(a, b);
		}
		else if (r == 3) {
			count(a, b);
		}
	}
	return 0;
}