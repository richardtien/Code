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

vector<int> merge(vector<int> left, vector<int> right)
{
  vector<int> result;
  int lPtr = 0;
  int rPtr = 0;

  for(int i = 0; i < left.size() + right.size(); i++)
  {
    if(lPtr == left.size())
    {
      result.push_back(right[rPtr++]);
    }
    else if(rPtr == right.size())
    {
      result.push_back(left[lPtr++]);
    }
    else if(left[lPtr] <= right[rPtr])
    {
      result.push_back(left[lPtr++]);
    }
    else
    {
      result.push_back(right[rPtr++]);
    }
  }
  return result;
}

vector<int> mergeSort(vector<int> arr)
{
  if(arr.size() > 1)
  {
    int mid = arr.size()/2;

    vector<int> left(arr.begin(),arr.begin()+mid);
    vector<int> right(arr.begin()+mid,arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);
  } 
  else return arr;
}

int main()
{
  vector<int> arr;
  arr.push_back(8);
  arr.push_back(10);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(7);
  arr.push_back(6);
  arr.push_back(9);
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(2);

  vector<int> result = mergeSort(arr);

  for(int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}

