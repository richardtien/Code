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

void bubbleSort(vector<int> &arr)
{
  int count = 0;
  bool swapped = true;
  int n = arr.size();
  while(swapped)
  {
    swapped = false;
    for(int i = 0; i < n-1; i++)
    {
      count++;
      if(arr[i] < arr[i+1])
      {
        swap(arr[i],arr[i+1]);
        swapped = true;
      }
    }
    n--;
  }
  cout << "Count: " << count << endl;
}

int main()
{
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(6);
  arr.push_back(7);
  arr.push_back(8);
  arr.push_back(9);
  arr.push_back(10);

  bubbleSort(arr);

  for(int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

