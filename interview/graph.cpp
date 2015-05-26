#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Vertex
{
  public:
    int value;
    bool visited;
    vector<Vertex*> adjList;
    Vertex(int n) : value(n) { visited = false;}
    void addEdge(Vertex * v)    // directed first
    {
      adjList.push_back(v);
       v->adjList.push_back(this);

    }

    void addEdgeDirected(Vertex * v)
    {
       adjList.push_back(v);
       v->adjList.push_back(this);
    }
};

class Graph
{
  public:
    vector<Vertex*> vertices;
    Vertex * addVertex(int n)
    {
      Vertex * v = new Vertex(n);
      vertices.push_back(v);
      return v;
    }
    void resetVisited()
    {
      for(int i = 0; i < vertices.size(); i++) vertices[i]->visited = false;
    }
};

void graphBFS(Graph * g, Vertex * v)
{
  g->resetVisited();  // set all vertices to not visited
  queue<Vertex*> q;
  q.push(v);
  v->visited = true;
  int level = 1;
  int nextLevel = 0;

  while(!q.empty())
  {
    Vertex * vertex = q.front();
    q.pop();
    level--;
    cout << vertex->value << " ";
    for(int i = 0; i < vertex->adjList.size(); i++)
    {
      if(vertex->adjList[i]->visited == false) // only push vertex into queue if it hasnt been visited
      {
        vertex->adjList[i]->visited = true;   // set it to visited when push into queue
        q.push(vertex->adjList[i]);
        nextLevel++;
      }
    }

    if(level == 0)
    {
      cout << endl;
      level = nextLevel;
      nextLevel = 0;
    }
  }
}

Vertex * search(Graph * g, Vertex * v, int n)
{
  g->resetVisited();  // set all vertices to not visited
  queue<Vertex*> q;
  q.push(v);
  v->visited = true;
  int level = 1;
  int nextLevel = 0;

  while(!q.empty())
  {
    Vertex * vertex = q.front();
    q.pop();
    level--;
    if(vertex->value == n) return vertex;


    for(int i = 0; i < vertex->adjList.size(); i++)
    {
      if(vertex->adjList[i]->visited == false)      
      {
        vertex->adjList[i]->visited = true;        
        q.push(vertex->adjList[i]);
        nextLevel++;
      }
    }

    if(level == 0)
    {
      level = nextLevel;
      nextLevel = 0;
    }
  }
  return NULL;
}

void traversal(Graph * g, Vertex * v)
{
  if(!v) return;

  cout << v->value << " ";
  v->visited = true;
  for(int i = 0; i < v->adjList.size(); i++)
  {
    if(v->adjList[i]->visited == false)
      traversal(g,v->adjList[i]);
  }


}


int main()
{
  Graph * g = new Graph();
  for(int i = 1; i <= 16; i++) g->addVertex(i);

  g->vertices[7]->addEdge(g->vertices[3]);
  g->vertices[7]->addEdge(g->vertices[11]);

  g->vertices[3]->addEdge(g->vertices[1]);
  g->vertices[3]->addEdge(g->vertices[5]);

  g->vertices[11]->addEdge(g->vertices[9]);
  g->vertices[11]->addEdge(g->vertices[13]);

  g->vertices[1]->addEdge(g->vertices[0]);
  g->vertices[1]->addEdge(g->vertices[2]);

  g->vertices[5]->addEdge(g->vertices[4]);
  g->vertices[5]->addEdge(g->vertices[6]);

  g->vertices[9]->addEdge(g->vertices[8]);
  g->vertices[9]->addEdge(g->vertices[10]);

  g->vertices[13]->addEdge(g->vertices[12]);
  g->vertices[13]->addEdge(g->vertices[14]);

  g->vertices[0]->addEdge(g->vertices[15]);
  
  cout << "Graph BFS: " << endl;
  
  graphBFS(g,g->vertices[7]);
  cout << endl;

  cout << "Graph Traversal: " << endl;
  g->resetVisited();
  traversal(g,g->vertices[7]);
  cout << endl;

  cout << "Search : ";
  g->resetVisited();
  Vertex * result = search(g,g->vertices[7],13);
  if(result) cout << result->value << endl;
  else cout << "cannot find result." << endl;


  return 0;
}

