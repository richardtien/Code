#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
#include <list>



using namespace std;


class TreeNode
{
  public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  
};

// Chapter 4.1
int height(TreeNode * root)
{
  if(!root) return 0;

  return max(height(root->left),height(root->right)) + 1;
}

bool isBalanced(TreeNode * root)
{
  if(!root) return true;

  int left = height(root->left);
  int right = height(root->right);

  if(abs(left-right) > 1) return false;
  else return isBalanced(root->left) && isBalanced(root->right);
  
}

// Chapter 4.3
TreeNode * createBST(int arr[], int start, int end)
{
  if(start > end)
  {
    return NULL;
  }

  int mid = (start+end)/2;

  TreeNode * node = new TreeNode(arr[mid]);
  node->left = createBST(arr,start,mid-1);
  node->right = createBST(arr,mid+1,end);

  return node;
}

// Chapter 4.4
void createList(TreeNode * root, vector<list<TreeNode *> > & lists, int level)
{
  if(!root) return;

  list<TreeNode *> l;

  if(lists.size() == level)
  {
    lists.push_back(l);
  }
  else
  {
    l = lists[level];
  }

  l.push_back(root);

  createList(root->left,lists,level+1);
  createList(root->right,lists,level+1);

}

// Chapter 4.5
bool matchTree(TreeNode * t1, TreeNode * t2)
{

  if(!t1 && !t2) return true;   // base case

  if(!t1 || !t2) return false;

  if(t1->val != t2->val)
  {
    return false;
  }
  else
  {
    return matchTree(t1->left,t2->left) && matchTree(t1->right,t2->right);
  }

}


bool checkBST(TreeNode * root, int min, int max)
{
  if(!root) return true;

  if(root->val <= min || root->val > max) return false;

  if(!checkBST(root->left,min,root->val) || 
     !checkBST(root->right,root->val,max)) return false;

  return true;
}


bool checkBST(TreeNode * root)
{
  return checkBST(root,INT_MIN,INT_MAX);
}

// Chapter 4.8
bool subTree(TreeNode * t1, TreeNode * t2)
{
  if(!t1) return false; // empty bigger tree cannot contain subtree

  if(t1->val == t2->val)
  {
    return matchTree(t1,t2);
  }
  else
  {
    return subTree(t1->left,t2) || subTree(t1->right,t2);
  }
}

bool checkSubtree(TreeNode * t1, TreeNode * t2)
{
  if(!t2) return true;  // empty subtree is always a subtree of bigger tree

  return subTree(t1,t2);
}

// Chapter 4.9
void sumPath(TreeNode * root, int sum)
{
  if(!root) return;



}

int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};


  TreeNode * a = createBST(arr,0,9);



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

