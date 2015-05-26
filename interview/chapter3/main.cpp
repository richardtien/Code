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

// Stack
class List
{
  public:
    int data;
    List * next;

    List(int d)
    {
      data = d;
      next = NULL;
    }
};

// Chapter 3.1 - Using a single array to implement three stacks

// Chapter 3.2 - Extend stack so that can find min at O(1)

// Chapter 3.3 - 

// Chapter 3.4 - 

// Chapter 3.5 -
class MyQueue
{
  public:
    stack<int> newest;
    stack<int> oldest;
  
    MyQueue() { }
  
    int size()
    {
      return newest.size() + oldest.size();
    }

    void add(int value)
    {
      newest.push(value);
    }

    int peek()
    {
      shiftStacks();
      return oldest.top();
    }

    int remove()
    {
      shiftStacks();
      
      int top = oldest.top();
      oldest.pop();
      return top;
    }

    void shiftStacks()
    {
      if(oldest.empty())
      {
        int temp;
        while(!newest.empty())
        {
          temp = newest.top();
          oldest.push(temp);
          newest.pop();
        }
      }
    }

};

// Chapter 3.6 -
stack<int> sort(stack<int> stk)
{
  stack<int> result;

  while(!stk.empty())
  {
    int temp = stk.top();
    stk.pop();
    while(!result.empty() && result.top() > temp)
    {
      stk.push(result.top());
      result.pop();
    }
    stk.push(temp);
  }
 
  return result;
}

// Chapter 3.7 -

int main()
{

  // Chapter 3.1 Tester

  // Chapter 3.2 Tester

  // Chapter 3.3 Tester

  // Chapter 3.4 Tester

  // Chapter 3.5 Tester

  // Chapter 3.6 Tester

  // Chapter 3.7 Tester

/*
  vector<int> f;
  vector<int> g;
  vector<int> h;
  vector<int> i;
  vector<int> j;
  vector<vector<int> > k;

  f.push_back(1);  f.push_back(2);  f.push_back(3);  f.push_back(4);
  g.push_back(5);  g.push_back(6);  g.push_back(7);  g.push_back(8);
  h.push_back(9);  h.push_back(10);  h.push_back(11);  h.push_back(12);
  i.push_back(13);  i.push_back(14);  i.push_back(15);  i.push_back(16);
  j.push_back(17);  j.push_back(18);  j.push_back(19);  j.push_back(20);
  k.push_back(f);  k.push_back(g);  k.push_back(i);  k.push_back(j);
*/


  return 0;
}

