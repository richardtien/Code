/*  Written by: Richard Tien
 *  Note:  
 */
 
#include <iostream>

using namespace std;

int factorialRec(int n)
{
  if(n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * factorialRec(n-1);
  }
}

int factorialIter(int n)
{
  if(n == 0)
  {
    return 1;
  }

  int value = 1;
  for(int i = 2; i <= n; i++)
  {
    value *= i;
  }
  return value;
}

int main()
{
  int input;
  cout << "Enter an integer for factorial: ";
  cin >> input;
  cout << "recursive Factorial " << factorialRec(input) << endl;
  cout << "iterative Factorial: " << factorialIter(input) << endl;

  return 0;
}
