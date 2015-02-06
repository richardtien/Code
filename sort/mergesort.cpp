/*  Written by: Richard Tien
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> list)
{
  for(int i = 0; i < list.size(); i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

vector<int> merge(vector<int> &list, vector<int> left, vector<int> right)
{
  vector<int> returnVector;
  returnVector.clear();

  int leftIndex = 0;
  int rightIndex = 0;

  for(int i = 0; i < left.size() + right.size(); i++)
  {
    if(leftIndex == left.size())
    {
      returnVector.push_back(right[rightIndex]);
      rightIndex++;
    }
    else if(rightIndex == right.size())
    {
      returnVector.push_back(left[leftIndex]);
      leftIndex++;
    }
    else if(left[leftIndex] < right[rightIndex])
    {
      returnVector.push_back(left[leftIndex]);
      leftIndex++;
    }
    else
    {
      returnVector.push_back(right[rightIndex]);
      rightIndex++;
    }
  }

  list = returnVector;
  return returnVector;
}

vector<int> mergesort(vector<int> &list)
{
  if(1 < list.size())
  {
    int mid = list.size()/2;

    vector<int> left;
    vector<int> right;

    for(int i = 0; i < mid; i++)
    {
      left.push_back(list[i]);
    }
    for(int i = mid; i < list.size(); i++)
    {
      right.push_back(list[i]);
    }

    left = mergesort(left);
    right = mergesort(right);

    return merge(list,left,right);
  }
  else
  {
    return list;
  }
}

int main()
{
  //int arr[10] = {10,9,8,7,6,5,4,3,2,1};

  //int arr[10] = {1,2,3,4,5,6,7,8,9,10};

  //int arr[10] = {1,6,3,7,5,9,4,8,2,10};
  
  int arr[10] = {10,2,8,4,9,5,7,3,6,1};

  vector<int> list (arr, arr+sizeof(arr)/sizeof(arr[0]));

  cout << "PRINTING LIST BEFORE MERGESORT" << endl;
  printArray(list);

  cout << "CALLING BUBBLE SORT FUNCTION" << endl;
  mergesort(list);

  cout << "PRINTING LIST AFTER MERGESORT" << endl;
  printArray(list);

  return 0;
}

