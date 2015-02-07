/*  Written by: Richard Tien
 *  Notes: After testing heapify using siftUp and siftDown,
 *         siftDown requires less swaps than siftUp
 */

#include <iostream>

using namespace std;

int swapCount = 0;

void printArray(int list[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

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

// Swapping child with parent if child > parent
// Will not be using since siftDown is more efficient
void siftUp(int list[], int start)
{
  int childIndex = start;

  while(childIndex > 0)
  {
    int parentIndex = parent(childIndex);
    if(list[parentIndex] < list[childIndex])
    {
      swap(list[parentIndex],list[childIndex]);
      swapCount++;
      childIndex = parentIndex;
    }
    else
      return;
  }
}

void siftDown(int list[], int start, int size)
{
  int root = start;

  while(leftChild(root) <= size)
  {
    int childIndex = leftChild(root);
    int swapIndex = root;

    // swapIndex updated with index of left or right child, the greater value
    if(list[swapIndex] < list[childIndex])
    {
      swapIndex = childIndex;
    }
    if(childIndex+1 <= size && list[swapIndex] < list[childIndex+1])
    {
      swapIndex = childIndex+1;
    }

    // if parent is greater than both childs then exit
    // else swap parent with child and update root with child index
    // to continue down the chain until either there are no more 
    // children or parent is greater than children
    if(swapIndex == root)
    {
      return;
    }
    else
    {
      swap(list[root],list[swapIndex]);
      swapCount++;
      root = swapIndex;
    }
  }
}

void heapify(int list[], int size)
{
  // start from the last parent index, iterating to the 0 index
  // while calling siftDown to retain heap property of max heap
  int start = parent(size);
  while(start >= 0)
  {
    siftDown(list,start,size-1);
    start--;
  }
}

void heapsort(int list[], int size)
{
  // call heapify to update the array in place with max heap property
  heapify(list,size);

  // perform sorting using siftDown
  // Since root element always contains the max value, swap with the
  // last index and perform siftDown with the subarray from start to
  // the last swapped element - 1, therefore the next max value will 
  // be at the root and ready for swapping to the end
  int end = size-1;
  while(0 < end)
  {
    swap(list[end],list[0]);
    end--;
    siftDown(list,0,end);
  }
}

int main()
{

  //int list[10] = {10,9,8,7,6,5,4,3,2,1};

  //int list[10] = {1,2,3,4,5,6,7,8,9,10};

  //int list[10] = {1,6,3,7,5,9,4,8,2,10};
  
  int list[10] = {10,2,8,4,9,5,7,3,6,1};
 
  int size = sizeof(list)/sizeof(list[0]);

  cout << "PRINTING LIST BEFORE HEAP SORT" << endl;
  printArray(list,size);

  cout << "CALLING BUBBLE SORT FUNCTION" << endl;
  heapsort(list,size);

  cout << "PRINTING LIST AFTER HEAP SORT" << endl;
  printArray(list,size);

  cout << "NUMBER OF SWAPS: " << swapCount << endl;

  return 0;
}

