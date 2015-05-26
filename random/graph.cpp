/*  Written by: Richard Tien
 *  Note: Random Questions
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <limits>
#include <queue>

using namespace std;

class Vertex;

class Edge
{
  public:
    Vertex * origin;
    Vertex * dest;
    int distance;

    Edge(Vertex * o, Vertex * d, int dist)
    {
      origin = o;
      dest = d;
      distance = dist;
    }
};

class Vertex
{
  public:
    string name;
    vector<Edge*> adjList;
    bool visited;


    Vertex(string str)
    {
      name = str;
    }

    void addEdge(Vertex * v, int d)
    {
      adjList.push_back(new Edge(this,v,d));
    }
};


class Graph
{
  public:

    Graph()
    {
      cout << "\tCreating new graph" << endl;
    }

    void addVertex(string str)
    {
      v.push_back(new Vertex(str));
    }

        int size()
    {
      return v.size();
    }

    void DFS(int x)
    {
      for(int i = 0; i < this->size(); i++)
        v[i]->visited = false;
  
      queue<Vertex*> queue;
      queue.push(v[x]);

      v[x]->visited = true;
      //cout << v[x]->name << endl;

      while(!queue.empty())
      {
        Vertex * curr = queue.front();
        queue.pop();

        cout << curr->name << endl;

        for(int i = 0; i < curr->adjList.size(); i++)
        {
          if(!curr->adjList[i]->dest->visited)
          {
            //cout << curr->adjList[i]->dest->name << endl;
            curr->adjList[i]->dest->visited = true;
            queue.push(curr->adjList[i]->dest);
          }
        }
      }
    }



    vector<Vertex*> v;

};



int main()
{
  Graph * g = new Graph();

  cout << "****** Adding Vertex ******" << endl;
  g->addVertex("Oakland");            // 0
  g->addVertex("San Francisco");      // 1
  g->addVertex("San Jose");           // 2
  g->addVertex("Sacramento");         // 3
  g->addVertex("Los Angeles");        // 4
  g->addVertex("San Diego");          // 5
  g->addVertex("Lake Tahoe");         // 6
  g->addVertex("Las Vegas");          // 7
  
  for(int i = 0; i < g->size(); i++)
  {
    cout << g->v[i]->name << endl;
  }

  cout << "****** Adding Edges ******" << endl;

  g->v[0]->addEdge(g->v[1],12);    // Oak -> SF (12)
  g->v[0]->addEdge(g->v[2],40);    // Oak -> SJ (40)
  g->v[0]->addEdge(g->v[3],80);    // Oak -> Sac (80)
  g->v[0]->addEdge(g->v[4],370);   // Oak -> LA (370)
  g->v[4]->addEdge(g->v[5],100);   // LA -> SD (100)
  g->v[4]->addEdge(g->v[7],270);   // LA -> Las Vegas (270)
  g->v[3]->addEdge(g->v[6],110);   // Sac -> Lake Tahoe (110)
  g->v[2]->addEdge(g->v[5],460);   // SJ -> SD (460)
  g->v[6]->addEdge(g->v[7],100);   // Lake Tahoe -> Las Vegas (100)


  for(int i = 0; i < g->size(); i++)
  {
    for(int j = 0; j < g->v[i]->adjList.size();j++)
    {
        cout << g->v[i]->adjList[j]->origin->name << " to " 
             << g->v[i]->adjList[j]->dest->name << " (" 
             << g->v[i]->adjList[j]->distance << ")" << endl;
    }
  }
  
  cout << "****** Calling DFS ******" << endl;
  g->DFS(0);

  return 0;
}
