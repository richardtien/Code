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

int parent(int n)
{
  return (n-1)/2;
}

int leftChild(int n)
{
  return (n*2)+1;
}

int rightChild(int n)
{
  return (n*2)+2;
}

void siftDown(int arr[], int start, int size)
{
  int root = start;

  while(leftChild(root) <= size)
  {
    int childIndex = leftChild(root);
    int swapIndex = root;

    if(arr[swapIndex] < arr[childIndex])
    {
      swapIndex = childIndex;
    }

    if(childIndex+1 <= size && arr[swapIndex] < arr[childIndex+1])
    {
      swapIndex = childIndex+1;
    }

    if(swapIndex == root) return;
    else
    {
      swap(arr[swapIndex],arr[root]);
      root = swapIndex;
    }
  }
}

void heapify(int arr[], int size)
{
  int start = parent(size);         // sift down starting from the last element's parent down to the root
  while(start >= 0)
  {
    siftDown(arr,start,size-1);
    start--;
  }
}

void heapSort(int arr[],int size)
{
  heapify(arr,size);        // call heapify so the root contains the max element

  int end = size-1;
  while(0 < end)            // swap the max element to the end of the list and call sift down on the new root
  {
    swap(arr[end],arr[0]);
    end--;
    siftDown(arr,0,end);
  }
}

void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int array[] = {7,9,4,6,1,3,2,5,8};
  printArray(array,9);

  heapSort(array,9);

  printArray(array,9);

  return 0;
}

