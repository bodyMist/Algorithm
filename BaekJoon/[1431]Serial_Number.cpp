#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int compareT(string a, string b);
int compareLength(string a, string b);
int compareSum(string a, string b);
int compareDict(string a, string b);

struct compare{
  bool operator()(string a, string b){
    int result = compareT(a, b);
    if(result == 1) return false;
    else return true;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<string,vector<string>, compare> pq;
  int N;
  cin >> N;
  cin.ignore();
  string input;
  for(int i = 0; i < N; i++){
    getline(cin, input);
    pq.push(input);
  }
  for(int i = 0; i < N; i++){
    cout << pq.top() << endl;
    pq.pop();
  }
  return 0;
}



int compareT(string a, string b){
  int result = compareLength(a, b);
  if(result == 1) return 1;
  else if(result == 2) return 2;
  else{
    result = compareSum(a, b);
    if(result == 1) return 1;
    else if(result == 2) return 2;
    else{
      result = compareDict(a, b);
      if(result == 1) return 1;
      else if(result == 2) return 2;
      else return -1;
    }
  }
}
int compareLength(string a, string b){
  if (a.length() < b.length())
    return 1;
  else if(a.length() > b.length())
    return 2;
  else if(a.length() == b.length())
    return 3;
  return -1;
}
int compareSum(string a, string b){
  char listA[51];
  char listB[51];
  strcpy(listA, a.c_str());
  strcpy(listB, b.c_str());
  int length = a.length();
  int sumA = 0, sumB = 0;
  for(int i = 0; i < length; i++){
    if(isdigit(listA[i]) != 0){
      sumA += listA[i] - '0';
    }
    if(isdigit(listB[i]) != 0){
      sumB += listB[i] - '0';
    }
  }
  if(sumA < sumB) return 1;
  else if(sumA > sumB) return 2;
  else return 3;
}
int compareDict(string a, string b){
  const char* listA = a.c_str();
  const char* listB = b.c_str();
  int length = a.length();
  for(int i = 0; i < length; i++){
    if(listA[i] < listB[i]) return 1;
    else if(listA[i] > listB[i]) return 2;
  }
  return -1;
}
