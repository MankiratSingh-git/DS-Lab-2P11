#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
  int V;
  list<int> *l;
  
  public:
  Graph(int v){
    V = v;
    l = new list<int> [v];
  }

  void addEdge(int u, int v){
    if(u >= V || v >= V) return;
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void printAdjList(){
    for(int i = 0 ; i < V ; i++){
      cout << i << " : ";
      for(int neigh : l[i]){
        cout << neigh << " ";
      }
      cout << endl;
    }
  }

  void bfs(){
    vector<bool> vis(V, false);
    queue<int> Q;
    vis[0] = true;
    Q.push(0);

    while(Q.size() > 0){
      int u = Q.front();
      Q.pop();
      cout << u << " ";
      for(int v : l[u]){
        if(!vis[v]){
          vis[v] = true;
          Q.push(v);
        }
      }
    }
    cout << endl;
  }

  void dfsHelper(int u, vector<bool> &vis){
    cout << u << " ";
    vis[u] = true;

    for(int v : l[u]){
      if(!vis[v]){
        dfsHelper(v, vis);
      }
    }
  }
  void dfs(){
    vector<bool> vis(V, false);
    for(int i = 0 ; i < V ; i++) if(!vis[i]) dfsHelper(i, vis);
    cout << endl;
  }
};

int main(){
  Graph G(5);
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(1,3);
  G.addEdge(2,4);
  G.printAdjList();
  G.bfs();
  G.dfs();
  return 0;
}