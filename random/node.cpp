
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>


using namespace std;

class Node
{
  public:
    int data;
    Node * next;

    Node(int d)
    {
      data = d;
      next = NULL;
    }

};

Node * reverseLL(Node * head)
{
  Node * curr = head;
  Node * prev = NULL;
  Node * next = head->next;
  
  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
  
}

// a->b->c->d->e->f->NULL
// 



void deleteDuplicates(Node * head)
{
  map<int,int> table;

  Node * prev = NULL;
  Node * curr = head;
  
  while(curr)
  {
    cout << curr->data << endl;
    if(table[curr->data] >= 1)
    {
      prev->next = curr->next;
    }
    else
    {
      prev = curr;
      table[curr->data]++;
    }
    curr = curr->next;
  } 
}

void deleteDup(Node * head)
{
  Node * curr = head;

  while(curr)
  {
    Node * runner = curr;
    while(runner->next)
    {
      if(curr->data == runner->next->data)
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

Node * addTwoNumbers(Node *l1, Node *l2)
{
  
  bool carry = false;
  int add = l1->data + l2->data;
  Node * root = new Node(add%10);
  Node * head = root;
  if(add > 9) carry = true;
  l1 = l1->next;
  l2 = l2->next;
  
  while(l1 && l2)
  {
    add = l1->data + l2->data;
    if(carry) ++add;
    carry = false;
    head->next = new Node(add%10);
    if(add > 9) carry = true;
    head = head->next;
    l1 = l1->next;
    l2 = l2->next;
  }

  while(l1)
  {
    int sum = l1->data;
    if(carry) sum++;

    head->next = new Node(sum%10);

    if(sum>9) carry = true;
    else carry = false;

    l1 = l1->next;
    head = head->next;
  }

  while(l2)
  {
    int sum = l2->data;
    if(carry) sum++;

    head->next = new Node(sum%10);

    if(sum>9) carry = true;
    else carry = false;

    l2 = l2->next;
    head = head->next;
  }

  if(carry)
  {
    head->next = new Node(1);
  }

  return root;
}


    Node *reverseKGroup(Node *head, int k) {
        stack<Node*> stk;
        Node * dummy = new Node(-1);
        Node * curr = head;
        Node * last;
        
        int i = 0;
        while(curr && i < k)
        {
            stk.push(curr);
            curr = curr->next;
            
            i++;
        }
        
        last = curr;

        
        if(!stk.empty())
        {
            curr = stk.top();
            stk.pop();
        }
        else return dummy->next;

        dummy->next = curr;
        
        while(!stk.empty())
        {
            curr->next = stk.top();
            curr = curr->next;
            stk.pop();
        }

        curr->next = last;


        curr = dummy->next;
        
        return dummy->next;
    }



int main()
{


  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

  Node * result = reverseKGroup(a,3);

  while(result)
  {
    cout << result->data << endl;
    result = result->next;
  }


/*

  Node *a = new Node(9);
  Node *b = new Node(8);
  //Node *c = new Node(3);

  Node *d = new Node(1);
  //Node *e = new Node(6);
  //Node *f = new Node(4);

  a->next = b;
  //b->next = c;

  //d->next = e;
  //e->next = f;


  Node * ret = addTwoNumbers(a,d);

  while(ret)
  {
    cout << ret->data << endl;
    ret = ret->next;
  }
*/



/*
  // Creating a linked list;
  Node *a = new Node(1);
  Node *b = new Node(1);
  Node *c = new Node(2);
  Node *d = new Node(3);
  Node *e = new Node(3);
  Node *f = new Node(4);
  Node *g = new Node(4);
  Node *h = new Node(4);
  Node *i = new Node(4);
  Node *j = new Node(4);
  Node *k = new Node(5);

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  g->next = h;
  h->next = i;
  i->next = j;
  j->next = k;
 
  Node *head = a;

  while(head)
  {
    cout << head->data << endl;
    head = head->next;
  }


  cout << "DELETE DUPLICATES" << endl;
  head = a;

  deleteDuplicates(head);
  //deleteDup(head);
  
  cout << "REVERSE LINKED LIST" << endl;
  head = a;
  Node * rev = reverseLL(head);

  while(rev)
  {
    cout << rev->data << endl;
    rev = rev->next;
  }
*/

  
  return 0;
}
