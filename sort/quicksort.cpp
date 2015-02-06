/*  Written by: Richard Tien
 */

#include <iostream>

using namespace std;

int iterations = 0;

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

int partition(int list[],int start,int end)
{
  int index = start;

  for(int i = start; i < end; i++)
  {
    iterations++;
    if(list[i] <= list[end])
    {
      swap(list[i],list[index]);
      index++;
    }
  }
  swap(list[index],list[end]);
  return index;
}

void quicksort(int list[],int start,int end)
{
  if(start < end)
  {
    int index = partition(list,start,end);
    quicksort(list,start,index-1);
    quicksort(list,index+1,end);
  }
}

int main()
{
  //int list[10] = {10,9,8,7,6,5,4,3,2,1};

  //int list[10] = {1,2,3,4,5,6,7,8,9,10};

  //int list[10] = {1,6,3,7,5,9,4,8,2,10};
  
  int list[10] = {10,2,8,4,9,5,7,3,6,1};

  int size = sizeof(list)/sizeof(list[0]);

  cout << "PRINTING LIST BEFORE QUICKSORT" << endl;
  printArray(list,size);

  cout << "CALLING BUBBLE SORT FUNCTION" << endl;
  quicksort(list,0,size-1);


  cout << "PRINTING LIST AFTER QUICKSORT" << endl;
  printArray(list,size);

  cout << "NUMBER OF ITERATIONS : " << iterations << endl;

  return 0;
}

