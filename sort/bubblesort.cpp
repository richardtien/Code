/*  Written by: Richard Tien
 */

#include <iostream>

using namespace std;

void printArray(int list[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int size)
{
  for(int i = 0; i < size-1; i++)
  {
    cout << "********************" << "\t number of iterations: " << size - i - 1 << endl;
    for( int j = 0; j < size - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(&arr[j],&arr[j+1]);
      }
      printArray(arr,size);
    }
  }
}

int main()
{

  //int list[10] = {10,9,8,7,6,5,4,3,2,1};

  //int list[10] = {1,2,3,4,5,6,7,8,9,10};

  //int list[10] = {1,6,3,7,5,9,4,8,2,10};
  
  int list[10] = {10,2,8,4,9,5,7,3,6,1};
 
  int size = sizeof(list)/sizeof(list[0]);

  cout << "PRINTING LIST BEFORE BUBBLE SORT" << endl;
  printArray(list,size);

  cout << "CALLING BUBBLE SORT FUNCTION" << endl;
  bubbleSort(list,size);

  cout << "PRINTING LIST AFTER BUBBLE SORT" << endl;
  printArray(list,size);

  return 0;
}

