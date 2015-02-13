/*  Written by: Richard Tien
 *  Note:  
 */
 
#include <iostream>

using namespace std;

int fibRec(int n)
{
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
    return fibRec(n-2)+fibRec(n-1);
}

int fibIter(int n)
{
  if(n == 0)
  {
    return 0;
  }

  int prev = 0;
  int curr = 1;
  int next = 1;
  for(int i = 1; i < n; i++)
  {
    next = prev + curr;
    prev = curr;
    curr = next;
  }
  
  return next;
}

int main()
{
  int input;
  cout << "Enter an integer for fibonacci: ";
  cin >> input;
  cout << "recursive Fib: " << fibRec(input) << endl;
  cout << "iterative Fib: " << fibIter(input) << endl;

  return 0;
}
