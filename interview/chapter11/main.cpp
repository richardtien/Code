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

// Chapter 11.1
void merge(int a[], int b[], int aLast, int bLast)
{
  int aPtr = aLast-1;
  int bPtr = bLast-1;

  int end = aLast+bLast-1;

  while(end >= 0 && aPtr >= 0 && bPtr >= 0)
  {
    if(a[aPtr] >= b[bPtr])
    {
      a[end--] = a[aPtr--];
    }
    else
    {
      a[end--] = b[bPtr--];
    }
  }

  while(bPtr >= 0)
  {
    a[end--] = b[bPtr--];
  }
}

// Chapter 11.2
vector<string> sort(vector<string> str)
{
  unordered_map<string,vector<string> > hash;

  for(int i = 0; i < str.size(); i++)
  {
    string key = str[i];
    sort(key.begin(),key.end());
    hash[key].push_back(str[i]);
  }

  vector<string> result;
  for(unordered_map<string,vector<string> >::iterator it = hash.begin(); it != hash.end(); it++)
  {
    for(int i = 0; i < it->second.size(); i++)
    {
      result.push_back(it->second[i]);
    }
  }
  return result;
}

void printStringVector(vector<string> l)
{
  for(int i = 0; i < l.size(); i++)
  {
    cout << i+1 << " - " << l[i] << endl;
  }
}

// Chapter 11.3
int search(int arr[], int start, int end, int x)
{
  int mid = (start+end)/2;
  if(arr[mid] == x) return mid;

  if(start > end) return -1;

  if(arr[start] < arr[mid])
  {
    if(arr[start] <= x && x <= arr[mid])
    {
      return search(arr,start,mid-1,x);
    }
    else
    {
      return search(arr,mid+1,end,x);
    }
  }
  else if(arr[start] > arr[mid])
  {
    if(arr[mid] <= x && x <= arr[end])
    {
      return search(arr,mid+1,end,x);
    }
    else
    {
      return search(arr,start,mid-1,x);
    }
  }
  else if(arr[start] == arr[mid])   // left and mid are equal
  {
    if(arr[mid] != arr[end])  // just check the right side
    {
      return search(arr,mid+1,end,x);
    }
    else  // check both sides
    {
      int t = search(arr,start,mid-1,x);
      if(t == -1)
      {
        return search(arr,mid+1,end,x);
      }
      else
      {
        return t;
      }
    }
  }

  return -1;
}

// Chapter 11.5
int searchR(vector<string> list, string str, int start, int end)
{
  if(start > end) return -1;

  int mid = (start+end)/2;
  
  if(list[mid].empty())
  {
    int left = mid-1;
    int right = mid+1;

    while(true)
    {
      if(left < start && right > end) return -1;
      else if(start <= left && !list[left].empty())
      {
        mid = left;
        break;
      }
      else if(right <= end && !list[right].empty())
      {
        mid = right;
        break;
      }
      left--;
      right++;
    }
  }

  if(list[mid] == str) return mid;
  else
  {
    if(list[mid].compare(str) < 0)
    {
      return searchR(list,str,mid+1,end);
    }
    else
    {
      return searchR(list,str,start,mid-1);
    }
  }
  return 0;
}

// Chapter 11.6
bool findElement(vector<vector<int> > matrix, int x)
{
  int row = matrix.size()-1;
  int col = 0;

  while(row >= 0 && col <= matrix[0].size())
  {
    if(matrix[row][col] == x) return true;
    else if(matrix[row][col] < x)
    {
      col++;
    }
    else
    {
      row--;
    }
  }
  return false;
}

int main()
{

  // Chapter 11.1 Tester
  cout << "Chapter 11.1 - " << endl;
  int a[10] = {5,6,7,8,9};
  int b[5] = {0,1,2,3,4};

  merge(a,b,5,5);

  for(int i = 0; i < 10; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  // Chapter 11.2 Tester
  cout << "Chapter 11.2 - " << endl;
  vector<string> sortString;
  sortString.push_back("race");
  sortString.push_back("bad");
  sortString.push_back("adb");
  sortString.push_back("dab");
  sortString.push_back("care");
  sortString.push_back("acre");
  sortString.push_back("lol");

  printStringVector(sortString);
  sortString = sort(sortString);
  cout << endl;
  printStringVector(sortString);

  // Chapter 11.3 Tester
  cout << "Chapter 11.3 - " << endl;
  int arr[] = {10,15,20,0,5};
  cout << search(arr,0,4,10) << endl;

  // Chapter 11.5 Tester
  cout << "Chapter 11.5 - " << endl;
 
  // Chapter 11.6 Tester

  cout << "Chapter 12.1" << endl;
  unsigned int i;
  for(i = 100; i > 0; --i)
  {
    printf("%u\n",i);
  }
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

