/*  Written by: Richard Tien
 *  Note: Singly Linked-List with only pointer node head
 *        Insert to head takes O(1)
 *        Insert to tail takes O(n)
 *        Delete head takes O(1)
 *        Delete tail takes O(n)
 */

#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

class LinkedList
{
  public:
    LinkedList();             // default constructor
    void insertFront(int x);  // insert new node to front
    void insertBack(int x);   // insert new node to back
    void print();             // print all node in this LinkedList Object
    Node * removeHead();      // remove head node from list and return the node
    Node * removeTail();      // remove tail node from list and return the node

    Node *head;
    int size;
};

LinkedList::LinkedList()
{
  this->head = NULL;
  this->size = 0;
}

void LinkedList::print()
{
  Node *i = this->head;
  while(i != NULL)
  {
    cout << i->data << endl;
    i = i->next;
  }
}

void LinkedList::insertFront(int data)
{
  Node *node = new Node();
  node->data = data;
  node->next = this->head;
  this->head = node;
  this->size++;
}

void LinkedList::insertBack(int data)
{
  Node *i = this->head;
  Node *node = new Node();
  node->data = data;
  this->size++;

  while(i != NULL)
  {
    if(i->next == NULL)
    {
      node->next = i->next;
      i->next = node;
      break;
    }
    i = i->next;
  }
}

Node * LinkedList::removeHead()
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

Node * LinkedList::removeTail()
{
  if(this->head == NULL)        // case 1, empty list
  {
    return NULL;
  }

  Node *i = this->head;
  size--;

  if(i->next == NULL)i          //  case 2, only 1 Node in list
  {
    this->head = NULL;
    i->next = NULL;  // remove link between deleted node and list
    return i;
  }

  while(i->next->next != NULL)  //  case 3, more than 1 Node in list
  {
    i = i->next;    // get the node before the last node
  }

  Node *node = i->next;
  i->next = i->next->next;

  node->next = NULL; // remove link between deleted node and list

  return node;
}

int main()
{
  LinkedList *a = new LinkedList();
  a->insertFront(5);
  a->insertFront(4);
  a->insertFront(3);
  a->insertBack(6);
  a->insertBack(7);
  a->insertFront(2);
  a->print();
  cout << "**********" << endl;
  a->removeHead();
  a->removeHead();
  a->print();
  cout << "**********" << endl;
  a->removeTail();
  a->removeTail();
  a->removeTail();
  a->print();
  cout << "**********" << endl;
  a->insertFront(123);
  a->insertBack(321);
  a->print();
  cout << "**********" << endl;
  a->removeHead();
  a->print();
  cout << "**********" << endl;

  a->removeTail();
  a->print();
  cout << "**********" << endl;
  cout << "REMOVING LAST ELEMENT" << endl;
  a->removeTail();
  a->print();

  return 0;
}
