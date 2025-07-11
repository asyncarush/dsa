#include<iostream>
using namespace std;

class Graph{
  private:
    vector<vector<int>> adjList;
  
  public:
    Graph(int size) {
      adjList.resize(size);
    }
    
    void addEdge(int s, int d) {
      this->adjList[s].push_back(d);
    }
};

int main() {
  Graph* g = new Graph(3);
  g->addEdge(0,1);
  g->addEdge(0,2);
  return 0;
}