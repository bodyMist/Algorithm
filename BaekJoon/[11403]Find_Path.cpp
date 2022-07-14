#include<iostream>
#include<stack>
using namespace std;

int adjacentArray[100][100];
int visit[100];
int result[100][100];
stack<int> s;

void dfs(int v){

}


int main(){
  int vertexCount;
  cin >> vertexCount;
  for(int i = 0; i < vertexCount; i++){
    for(int j =0; j < vertexCount; j++){
      cin >> adjacentArray[i][j];
    }
  }
  for(int i =0; i < vertexCount; i++){
    dfs(i);
    
  }
  return 0;
}