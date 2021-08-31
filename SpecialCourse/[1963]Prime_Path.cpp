#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

bool result[10000];
int primeList[10000];
int listSize = 0;
void getPrime(int N) {
	result[0] = false;
	result[1] = false;
	int index;
	for (int i = 1; i <= 1000; i++) {
		if (result[i] == true) {
			index = i * i;
			while (index <= 10000) {
				result[index] = false;
				index += i;
			}
		}
	}
	index = 0;
	for (int i = 2; i <= 10000; i++) {
		if (result[i] == true)
			primeList[index++] = i;
	}
	listSize = index;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(result, result + 10000, true);
	int T, A, B, result = 0;
	char firstInput[5], secondInput[5], temp[5];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		strcpy(firstInput, to_string(A).c_str());
		strcpy(secondInput, to_string(B).c_str());
		strcpy(temp, firstInput);
	

		
			
	}
	return 0;
}