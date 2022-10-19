#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int N;
string K;

// SubTask1
int solve1() {
  int KK;
  int index = 0;
  for (int i = K.length() - 1; i >= 0; i--) {
    KK += (K[i] - '0') * pow(2, index);
    index++;
  }
  int count = 0;
  while (KK != 0) {
    int bitwiseNot, addition, minus, bitwiseAnd;

    bitwiseNot = ~KK;
    addition = bitwiseNot + 1;
    bitwiseAnd = KK & addition;
    minus = KK - bitwiseAnd;

    KK = minus;
    count++;
  }
  return count;
}

// SubTask2
string bitnot(string KK) {
  string bitwiseNot(KK);
  for (int i = 0; i < KK.length(); i++) {
    int temp = KK[i] - '0';
    bitwiseNot[i] = !temp + '0';
  }
  return bitwiseNot;
}
string add(string bitwiseNot) {
  int carry = 0;
  bitwiseNot[bitwiseNot.length() - 1] += 1;
  for (int i = bitwiseNot.length() - 1; i >= 0; i--) {
    bitwiseNot[i] += carry;
    if (bitwiseNot[i] > '1') {
      bitwiseNot[i] = '0';
      carry = 1;
    } else {
      carry = 0;
    }
  }
  if (carry == 1) {
    bitwiseNot.insert(bitwiseNot.begin(), carry + '0');
  }
  return bitwiseNot;
}
string bitandOper(string KK, string addition) {
  int K_SIZE = KK.length();
  int A_SIZE = addition.length();
  if (K_SIZE > A_SIZE) {
    while (K_SIZE == addition.length()) {
      addition.insert(addition.begin(), '0');
    }
  } else if (K_SIZE < A_SIZE) {
    while (A_SIZE == addition.length()) {
      KK.insert(KK.begin(), '0');
    }
  }
  string andResult;
  for (int i = 0; i < addition.length(); i++) {
    int a = KK[i] - '0';
    int b = addition[i] - '0';
    int result = a & b;
    andResult.push_back((a & b) + '0');
  }
  return andResult;
}

string subtraction(string KK, string andResult) {
  const int K_SIZE = KK.length();
  const int A_SIZE = andResult.length();
  if (K_SIZE > A_SIZE) {
    while (K_SIZE == andResult.length()) {
      andResult.insert(andResult.begin(), '0');
    }
  } else if (K_SIZE < A_SIZE) {
    while (A_SIZE == andResult.length()) {
      KK.insert(KK.begin(), '0');
    }
  }
  string minus;
  int carry = 0;
  for (int i = andResult.length() - 1; i >= 0; i--) {
    int a = KK[i] - '0';
    int b = andResult[i] - '0';
    a -= carry;
    int result = a - b;
    if (result < 0) {
      carry = 1;
      result += 2;
    } else {
      carry = 0;
    }
    minus.insert(minus.begin(), result + '0');
  }
  if (carry == 1) minus.insert(minus.begin(), '2');
  return minus;
}

int solve2() {
  int count = 0;
  bool check = true;
  while (check) {
    string bitwiseNot = bitnot(K);
    string addition = add(bitwiseNot);

    string bitwiseAnd = bitandOper(K, addition);
    string minus = subtraction(K, bitwiseAnd);
    K = minus;
    // 0 check
    check = false;
    for (int i = 0; i < N; i++) {
      if (K[i] == '1') check = true;
    }
    count++;
  }
  return count;
}
// Submask2 -- another
int solve3() {
  int count = 0;
  for (char t : K) {
    if (t == '1') count++;
  }
  return count;
}
int main() {
  cin >> N;
  cin.ignore();
  getline(cin, K);
  cout << solve3();

  return 0;
}