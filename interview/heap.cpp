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


int parent(int n)
{
  return (n-1)/2;
}

int left(int n)
{
  return (n*2) + 1;
}

int right(int n)
{
  return (n*2) + 2;
}

class MaxHeap
{
  public:
    vector<int> heap;

    MaxHeap() { }

    int size() { return heap.size(); };

    void add(int n) // bubble up
    {
      heap.push_back(n);
      int curr = size()-1;
      while(heap[parent(curr)] < heap[curr])
      {
        swap(heap[parent(curr)],heap[curr]);
        curr = parent(curr);
      }
    }

    void pop()
    {
      if(heap.empty()) return;

      int curr = 0;
      swap(heap[0],heap[heap.size()-1]);
      heap.pop_back();

      while(left(curr) < size())
      {
        int idx = curr;
        if(heap[left(curr)] > heap[curr])
        {
          idx = left(curr);
        }
        if(heap[right(curr)] > heap[idx] && right(curr) < size())
        {
          idx = right(curr);
        }
        
        if(idx == curr) return;
        else
        {
          swap(heap[idx],heap[curr]);
          curr = idx;
        }

      }
    }

    int top()
    {
      if(!heap.empty()) return heap[0];
      else return -1;
    }

    void print()
    {
      for(int i = 0; i < size(); i++) cout << heap[i] << " ";
      cout << endl;
    }

};



int main()
{
  MaxHeap * heap = new MaxHeap();
  for(int i = 1; i <= 16; i++) heap->add(i);
  heap->print();

  cout << "Top() : " << heap->top() << endl;
  for(int i = 0; i < 20; i++)
  {
    heap->pop();
    cout << "Top() : " << heap->top() << "\t";
    heap->print();
  }
  
  return 0;
}

