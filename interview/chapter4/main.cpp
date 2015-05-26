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
  
  
  return 0;
}
bool isBalanced(TreeNode * root)
{
  if(!root) return true;

  int l = height(root->left);
  int r = height(root->right);

  if(abs(l-r) > 1) return false;
  else return isBalanced(root->left) && isBalanced(root->right);
}

// Chapter 4.2

int main()
{

  // Chapter 4.1 Tester
  cout << "Chapter 4.1 - " << endl;


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

