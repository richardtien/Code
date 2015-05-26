#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
using namespace std;

class Vertex;

class Edge
{
  public:
    Edge(Vertex * a, Vertex * b)
    {
      origin = a;
      destination = b;
    }

    Vertex * getOrigin() { return origin; }
    Vertex * getDestination() { return destination; }

  private:
    Vertex * origin;
    Vertex * destination;
};

class Vertex
{
  public:
    Vertex(string s)
    {
      name = s;
    }

    void addEdge(Vertex * v)
    {
      Edge * e = new Edge(this,v);
      adjList.push_back(e);
    }

    string getName() { return name; }
    vector<Edge *> getAdjList() { return adjList; }
    
    bool visited;


  private:
    string name;
    vector<Edge *> adjList;

};

class Graph
{
  public:
    Graph() { }
    void add(Vertex * v)
    {
      vertices.push_back(v);
    }

    vector<Vertex *> getVertices() { return vertices; }

  private:
    vector<Vertex *> vertices;
};

// Chapter 4.2
bool search(Graph * g, Vertex * start, Vertex * end)
{
  // USING BFS
  vector<Vertex *> vertices = g->getVertices();
  for(int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }
  
  queue<Vertex *> q;

  start->visited = true;

  q.push(start);
  
  Vertex * temp;

  while(!q.empty())
  {
    temp = q.front();
    q.pop();

    if(temp)
    {
      for(int i = 0; i < temp->getAdjList().size(); i++)
      {
        if(!temp->getAdjList()[i]->getDestination()->visited)
        {
          if(temp->getAdjList()[i]->getDestination() == end)
          {
            return true;
          }
          else
          {
            temp->getAdjList()[i]->getDestination()->visited = true;
            q.push(temp->getAdjList()[i]->getDestination());
          }
        }
      }
    }


  }
  

  return false;
}

int main()
{

  Vertex * a = new Vertex("1");
  Vertex * b = new Vertex("2");
  Vertex * c = new Vertex("3");
  Vertex * d = new Vertex("4");
  Vertex * e = new Vertex("5");
  Vertex * f = new Vertex("6");
  Vertex * g = new Vertex("7");
  Vertex * h = new Vertex("8");
  Vertex * i = new Vertex("9");
  Vertex * j = new Vertex("10");
  Vertex * k = new Vertex("11");
  Vertex * l = new Vertex("12");
  Vertex * m = new Vertex("13");
  Vertex * n = new Vertex("14");
  Vertex * o = new Vertex("15");
  Vertex * p = new Vertex("16");


  a->addEdge(b);
  a->addEdge(c);

  b->addEdge(d);
  b->addEdge(e);
  
  c->addEdge(f);
  c->addEdge(g);

  d->addEdge(h);
  d->addEdge(i);

  e->addEdge(j);
  e->addEdge(k);

  f->addEdge(l);
  f->addEdge(m);

  g->addEdge(n);
  g->addEdge(o);

  Graph * graph = new Graph();

  graph->add(a);
  graph->add(b);
  graph->add(c);
  graph->add(d);
  graph->add(e);
  graph->add(f);
  graph->add(g);
  graph->add(h);
  graph->add(i);
  graph->add(j);
  graph->add(k);
  graph->add(l);
  graph->add(m);
  graph->add(n);
  graph->add(o);
  graph->add(p);  // not connected vertex


  if(search(graph,a,o)) cout << "path" << endl;
  else cout << "no path" << endl;

  return 0;
}

