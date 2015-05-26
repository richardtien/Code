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

// Chapter 17.1
void swap(int &a, int &b)
{
  a = a - b;
  b = a + b;
  a = b - a;
  // or XOR 3 times
}

void printArray(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// Chapter 17.2
void printMatrix(vector<vector<int> > matrix)
{
  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

}

bool hasWon(vector<vector<int> > board) // 3x3
{
  for(int i = 0; i < board.size(); i++)
  {
    if(board[i][0] != 0 && board[i][0] == board[i][1] &&
    board[i][0] == board[i][2])
    {
      return true;
    }

    if(board[0][i] != 0 && board[0][i] == board[1][i] &&
    board[0][i] == board[2][i])
    {
      return true;
    }

    if(board[0][0] != 0 && board[0][0] == board[1][1] &&
    board[0][0] == board[2][2])
    {
      return true;
    }

    if(board[2][0] != 0 && board[2][0] == board[1][1] &&
    board[2][0] == board[0][2])
    {
      return true;
    }

  }
  return false;
}

bool hasWonn(vector<vector<int> > matrix)
{
  int n = matrix.size();
  for(int i = 0; i < n; i++)    // check row
  {
    if(matrix[i][0] != 0)
    {
      for(int j = 1; j < n; j++)
      {
        if(matrix[i][j-1] != matrix[i][j])
        {
          break;
        }
        if(j == n-1) return true;
      }
    }
  }

  for(int i = 0; i < n; i++)
  {
    if(matrix[0][i] != 0)
    {
      for(int j = 1; j < n; j++)
      {
        if(matrix[j][i] != matrix[j-1][i])
        {
          break;
        }
        if(j == n-1) return true;
      }
    }
  }

  if(matrix[0][0] != 0)
  {
    for(int i = 1; i < n; i++)
    {
      if(matrix[i][i] != matrix[i-1][i-1])
      {
        return false;
      }
      if(i == n-1) return true;
    }
  }
  
  if(matrix[n-1][0] != 0)
  {
    for(int i = 1; i < n; i++)
    {
      if(matrix[n-1-i][i] != matrix[n-i][i])
      {
        return false;
      }
      if(n == n-1) return true;
    }
  }

  return false;
}

// Chapter 17.3
int factorsFive(int n)
{
  int count = 0;
  while(n%5 == 0)
  {
    count++;
    n = n/5;
  }

  return count;
}

int countTrailFact(int n)
{
  int count = 0;
  for(int i = 2; i < n; i++)
  {
    count = count + factorsFive(i);
  }

  return count;
}

// Chapter 17.5
int code(char c)
{
  if(c == 'R') return 0;
  else if(c == 'Y') return 1;
  else if(c == 'G') return 2;
  else if(c == 'B') return 3;
  else return -1;
}
void estimate(string guess, string solution)
{
  if(guess.length() != solution.length()) return;

  int hit = 0;
  int psuedo = 0;

  int possible[4] = {0};

  for(int i = 0; i < 4; i++)
  {
    if(guess[i] == solution[i])
    {
      hit++;
    }
    else  // possible psuedo hit
    {
      int c = code(solution[i]);
      possible[c]++;
    }
  }

  for(int i = 0; i < 4; i++)
  {
    int c = code(guess[i]);
    if(c >= 0 && possible[c] > 0 && guess[i] != solution[i])
    {
      psuedo++;
      possible[c]--;
    }
  }

  cout << "# of hits: " << hit 
       << "\t# of psuedo-hits: " << psuedo << endl;
}

// Chapter 17.8
int maxSum(int arr[], int n)
{
  int maxSum = 0;
  int sum = 0;

  for(int i = 0; i < n; i++)
  {
    sum += arr[i];
    if(sum > maxSum)
    {
      sum = maxSum;
    }
    else if(sum < 0)
    {
      sum = 0;
    }
  }
  return maxSum;

}

// Chapter 17.9
int getFrequency(vector<string> book, string word)
{
  int count;  // making words lower case may be a detail
  for(int i = 0; i < book.size(); i++)
  {
    if(book[i] == word) count++;
  }

  return count;
}

unordered_map<string,int> buildBookHash(vector<string> book)
{
  unordered_map<string,int> result;

  for(int i = 0; i < book.size(); i++)
  {
    result[book[i]]++;
  }
  return result;
}

int getFrequency(unordered_map<string,int> table, string word)
{
  if(table.empty()) return -1;
  if(word.empty()) return -1;
  return table[word];
}

class Node
{
  public:
    int data;
    Node * n1;
    Node * n2;
    Node(int d) : data(d), n1(NULL), n2(NULL){ }
};

void preOrder(Node * root)
{
  if(!root) return;
  preOrder(root->n1);
  cout << root->data << endl;
  preOrder(root->n2);
}

Node * treeToLL(Node * root)
{
  if(!root) return NULL;

  if(root->n1)
  {
    Node * left = treeToLL(root->n1);
    
    while(left->n2)
    {
      left = left->n2;
    }

    left->n2 = root;
    root->n1 = left;

  }

  if(root->n2)
  {
    Node * right = treeToLL(root->n2);

    while(right->n1)
    {
      right = right->n1;
    }

    right->n1 = root;
    root->n2 = right;
  }
  
  return root; 
}

Node * treeToLLS(Node * root)
{
  Node * result = treeToLL(root);
  while(result->n1)
  {
    result = result->n1;
  }
  return result;
}

priority_queue<int> maxheap;  // all elements smaller than median
priority_queue<int,vector<int>,greater<int> > minheap; // bigger than median

void addHeap(int n)
{
  if(maxheap.size() == minheap.size())
  {
    if(!minheap.empty() && n > minheap.top())
    {
      maxheap.push(minheap.top());
      minheap.pop();
      minheap.push(n);
    }
    else
    {
      maxheap.push(n);
    }
  }
  else
  {
    if(n < maxheap.top())
    {
      minheap.push(maxheap.top());
      maxheap.pop();
      maxheap.push(n);
    }
    else
    {
      minheap.push(n);
    }
  }
}

double getMedian()
{
  if(maxheap.size() == 0) return INT_MIN;

  if(maxheap.size() == minheap.size())
  {
    return ((double)maxheap.top()+minheap.top())/2;
  }
  else
  {
    return maxheap.top();
  }
}

int main()
{
  // Chapter 17.1
  cout << "Chapter 17.1 - " << endl;
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  printArray(arr,10);
  swap(arr[0],arr[9]);
  cout << endl;
  printArray(arr,10);


  // Chapter 17.2
  cout << "Chapter 17.2 - " << endl;

  vector<vector<int> > board(3,vector<int>(3,0));
  printMatrix(board);
  hasWonn(board);

  // Chapter 17.3
  cout << "Chapter 17.3 - " << endl;
  
  // Chapter 17.5
  cout << "Chapter 17.5 - " << endl;
  estimate("RGBY","GGRR");

  // Chapter 17.13
  cout << "Chapter 17.13 - " << endl;
  Node * a = new Node(1);
  Node * b = new Node(2);
  Node * c = new Node(3);
  Node * d = new Node(4);
  Node * e = new Node(5);
  Node * f = new Node(6);
  Node * g = new Node(7);
  Node * h = new Node(8);
  Node * i = new Node(9);
  Node * j = new Node(10);
  Node * k = new Node(11);
  Node * l = new Node(12);
  Node * m = new Node(13);
  Node * n = new Node(14);
  Node * o = new Node(15);


  h->n1 = d;
  h->n2 = l;

  d->n1 = b;
  d->n2 = f;

  l->n1 = j;
  l->n2 = n;

  b->n1 = a;
  b->n2 = c;

  f->n1 = e;
  f->n2 = g;
  
  j->n1 = i;
  j->n2 = k;

  n->n1 = m;
  n->n2 = o;

  //preOrder(a);
  Node * result = treeToLLS(h);
  
  while(result)
  {
    cout << result->data << endl;
    result = result->n2;
  }

  cout << "Get Median" << endl;
  for(int i = 1; i <= 100; i++)
  {
    addHeap(i);
    cout << "1 to " << i << " - " << getMedian() << endl;
  }
  
  return 0;
}

