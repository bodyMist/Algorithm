#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Trie{
  public:
    bool isEnd;
    Trie *phone[20];
    void insert(char* input);
    bool find(char* target);
    Trie(){
      for(int i = 0; i < 20; i++){
        isEnd = false;
        phone[i] = NULL;
      }
    }
};

void Trie::insert(char* input){
  if(*input == NULL){
    this->isEnd = true;
    return;
  }
  int current = *input - '0';
  if(phone[current] == NULL){
    phone[current] = new Trie();
  }
  phone[current]->insert(input+1);
}

bool Trie::find(char* target){
  if(*target == NULL){
    for(int p = 0; p < 10; p++){
      if(phone[p] != NULL)
        return true;
    }
    if(isEnd) return false;
    return true;
  }
  int current = *target - '0';
  if(phone[current] == NULL)
    return false;
  return phone[current]->find(target+1);
}


int main(){
  int testcase;
  cin >> testcase;
  Trie trie[100];
  for(int t = 0; t < testcase; t++){
    int N;
    cin >> N;
    trie[t] = Trie();
    vector<string> store;
    for(int j = 0; j < N; j++){
      string input;
      cin >> input;
      store.push_back(input);
      trie[t].insert(&*input.begin());
    }
    for(int i = 0; i < N; i++){
      if(trie[t].find(&*store[i].begin())){
        cout << "NO" << endl;
        break;
      }
      if(i == N-1){
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}