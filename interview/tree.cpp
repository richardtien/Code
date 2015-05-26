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



class TreeNode
{
  public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

// Sorted Array
TreeNode * arrayToBST(int list[], int start, int end)
{
  if(start > end) return NULL;

  int mid = (start+end)/2;

  TreeNode * node = new TreeNode(list[mid]);

  node->left = arrayToBST(list,start,mid-1);
  node->right = arrayToBST(list,mid+1,end);

  return node;
}

void preOrder(TreeNode * root)
{
  if(!root) return;

  cout << root->val << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode * root)
{
  if(!root) return;

  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

void postOrder(TreeNode * root)
{
  if(!root) return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->val << " ";
}

void printBFS(TreeNode * root)
{
  if(!root) return;

  queue<TreeNode*> q;
  q.push(root);
  int level = 1, nextLevel = 0;

  while(!q.empty())
  {
    TreeNode * node = q.front();
    q.pop();
    level--;
    cout << node->val << " ";

    if(node->left)
    {
      q.push(node->left);
      nextLevel++;
    }
    if(node->right)
    {
      q.push(node->right);
      nextLevel++;
    }
    if(level == 0)
    {
      cout << endl;
      level = nextLevel;
      nextLevel = 0;
    }
  }
}

void inOrderI(TreeNode * root)
{
  stack<TreeNode*> stk;
  TreeNode * curr = root;
  while(!stk.empty() || curr != NULL)
  {
    if(curr != NULL)
    {
      stk.push(curr);
      curr = curr->left;
    }
    else if(!stk.empty())
    {
      TreeNode * node = stk.top();
      stk.pop();
      cout << node->val << " ";
      curr = node->right;
    }
  }
}

void preOrderI(TreeNode * root)
{
  stack<TreeNode*> stk;
  stk.push(root);
  while(!stk.empty())
  {
    TreeNode * node = stk.top();
    stk.pop();
    cout << node->val << " ";
    if(node->right)
    {
      stk.push(node->right);
    }
    if(node->left)
    {
      stk.push(node->left);
    }
  }
}

void postOrderI(TreeNode * root)
{
  // this is harder
}


int main()
{
  int list[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  TreeNode * root = arrayToBST(list,0,15);

  cout << "\tPrinting PreOrder(R) : " << endl;
  preOrder(root);
  cout << endl << endl;

  cout << "\tPrinting InOrder(R) : " << endl;
  inOrder(root);
  cout << endl << endl;

  cout << "\tPrinting PostOrder(R) : " << endl;
  postOrder(root);
  cout << endl << endl;
 
  cout << "\tPrinting BFS(Q) : " << endl;
  printBFS(root);
  cout << endl;

  cout << "\tPrinting preOrderI(S) : " << endl;
  preOrderI(root);
  cout << endl;

  cout << "\tPrinting inOrderI(S) : " << endl;
  inOrderI(root);
  cout << endl;

  cout << "\tPrinting postOrderI(S) : " << endl;
  postOrderI(root);
  cout << endl;

  return 0;
}

