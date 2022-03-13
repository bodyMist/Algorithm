

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph(300001);
vector<int> cost(300001, 1000000);
vector<int> visit(300001);
queue<int> order;

void dijkstra(int startNode){
  order.push(startNode);
  int node;
  while(order.empty() == false){
    node = order.front();
    order.pop();

    if(visit[node] == 1)  continue;
    visit[node] = 1;

    int nodeCost = cost[node];

    for(int i = 0; i < graph[node].size(); i++){
      
      int nextNode = graph[node][i];
      int nextCost = cost[nextNode];
      if(nodeCost+1 < nextCost){
        order.push(graph[node][i]);
        cost[nextNode] = nodeCost+1;
      }
    }
  }
}

int main(){
  int N, M, K, X;
  cin >> N >> M >> K >> X;
  int A,B;
  for(int i = 0; i < M; i++){
    cin >> A >> B;
    graph[A].push_back(B);
  }
  cost[X] = 0;
  dijkstra(X);
  int result = 0;
  for(int i = 1; i <= N; i++){
    if(cost[i] == K){
      cout << i << endl;
      result++;
    }
  }
  if(result == 0)
    cout << -1;

  return 0;
}