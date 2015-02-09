/*  Written by: Richard Tien
 *  Note:  Simple BST to store int data
 *         Show the implemented add, search, getMax, and getMin functions
 *         Modified the isBST function to test our BST data structure
 *         whether it holds the BST property after adding a few nodes.
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class BSTNode
{
  public:
    BSTNode(int);

    BSTNode * add(BSTNode **,int);
    bool find(BSTNode *,int);

    int getMin(BSTNode *);
    int getMax(BSTNode *);

    int data;
    BSTNode * leftChild;
    BSTNode * rightChild;
};

BSTNode::BSTNode(int data)
{
  this->data = data;
  this->leftChild = this->rightChild = NULL;
}

BSTNode* BSTNode::add(BSTNode ** root,int data)
{
  if(*root == NULL)               // node does not exist
  {
    *root = new BSTNode(data);
  }
  else if(data <= (*root)->data)  // inserted data is less than current node
  {
    (*root)->leftChild = this->add(&((*root)->leftChild),data);
  }
  else                            // inserted data is greater than current node
  {
    (*root)->rightChild = this->add(&((*root)->rightChild),data);
  }

  return *root;
}

bool BSTNode::find(BSTNode * root, int data)
{
  if(root == NULL)
  {
    return false;
  }

  if(root->data != data)
  {
    return this->find(root->leftChild,data) || this->find(root->rightChild,data);
  }
  else
    return true;
}

int BSTNode::getMin(BSTNode * root)
{
  if(root == NULL)
  {
    return std::numeric_limits<int>::min();
  }
  else if(root->leftChild !=  NULL)
  {
    return getMin(root->leftChild);
  }
  else
    return root->data;
}

int BSTNode::getMax(BSTNode * root)
{
  if(root == NULL)
  {
    return std::numeric_limits<int>::max();
  }
  else if(root->rightChild != NULL)
  {
    return getMax(root->rightChild);
  }
  else
    return root->data;
}

bool isBST(BSTNode *node, int minData, int maxData) 
{
    if(node == NULL)
    { 
      return true;
    }

    if(node->data < minData || node->data > maxData) 
    {
      return false;
    }

    return isBST(node->leftChild, minData, node->data) && 
           isBST(node->rightChild, node->data, maxData);
}

int main()
{
  BSTNode * root = NULL;

  cout << "***********************************" << endl;
  cout << "Adding 5, 6, 4, 3, 2, 1, 7, 8, 9" << endl;
  root->add(&root,5);
  root->add(&root,6);
  root->add(&root,4);
  root->add(&root,3);
  root->add(&root,2);
  root->add(&root,1);
  root->add(&root,7);
  root->add(&root,8);
  root->add(&root,9);

  cout << "***********************************" << endl;
  cout << "Find 5: " << root->find(root,5) << "\n";
  cout << "Find 9: " << root->find(root,9) << "\n";
  cout << "Find 2: " << root->find(root,2) << "\n";
  cout << "Find 10: " << root->find(root,10) << "\n";
  cout << "Find 1: " << root->find(root,1) << "\n";
  cout << "Find -1: " << root->find(root,-1) << "\n";

  cout << "***********************************" << endl;
  cout << "MIN: " << root->getMin(root) << "\n";
  cout << "MAX: " << root->getMax(root) << "\n";
  cout << "BST PROPERTY? " << isBST(root,root->getMin(root),root->getMax(root)) << endl;  // 1 for true, 0 for false
  cout << "***********************************" << endl;

  return 0;
}
