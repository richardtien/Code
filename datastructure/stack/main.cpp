/*  Written by: Richard Tien
 *  Note: Stack implementation using Linked List
 *        Stack is a data structure of LIFO
 */

#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

class Stack
{
  public:
    Stack();                  // default constructor
    void push(int x);         // push node to top of the stack
    Node * pop();             // pop the top node off the stack and return it
    void print();             // print all node in this Stack object

    Node *head;
    int size;
};

Stack::Stack()
{
  this->head = NULL;
  this->size = 0;
} 


void Stack::print()
{
  Node *i = this->head;
  while(i != NULL)
  {
    cout << i->data << endl;
    i = i->next;
  }
}

void Stack::push(int data)
{
  Node *node = new Node();
  node->data = data;
  node->next = this->head;
  this->head = node;
  this->size++;
}


Node * Stack::pop()
{
  if(this->head == NULL)
  {
    return NULL;
  }

  Node *i = this->head;
  this->head = this->head->next;

  i->next = NULL; // remove link between deleted node and list

  size--;

  return i;
}

int main()
{
  Stack *a = new Stack();
  a->push(5);
  a->push(4);
  a->push(3);
  a->push(2);
  a->print();
  cout << "**********" << endl;
  a->pop();
  a->pop();
  a->print();
  cout << "**********" << endl;
  a->push(123);
  a->print();
  cout << "**********" << endl;
  a->pop();
  a->pop();
  a->pop();
  a->print();

  return 0;
}
