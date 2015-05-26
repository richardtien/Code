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

void selectionSort(vector<int> &arr)
{
  int count = 0;
  int iMin;

  for(int i = 0; i < arr.size()-1; i++)
  {
    iMin = i;
    for(int j = i+1; j < arr.size(); j++)
    {
      count++;
      if(arr[iMin] < arr[j])
      {
        iMin = j;
      }
    }
    if(iMin != i) swap(arr[iMin],arr[i]);
  }
  cout << "Count: " << count << endl;
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

  selectionSort(arr);

  for(int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

