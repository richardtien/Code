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

// Singly Linked-List
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

// Chapter 2.1
void removeDuplicates(List * root)
{
  unordered_map<int,bool> table;

  List * prev = root;
  List * curr = root->next;

  table[prev->data] = true;

  while(curr)
  {
    if(table[curr->data])    // duplicate
    {
      prev->next = curr->next;
    }
    else                     // insert value into hash table, not duplicate
    {
      table[curr->data] = true;
      prev = curr;

    }
    curr = curr->next;
  }
}

void removeDups(List * root)
{
  List * curr = root;

  while(curr)
  {
    List * runner = curr;
    while(runner->next)
    {
      if(runner->next->data == curr->data)
      {
        runner->next = runner->next->next;
      }
      else
      {
        runner = runner->next;
      }
    }
    curr = curr->next;
  }

}

// Chapter 2.2
List * findKtoLast(List * root, int n)
{
  List * runner = root;
  List * curr = root;
  for(int i = 0; i <= n; i++)
  {
    runner = runner->next;
  }

  while(runner)
  {
    curr = curr->next;
    runner = runner->next;
  }

  return curr;
}

// Chapter 2.3
void deleteNode(List * node)
{
  if(!node || !node->next) return;
  node->data = node->next->data;
  node->next = node->next->next;
}

// Chapter 2.4
List * partition(List * root, int x)
{
  List * curr = root;

  List * dummyLT = new List(-1);
  List * dummyGT = new List(-1);
  List * lt = dummyLT;
  List * gt = dummyGT;

  while(curr)
  {
    if(curr->data < x)
    {
      dummyLT->next = curr;
      dummyLT = dummyLT->next;
    }
    else if(curr->data > x)
    {
      dummyGT->next = curr;
      dummyGT = dummyGT->next;
    }
    curr = curr->next;
  }

  if(!lt) return gt->next;

  dummyLT->next = gt->next;

  return lt->next;
}

// Chapter 2.5
List * addLists(List * l1, List * l2)
{
  if(!l1 && !l2) return NULL;
  if(!l1) return l2;
  if(!l2) return l1;

  List * dummy = new List(-1);

  int sum = l1->data + l2->data;
  int carry = 0;
  if(sum > 9)
  {
    carry = 1;
    sum = sum % 10;
  }

  List * head = new List(sum);
  dummy->next = head;

  l1 = l1->next;
  l2 = l2->next;

  while(l1 && l2)
  {
    sum = l1->data + l2->data;
    if(carry != 0) sum += carry;
    if(sum > 9)
    {
      carry = 1;
      sum = sum % 10;
    }
    else carry = 0;

    List * temp = new List(sum);
    head->next = temp;
    head = head->next;
    l1 = l1->next;
    l2 = l2->next;
  }

  while(l1)
  {
    sum = l1->data;
    if(carry != 0) sum += carry;
    if(sum > 9)
    {
      carry = 1;
      sum = sum % 10;
    }
    else carry = 0;

    List * temp = new List(sum);
    head->next = temp;
    head = head->next;

    l1 = l1->next;
  }

  while(l2)
  {
    sum = l2->data;
    if(carry != 0) sum += carry;
    if(sum > 9)
    {
      carry = 1;
      sum = sum % 10;
    }
    else carry = 0;

    List * temp = new List(sum);
    head->next = temp;
    head = head->next;

    l2 = l2-> next;
  }

  if(carry != 0)
  {
    List * temp = new List(1);
    head->next = temp;
    head = head->next;
  }

  return dummy->next;;
}

// Chapter 2.6
List * findBeginning(List * head)
{
  List * slow = head;
  List * fast = head;

  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) break;
  }

  slow = head;

  while(slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;

}

// Chapter 2.7
List * reverseList(List * head)
{
  List * prev = NULL;
  List * curr = head;

  while(curr->next)
  {
    List * temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  curr->next = prev;

  return curr;
}
bool isPalindrome(List * head)
{
  List * rev = reverseList(head);

  while(head && rev)
  {
    if(head->data != rev->data) return false;
    else
    {
      head = head->next;
      rev = rev->next;
    }
  }

  return true;
}

int main()
{
  
  // Chapter 2.1 Tester
  cout << "Chapter 2.1 - " << endl;
  List * root = new List(1);
  List * a = new List(2);
  List * b = new List(3);
  List * c = new List(3);
  List * d = new List(2);
  List * e = new List(4);
  List * f = new List(4);
  List * g = new List(5);

  root->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  List * curr = root;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
  //removeDuplicates(root);
  removeDups(root);
  curr = root;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;

  // Chapter 2.2
  cout << "Chapter 2.2 - " << endl;
  cout << findKtoLast(root,4)->data << endl;
  
  // Chapter 2.3
  cout << "Chapter 2.3 - " << endl;
  deleteNode(e);
  curr = root;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
  
  // Chapter 2.4
  cout << "Chapter 2.4 - " << endl;
  List * h = partition(root,4);
  curr = h;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
  
  // Chapter 2.5
  cout << "Chapter 2.5 - " << endl;
  List * i = new List(7);
  List * j = new List(1);
  List * k = new List(6);
  List * l = new List(5);
  List * m = new List(9);
  List * n = new List(3);

  i->next = j; j->next = k;
  l->next = m; m->next = n;

  List * o = addLists(i,l);
  curr = o;

  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;

  // Chapter 2.6
  cout << "Chapter 2.6 - " << endl;

  // Chapter 2.7
  cout << "Chapter 2.7 - " << endl;
  List * p = reverseList(o);
  curr = p;
  cout << "Reverse List:" << endl;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
  
  List * q = new List(0);
  List * r = new List(1);
  List * s = new List(2);
  List * t = new List(1);
  List * u = new List(0);
  List * v = new List(3);

  q->next = r; 
  r->next = s; 
  s->next = t; 
  t->next = u;
  //u->next = v;

  cout << "Palindrome:" << endl;
  if(isPalindrome(q)) cout << "is palindrome" << endl;
  else cout << "is not palindrome" << endl;
  

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

