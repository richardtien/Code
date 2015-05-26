#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>

using namespace std;


// Chapter 1.1
bool isUnique(string str)
{
  if(str.length() > 128) return false;

  bool list[128] = {false};

  for(int i = 0; i < str.length(); i++)
  {
    if(list[str[i]])
    {
      return false;
    }
    else
    {
      list[str[i]] = true;
    }
  }
  return true;
}

// Chapter 1.2
void reverseString(char * str)
{

  char * ptr = str;
  char temp;
  while(*ptr)
  {
    ptr++;
  }
  ptr--;

  char * start = str;

  while(start < ptr)
  {
    temp = *start;

    *start = *ptr;
    *ptr = temp;

    start++;
    ptr--;
  }
}

// Chapter 1.3
bool permutation(string s1, string s2)
{
  // Way 1
  /*
  sort(s1.begin(),s1.end());  // takes O(n log n)
  sort(s2.begin(),s2.end());  // takes O(n log n)
  return !s1.compare(s2);     // takes O( n ) so this is a O(n log n) algorithm
  */

  // Way 2 (This algorithm takes O( n ), and constant space
  if(s1.length() != s2.length()) return false;

  int list[128] = {0};

  for(int i = 0; i < s1.length(); i++)
  {
    list[s1[i]]++;
  }

  for(int i = 0; i < s2.length(); i++)
  {
    list[s2[i]]--;
    if(list[s2[i]] < 0) return false;
  }

  return true;
}

// Chapter 1.4
void replaceSpaces(char str[], int len)
{
  int spaces = 0;

  for(int i = 0; i < len; i++)
  {
    if(str[i] == ' ') spaces++;
  }

  int newLen = len + (spaces*2);

  str[newLen--] = '\0';

  for(int i = len-1; i > 0; i--)
  {
    if(str[i] != ' ')
    {
      str[newLen] = str[i];
      newLen--;
    }
    else
    {
      str[newLen--] = '0';
      str[newLen--] = '2';
      str[newLen--] = '%';
    }
  }
}


// Chapter 1.5
string compress(string str)
{
  string result = "";
  char curr = str[0];
  int count = 1;

  for(int i = 1; i < str.length(); i++)
  {
    if(str[i] != curr)
    {
      result = result + curr + to_string(count);
      count = 1;
      curr = str[i];
    }
    else
    {
      count++;
    }
  }
  result = result + curr + to_string(count);

  if(str.length() < result.length())
    return str;
  else
    return result;
}

// Chapter 1.6
void rotate(vector<vector<int> > & matrix)
{
  int n = matrix.size();

  for(int i = 0; i < n/2; i++)
  {
    int last = n - 1 - i;
    for(int j = i; j < last; j++)
    {
      int offset = j - i;
      int top = matrix[i][j];

      matrix[i][j] = matrix[last-offset][i]; // top = left

      matrix[last-offset][i] = matrix[last][last-offset];  // left = bottom

      matrix[last][last-offset] = matrix[j][last];  // bottom = right

      matrix[j][last] = top;  // right = top;
    }
  }
}

// Chapter 1.7
void zeroMatrix(vector<vector<int> > & matrix)
{
  vector<bool> row(matrix.size());

  vector<bool> col(matrix[0].size());


  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix[i].size(); j++)
    {
      if(matrix[i][j] == 0)
      {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix[i].size(); j++)
    {
      if(row[i] || col[j])
      {
        matrix[i][j] = 0;
      }
    }
  }
}

// Chapter 1.8
bool isSubstring(string s1, string s2)    // helper function
{
  if(s2.length() > s1.length()) return false;

  int end  = s1.length() - s2.length();

  for(int i = 0; i <= end; i++)
  {
    int start = i;
    int j = 0;
    while(s1[start] == s2[j])
    {
      start++;
      j++;
      if(j == s2.length()) return true;
    }
  }

  return false;
}

bool isRotation(string s1, string s2)
{
  return isSubstring(s1+s1,s2);
}



int main()
{
  
  // Chapter 1.1 Tester
  if(isUnique("abc")) cout << "unique" << endl;
  else cout << "not unique" << endl;

  // Chapter 1.2 Tester
  string a = "abcdefg\0";
  cout << a;
  reverseString((char*) a.c_str());
  cout << "\t" << a << endl;

  // Chapter 1.3 Tester
  string b = "cork";
  string c = "rock";

  if(permutation(b,c)) cout << "permutation" << endl;
  else cout << "not permutation" << endl;

  // Chapter 1.4 Tester
  char d[] = "Mr John Smith            ";
  replaceSpaces(d,13);
  cout << d << endl;

  // Chapter 1.5 Tester
  string e = "aabcccccaaa";
  cout << e << "\t" << compress(e) << endl;

  // Chapter 1.6 Tester
  vector<int> f;
  vector<int> g;
  vector<int> h;
  vector<int> i;
  vector<int> j;
  vector<vector<int> > k;

  f.push_back(1);  f.push_back(2);  f.push_back(3);  f.push_back(4);
  g.push_back(5);  g.push_back(6);  g.push_back(7);  g.push_back(8);
  h.push_back(9);  h.push_back(10);  h.push_back(11);  h.push_back(12);
  i.push_back(13);  i.push_back(14);  i.push_back(15);  i.push_back(16);
  j.push_back(17);  j.push_back(18);  j.push_back(19);  j.push_back(20);
  k.push_back(f);  k.push_back(g);  k.push_back(i);  k.push_back(j);

  for(int i = 0; i < k.size(); i++)
  {
    for(int j = 0; j < k[i].size(); j++)
      cout << k[i][j] << "\t";
    cout << endl;
  }
  cout << endl;

  rotate(k);

  for(int i = 0; i < k.size(); i++)
  {
    for(int j = 0; j < k[i].size(); j++)
      cout << k[i][j] << "\t";
    cout << endl;
  }

  // Chapter 1.7 Tester

  // Chapter 1.8 Tester
  string l = "waterbottle";
  string m = "erbottlewat";
  string n = "asdfghj";

  if(isRotation(l,m)) cout << "rotated" << endl;
  else  cout << "not rotated" << endl;

  return 0;
}

