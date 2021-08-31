#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

int HASH_MOD[4] = { 69777, 79777, 89787, 99777 };
int HASH_POW[4] = { 313, 419, 619, 797 };
int HASH_PRIOR[4] = { 1,1,1,1 };
int hashSum[4] = { 0,0,0,0 };
int result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, string>> hashmap;
	string S, S1;
	string K;
	cin >> S >> K;

	// 문자열에서 숫자 제거
	for (int i = 0; i < S.length(); i++) {
		if (isdigit(S[i]) == 0) {
			S1 += S[i];
		}
	}
	int fixedLength = K.length();
	string temp;

	for (int t = 0; t < 4; t++) {
		// 뒤에서부터 K길이 만큼의 문자열 해시 구하기
		for (int i = 0; i < fixedLength; i++) {
			hashSum[t] *= HASH_POW[t];
			hashSum[t] += (int)S1[i];
			hashSum[t] %= HASH_MOD[t];
			HASH_PRIOR[t] *= HASH_POW[t];
			HASH_PRIOR[t] %= HASH_MOD[t];
		}
		temp = S1.substr(0, fixedLength);
		hashmap.push_back(pair<int, string>(hashSum[t], temp));
		//cout << temp << " " << hashSum[t] << endl;


		for (int i = fixedLength; i < S1.length(); i++) {
			hashSum[t] *= HASH_POW[t];
			hashSum[t] -= ((int)S1[i - fixedLength] * HASH_PRIOR[t]) % HASH_MOD[t];
			hashSum[t] += (int)S1[i];
			hashSum[t] += HASH_MOD[t];
			hashSum[t] %= HASH_MOD[t];
			temp = S1.substr(i - fixedLength + 1, fixedLength);
			hashmap.push_back(pair<int, string>(hashSum[t], temp));
			//cout << temp << " " << hashSum[t] << endl;
		}
		// K에 대한 해시 계산하기
		int Khash = 0;
		int KhashPrior = 1;
		for (int i = 0; i < fixedLength; i++) {
			Khash *= HASH_POW[t];
			Khash += (int)K[i];
			Khash %= HASH_MOD[t];
			KhashPrior *= HASH_POW[t];
			KhashPrior %= HASH_MOD[t];
		}
		//cout << Khash << endl;

		// K의 해시값으로 검색
		for (int i = 0; i < hashmap.size(); i++) {
			if (hashmap[i].first == Khash)
				result++;
		}
	}
	if (result >= 4) cout << 1;
	else cout << 0;
	return 0;
}