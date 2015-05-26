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

int partition(vector<int> &arr, int start, int end)
{
  int pivot = arr[end];
  int pIndex = start;

  for(int i = start; i < end; i++)
  {
    if(pivot >= arr[i])
    {
      swap(arr[pIndex],arr[i]);
      pIndex++;
    }
  }
  swap(arr[end],arr[pIndex]);

  return pIndex;
}

void quickSort(vector<int> &arr, int start, int end)
{
  if(start < end)
  {
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
  }
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

  quickSort(arr,0,9);

  for(int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

