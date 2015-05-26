#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
#include <List>

using namespace std;

// Chapter 9.1
int steps(int n)
{
  if(n == 0) return 1;
  else if(n < 0) return 0;

  return steps(n-1) + steps(n-2) + steps(n-3);
}

int steps(int n, int map[])
{
  if(n == 0) return 1;
  else if(n < 0) return 0;
  else if(map[n] != 0) return map[n];
  else
  {
    map[n] = steps(n-1,map) + steps(n-2,map) + steps(n-3,map);
    return map[n];
  }
}

// Chapter 9.2
int findPath(int x, int y)
{
  if(x == 0 && y == 0) return 0;

  vector<vector<int> > dp(x,vector<int>(y));

  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      if(i == 0 || j == 0) dp[i][j] = 1;
      else dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
  }
  return dp[x-1][y-1];
}

// Chapter 9.3
int findMagic(int arr[], int start, int end)
{
  
  while(start <= end)
  {
    int mid = (start+end)/2;
    //cout << start << " " << end << " " << mid << " " << arr[mid] << endl;

    if(arr[mid] == mid) return mid;
    else if(arr[mid] > mid)
    {
      end = mid-1;
    }
    else if(arr[mid] < mid)
    {
      start = mid+1;

    }
  }

  return INT_MIN;
}

// Chapter 9.4
void subsetsHelper(vector<int> &s, vector<int> &solution, vector<vector<int> > &result, int len, int start)
{
  if(solution.size() == len)
  {
    result.push_back(solution);
    return;
  }

  for(int i = start; i < s.size(); i++)
  {
    solution.push_back(s[i]);
    subsetsHelper(s,solution,result,len,i+1);
    solution.pop_back();
  }
}

vector<vector<int> > subsets(vector<int> &s)
{
  sort(s.begin(),s.end());
  vector<int> solution;
  vector<vector<int> > result;

  for(int i = 0; i <= s.size(); i++)
  {
    subsetsHelper(s,solution,result,i,0);
    solution.clear();
  }
  return result;
}

// Chapter 9.5
void permutationHelper(string s, string &solution, vector<string> &result, vector<bool> &visited)
{
  if(solution.length() == s.length())
  {
    result.push_back(solution);
    return;
  }

  for(int i = 0; i < s.size(); i++)
  {
    if(!visited[i])
    {
      visited[i] = true;
      solution += s[i];
      permutationHelper(s,solution,result,visited);
      solution.pop_back();
      visited[i] = false;
    }
  }

}
vector<string> stringPermutations(string s)
{
  
  vector<string> result;
  string solution = "";
  vector<bool> visited(s.size(),false);

  permutationHelper(s,solution,result,visited);

  return result;
}

// Chapter 9.6
void parenHelper(int l, int r, vector<string> &result, string solution)
{
  if(l == 0 && r == 0)
  {
    result.push_back(solution);
  }

  if(l > 0)
  {
    parenHelper(l-1,r,result,solution+'(');
  }

  if(l < r)
  {
    parenHelper(l,r-1,result,solution+')');
  }
}

vector<string> generateParen(int n)
{
  vector<string> result;
  string solution = "";
  parenHelper(n,n,result,solution);

  return result;
}

// Chapter 9.7 - 4^n

void paintFill(vector<vector<int> > &image, int x, int y, int oldColor, int newColor)
{
  if(x < 0 || x > image.size() || y < 0 || y > image[0].size()) return;

  if(image[x][y] == oldColor)
  {
    image[x][y] = newColor;

    paintFill(image,x-1,y,oldColor,newColor);
    paintFill(image,x+1,y,oldColor,newColor);
    paintFill(image,x,y-1,oldColor,newColor);
    paintFill(image,x,y+1,oldColor,newColor);
  }
}

void paintFill(vector<vector<int> > &image, int x, int y, int newColor)
{
  if(image[x][y] == newColor) return;
  
  paintFill(image,x,y,image[x][y],newColor);
}

// Chapter 9.8

int makeWays(int n, int denom)
{
  int next_denom = 0;
  switch(denom)
  {
    case 25:
      next_denom = 10;
      break;
    case 10:
      next_denom = 5;
      break;
    case 5:
      next_denom = 1;
      break;
    case 1:
      return 1;
  }

  int ways = 0;
  for(int i = 0; i * denom <= n; i++)
  {
    ways += makeWays(n-(i*denom),next_denom);
  }
  return ways;
}

// Chapter 9.9

// Queens
void printBoard(vector<vector<bool> > board)
{
  for(int i = 0; i < board.size(); i++)
  {
    for(int j = 0; j < board[i].size(); j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSafe(vector<vector<bool> > board, int row, int col)
{
  int i, j;

  for(i = 0; i < col; i++)
  {
    if(board[row][i]) return false;
  }

  for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if(board[i][j]) return false;
  }

  for(i = row, j = col; j >= 0 && i < board.size(); i++, j--)
  {
    if(board[i][j]) return false;
  }
  return true;
}

bool solveQueens(vector<vector<bool> > & board, int col)
{
  if(col >= board.size()) 
  {
    return true;
  }
  for(int i = 0; i < board.size(); i++)
  {
    if(isSafe(board,i,col))
    {
      board[i][col] = 1;
      if(solveQueens(board,col+1) == true)
      {
        return true;
      }
      board[i][col] = 0;
    }
  }
  return false;
}

// Chapter 9.10

int main()
{
  cout << "Chapter 9.1 - " << endl;
  cout << steps(9) << endl;
  int map[10] = {0};
  cout << steps(9,map) << endl;

  cout << "Chapter 9.2 - " << endl;

  cout << findPath(5,5) << endl;

  cout << "Chapter 9.3 - " << endl;

  int arr[11] = {-40,-20,-1,1,2,3,5,7,9,12,13};
  
  cout << findMagic(arr,0,10) << endl;

  cout << "Chapter 9.4 - " << endl;

  vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  vector<vector<int> > result = subsets(list);

  for(int i = 0; i < result.size(); i++)
  {
    for(int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Chapter 9.5 - " << endl;
  vector<string> stringResult = stringPermutations("xyz");
  for(int i = 0; i < stringResult.size(); i++)
  {
    for(int j = 0; j < stringResult[i].length(); j++)
    {
      cout << stringResult[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Chapter 9.6 - " << endl;
  vector<string> parenResult = generateParen(3);

  for(int i = 0; i < parenResult.size(); i++)
  {
    cout << parenResult[i] << endl;
  }

  cout << "\n\n\nSolve Queens" << endl;
  vector<vector<bool> > board(4,vector<bool>(4,false));

  cout << "\n" << endl;
  if(solveQueens(board,0))
  {
    printBoard(board);
  }
  
    
  return 0;
}


