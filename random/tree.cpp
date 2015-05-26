
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node
{
  public:
    int data;
    Node * left;
    Node * right;

    Node(int data)
    {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

int height(Node * root)
{
  if(root == NULL)
    return 0;

  int left = height(root->left);
  int right = height(root->right);

  return 1 + max(left,right);
}


bool isBalanced(Node * root)
{
  if(root == NULL)
  {
    return true;
  }

  int left = height(root->left);
  int right = height(root->right);

  if(abs(left-right) > 1)
  {
    return false;
  }
  else
  { 
    return isBalanced(root->left) && isBalanced(root->right);
  }
}

int max(int x, int y)
{
  if(x < y) return y;
  else return x;
}

// create a BST from a sorted array
Node * createBST(int arr[], int start, int end)
{
  if(start > end)
  {
    return NULL;
  }

  int mid = (start+end)/2;
  Node * node = new Node(arr[mid]);

  node->left = createBST(arr,start,mid-1);
  node->right = createBST(arr,mid+1,end);

  return node;
}

void preOrder(Node * root)
{
  if(root == NULL) return;
  
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node * root)
{
  if(root == NULL) return;
 
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  
}

void postOrder(Node * root)
{
  if(root == NULL) return;
  
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
  
}



/* Point of BFS is to iterate through the graph
 *
 *
 */
void printBFS(Node * root)
{
  queue<Node*> queue;
  queue.push(root);       // insert root into queue

  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;

  while(!queue.empty())
  {
    Node * node = queue.front();
    queue.pop();
    nodesInCurrentLevel--;
    cout << node->data << " ";

    if(node->left) 
    {
      queue.push(node->left);
      nodesInNextLevel++;
    }

    if(node->right)
    {
      queue.push(node->right);
      nodesInNextLevel++;
    }

    if(nodesInCurrentLevel == 0)
    {
      cout << endl;
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;

    }

  }
}

bool isSameTree(Node * p, Node * q)
{


  return false;
}

int main()
{

  int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};


/*
  Node * root = new Node(3);
  root->left = new Node(2);
  root->right = new Node(5);
  root->right->left = new Node(4);
  root->right->right = new Node(7);
  root->right->right->right = new Node(8);
*/

  Node *root = createBST(a,0,20);

  if(isBalanced(root))
  {
    cout << "Tree is balanced" << endl;
  }
  else
  {
    cout << "Tree is not balanced" << endl;
  }

  preOrder(root);
  cout << endl;
  inOrder(root);
  cout << endl;
  postOrder(root);
  cout << endl;

  cout << "************************************" << endl;

  cout << "\tBFS NODES PER LEVEL" << endl;
  printBFS(root);

  levelOrderBottom(root);




/*
  int x[] = {1,2,3,4};

  int *y[] = {x,x,x,x};

  int **z = y;

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout << z[i][j] << " ";
    }
    cout << endl;
  }
*/


}



