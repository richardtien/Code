#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
#include <List>

using namespace std;


class HashEntry
{
  private:
    int key;
    int value;

  public:
    HashEntry(int k, int v)
    {
      key = k;
      value = v;
    }
    int getKey() { return this->key; }
    int getValue() { return this->value; }
    void setValue(int v)
    {
      value = v;
    }
};

class HashMap
{
  private:
    int size;
    vector<vector<HashEntry *> > table;

  public:
    HashMap(int n) : table(n,vector<HashEntry*>())
    { 
      this->size = n;
    }

    int getHash(int n)
    {
      return n % size;
    }

    void put(int k, int v)
    {
      int hash = getHash(k);
      for(int i = 0; i < table[hash].size(); i++)
      {
        if(table[hash][i]->getKey() == k)
        {
          table[hash][i]->setValue(v);
          return;
        }
      }
      table[hash].push_back(new HashEntry(k,v));
    }

    int get(int k)
    {
      int hash = getHash(k);
      for(int i = 0; i < table[hash].size(); i++)
      {
        if(table[hash][i]->getKey() == k) return table[hash][i]->getValue();
      }
      return INT_MIN;
    }


    void print()
    {
      for(int i = 0; i < table.size(); i++)
      {
        cout << "Index " << i+1 << " -  ";
        for(int j = 0; j < table[i].size(); j++)
        {
          cout << table[i][j]->getKey() << ":" << table[i][j]->getValue() << "  ";
        }
        cout << endl;
      }
    }
  
};

int main()
{
  HashMap * h = new HashMap(10);

  h->put(1,1);
  h->put(1,2);
  h->put(2,2);
  h->put(2,5);
  h->put(12,3);

  h->print();

  cout << h->get(13) << endl;

  cout << sizeof(h) << endl;

  return 0;
}


