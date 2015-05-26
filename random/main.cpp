/*  Written by: Richard Tien
 *  Note: Random Questions
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <limits>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cstdlib>

using namespace std;



void stringReverse(string *str)
{
  int start = 0;
  int end = (*str).length()-1;

  while( start < end )
  {
    int temp = (*str)[start];
    (*str)[start] = (*str)[end];
    (*str)[end] = temp;
    start++;
    end--;
  }

}


void makeZero(int arr[5][5])
{
  bool row[5] = {0,0,0,0,0};
  bool col[5] = {0,0,0,0,0};

  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if(arr[i][j] == 0)
      {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if(row[i] || col[j])
      {
        arr[i][j] = 0;
      }
    }
  }
}

int findKthLargest(int a[10], int b[10], int k)
{
  
  int ptrA = 10-1;
  int ptrB = 10-1;
  int largest = -1;
  int kth = 0;
  while(ptrA >= 0 && ptrB >= 0)
  {
    if(a[ptrA] < b[ptrB])
    {
      largest = b[ptrB];
      ptrB--;
    }
    else if(a[ptrA] > b[ptrB])
    {
      largest = a[ptrA];
      ptrA--;
    }
    kth++;
    if(kth == k)
    {
      return largest;
    }

  }

  while(k > kth)
  {
    if(ptrA < 0)
    {
      largest = b[ptrB];
      ptrB--;
      kth++;
    }
    else if(ptrB < 0)
    {
      largest = a[ptrA];
      ptrA--;
      kth++;
    }
  }

  return largest;
}

int findKthSmallest(int a[10], int b[10], int k)
{
  
  int ptrA = 0;
  int ptrB = 0;
  int smallest = 0;
  int kth = 0;
  
  while(ptrA < 10 && ptrB < 10)
  {
    //cout << ptrA << " - " << ptrB << " _ " << kth << endl;
    
    
    if(a[ptrA] < b[ptrB])
    {
      smallest = a[ptrA];
      ptrA++;
    }
    else
    {
      smallest = b[ptrB];
      ptrB++;
    }
    kth++;
    if(kth == k)
    {
      return smallest;
    }
  }

  while(kth < k)
  {
    if( ptrA >= 10 )
    {
      smallest = b[ptrB];
      ptrB++;
      kth++;
    }
    else if( ptrB >= 10)
    {
      smallest = a[ptrA];
      ptrA++;
      kth++;
    } 
  }


  return smallest;
}




int gcd(int x, int y)
{
  int z;
  while( x != 0 )
  {
    z = x;
    x = y % x;
    y = z;
  }
  return y;
}

int gcdr(int x, int y)
{

  if( x == 0 )
  {
    return y;
  }
  
  return gcdr(y%x,x);
}

int lcm(int x, int y)
{
  int z = abs(x*y);

  int gcd = gcdr(x,y);

  return z/gcd;
}

bool findPairSum(int list[], int sum)
{

  int total = 0;

  for(int i = 0; i < 10; i++)
  {
    for(int j = i+1; j < 10; j++)
    {
      if(list[i] + list[j] == sum)
      {
        return true;                    // sum has been found
      }
    }
  }
  return false;
}


vector<int> findSubSum(vector<int> list, int sum)
{
  int total;
  vector<int>::const_iterator begin = list.begin();
	vector<int>::const_iterator last = list.begin();

  for(int i = 0; i < list.size(); i++)
  {
    if(list[i] == sum)
    {
      cout << "found" << endl;
      vector<int> new_arr(begin+i,begin+1+i);
      return new_arr;
    }
    for(int j = i + 1; j < list.size(); j++)
    {
      total = 0;
      for(int p = i; p <= j; p++)
      {
        total += list[p];
      }

      if(total == sum)
      {
        cout << "found" << endl;
        vector<int> new_arr(begin+i, last+j+1);
        return new_arr;
      }

    }
  }

  cout << "not found" << endl;
  vector<int> ret;
  return ret;
}

int countWays(int n)
{
  if(n < 0)
  {
    return 0;
  }
  else if(n == 0)
  {
    return 1;
  }
  else
  {
    return countWays(n-1)+countWays(n-2)+countWays(n-3);
  }
}

int countWaysDP(int n,int map[])
{
  if(n < 0)
  {
    return 0;
  }
  else if(n == 0)
  {
    return 1;
  }
  else if(map[n] > -1)
  {
    return map[n];
  }
  else
  {
    map[n] = countWaysDP(n-1,map)+countWaysDP(n-2,map)+countWaysDP(n-3,map);
    return map[n];
  }
}

int findMagic(int list[], int start, int end)
{
  if(start>end)
  {
    return -1;
  }

  int mid = (start+end)/2;
  if(list[mid] == mid)
  {
    return mid;
  }
  else if(list[mid] > mid)
  {
    return findMagic(list,start,mid-1);
  }
  else
  {
    return findMagic(list,mid+1,end);
  }
}


void permutations(string str, int start, int length) 
{
  if(start == length-1)
  {
    cout << str << endl;
    return;
  }

  for(int i = start; i < length; i++)
  {
    swap(str[start],str[i]);
    permutations(str,start+1,length);
    swap(str[i],str[start]);
  }
}

vector<int> mergeSortedList(vector<int> a, vector<int> b)
{
  vector<int> ret;

  int p1 = 0;
  int p2 = 0;

  while(p1 < a.size() && p2 < b.size())
  {
    if(a[p1] < b[p2])
    {
      ret.push_back(a[p1]);
      p1++;
    }
    else
    {
      ret.push_back(b[p2]);
      p2++;
    }
  }
  
  while(p1 < a.size())
  {
    ret.push_back(a[p1]);
    p1++;
  }
  
  while(p2 < b.size())
  {
    ret.push_back(b[p2]);
    p2++;
  }


  return ret;
}

// Given a string, convert it into a palindrome with the lease   number of insertions possible. 
int FindMinInsert(string s, int l, int r)
{
  if ( l >= r ) return 0;
  if (s[l] == s[r]) return FindMinInsert(s, l+1, r-1);
     int insert_left = FindMinInsert(s, l, r-1) +1;
     int insert_right = FindMinInsert(s, l+1, r) +1;
     return min(insert_left, insert_right);


}

string incrementString(string str)
{
  int t;
  try {
    t = stoi(str)+1;
  } catch (invalid_argument& e)
  {
    return "Error String is not Alphanumeric";
  }
  return to_string(t);
}

string decrementString(string str)
{
  int t;
  try {
    t = stoi(str)-1;
  } catch (invalid_argument& e)
  {
    return "Error String is not Alphanumeric";
  }
  return to_string(t);
}

bool isPowerTwo(int n)
{
  return ((n & (n-1)) == 0);
}

/*
1                     1               2^0
10                    2               2^1
100                   4               2^2
1000                  8               2^3
10000                 16              2^4
100000                32              2^5
1000000               64              2^6
10000000              128             2^7
100000000             256             2^8
1000000000            512             2^9
10000000000           1024            2^10
100000000000          2048            2^11
1000000000000         4096            2^12
10000000000000        8192            2^13
100000000000000       16384           2^14
1000000000000000      32768           2^15
10000000000000000     65536           2^16
*/

// up to 16 bits
// returns 16 bit representation of a positive int from 0 - (2^16 - 1)
string intToBitString(int n)
{

  if(n >= 65536)
  {
    return "Error int is larger than 2^16 - 1";
  }

  string result = "";
  int power = 32768; // 2^15  //numeric_limits<int>::max();//4294967296;
  int i = 0;
  while(i < 16)
  {
    if( (n-power) >= 0)
    {
      result = result + "1";
      n -= power;
    }
    else
    {
      result = result + "0";
    }
    power /= 2;
    i++;
  }

/*
  string result = "";

  while(n)
  {
    if(n&1)
    {
      result = "1" + result;
    }
    else
    {
      result = "0" + result;
    }
    n = n>>1;
  }
*/
  return result;
}

vector<string> stringSplit(string str, char delim)
{
  vector<string> ret;
  string temp = "";

  for(int i = 0; i < str.size(); i++)
  {
    if(str[i] != delim) 
      temp += str[i];
    else
    {
      ret.push_back(temp);
      temp = "";
    }
  }
  return ret;
}

string encode(vector<string> list)
{
  string ret = "";
  for(int i = 0; i < 10; i++)
  {
    ret = ret + list[i] + " ";
  }
  return ret;
}

vector<string> decode(string s)
{
  vector<string> ret;
  /*
  istringstream ss(s);
  string token;

  while(getline(ss, token, ' ')) 
  {
    ret.push_back(token);
  }
*/

  return stringSplit(s,' ');
}

bool compareStringVector(vector<string> x, vector<string> y)
{
  if(x.size() != y.size()) return false;

  for(int i = 0; i < x.size(); i++)
  {
    if(x[i] != y[i]) return false;
  }
  return true;
}


//O( 2^n )
void printStrings(string str,int start, int end)
{

  if(start <= end)
  {
    int size = end-start;
    cout << str.substr(start,size+1) << endl;

    printStrings(str,start+1,end);
    printStrings(str,start,end-1);
  }
  else
  {
    return;
  }
}

vector<int> inc(vector<int> &list)
{
  int ptr = list.size()-1;

  if(list[ptr] != 9)
  {
    list[ptr]++;
  }
  else
  {
    while(list[ptr] == 9)
    {
      list[ptr--] = 0;
      if(ptr < 0)
      {
        vector<int> newList;
        newList.push_back(1);
        for(int i = 0; i < list.size();i++) newList.push_back(list[i]);
        return newList;
      }

      if(list[ptr] != 9)
      {
        list[ptr]++;
        break;
      }
    }
  }
  return list;
}

void rotate(int nums[], int n, int k)
{
  for(int i = 0; i < k; i++)
  {
    int temp = nums[n-1];
    for(int j = n-1; j > 0; j--)
    {
      nums[j] = nums[j-1];
    }
    nums[0] = temp;
  } 
}

static int myComp(int num1, int num2)
{
  string s1 = to_string(num1) + to_string(num2);
  string s2 = to_string(num2) + to_string(num1);
  bool x = s1 > s2;
  cout << s1 << " " << s2 << " " << x << endl;
  return s1 > s2;
}

string largestNumber(vector<int> &num)
{
  sort(num.begin(), num.end(), myComp);

  for(int i = 0; i < num.size(); i++)
  {
    cout << num[i] << " ";
  }
  cout << endl;
  
  return "hello world";
}

void incc(vector<int> &list)
{
  for(int i = list.size()-1; i >= 0; i--)
  {
    if(list[i] == 9)
    {
      cout << "wtf" << endl;
      list[i] = 0;
      if(i == 0)
      {
        cout << "add 1" << endl;
        break;
      }
    }
    else
    {
      
      list[i]++;
      break;
    }
  }
}

bool isPalindrome(string s)
{
  int start = 0;
  int end = s.length()-1;
        
  while(start <= end)
  {
    if(s[start] != s[end]) return false;
      start++;
      end--;
  }
  return true;
}



string longestPalindrome(string s)
{
  bool table[1000][1000] = {false};

  int max = 0;
  int start = 0;

  for(int len = 0; len < s.length(); len++)
  {
    for(int i = 0; i < s.length() - len; i++)
    {
      if(s[i] == s[len + i])
      {
        if(len < 2 || table[i+1][i + len - 1])
        {
          table[i][i + len] = true;
          if(len > max)
          {
            max = len;
            start = i;
          }
        }
      }
    }
  }

  return s.substr(start,max+1);
}

string convert(string s, int nRows)
{

  if(nRows <= 1) return s;

  string str = "";

  vector<string> table(nRows);

  
  bool dir = true;
  int ptr = 0;
  for(int i = 0; i < s.length(); i++)
  {
    table[ptr] += s[i];
    

    if(dir)
    {
      ptr++;
    }
    else
    {
      ptr--;
    }

    if(ptr%(nRows-1) == 0)
    {
      if(dir) dir = false;
      else dir = true;
    }

    
  }

  for(int i = 0; i < table.size(); i++)
  {
    str.append( table[i] );
  }

  return str;
}


bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> list;

        while(x != 0)
        {
            list.push_back(x%10);
            x /= 10;
        }

        int start = 0;
        int end = list.size()-1;

        while(start<end)
        {
          if(list[start] != list[end]) return false;
          start++;
          end--;
        }
        
        return true;
    }


vector<string> letterCombinations(string digits)
{
  unordered_map<char,vector<string> > table;

  vector<string> one;
  one.push_back("");
  table['1'] = one;

  vector<string> two;
  two.push_back("a");
  two.push_back("b");
  two.push_back("c");
  table['2'] = two;

  vector<string> three;
  three.push_back("d");
  three.push_back("e");
  three.push_back("f");
  table['3'] = three;

  vector<string> four;
  four.push_back("g");
  four.push_back("h");
  four.push_back("i");
  table['4'] = four;

  vector<string> five;
  five.push_back("j");
  five.push_back("k");
  five.push_back("l");
  table['5'] = five;

  vector<string> six;
  six.push_back("m");
  six.push_back("n");
  six.push_back("o");
  table['6'] = six;

  vector<string> seven;
  seven.push_back("p");
  seven.push_back("q");
  seven.push_back("r");
  seven.push_back("s");
  table['7'] = seven;

  vector<string> eight;
  eight.push_back("t");
  eight.push_back("u");
  eight.push_back("v");
  table['8'] = eight;

  vector<string> nine;
  nine.push_back("w");
  nine.push_back("x");
  nine.push_back("y");
  nine.push_back("z");
  table['9'] = nine;

  vector<string> result;
  if(digits.length() == 0) return result;


  result.push_back("");

  for(int i = 0; i < digits.length(); i++)
  {
    vector<string> temp;
    for(int j = 0; j < table[digits[i]].size(); j++)
    {
      for(int k = 0; k < result.size(); k++)
      {
        string t = result[k]+table[digits[i]][j];
        temp.push_back(t);
      }
    }
    result = temp;
  }
  return result;
}

bool isValid(string s) {
        stack<char> stk;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stk.empty()) return false;
                char top = stk.top();
                if(top == '(')
                {
                    if(s[i] == ')')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(top == '{')
                {
                    if(s[i] == '}')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(top == '[')
                {
                    if(s[i] == ']')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if(stk.empty()) return true;
        else return false;
        
    }
    
int removeDuplicates(int A[], int n) {
        
        int length = 1;
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int curr = A[0];
        int currIndex = 1;
        
        for(int runner = 1; runner < n;)
        {
            if(curr == A[runner])
            {
                runner++;
            }
            else
            {
                curr = A[runner];
                A[currIndex] = A[runner];
                currIndex++;
                runner++;
                length++;
            }
        }
        return length;
    }

int removeElement(int A[], int n, int elem) {
        
        if(n == 0) return 0;
        
        int curr;
        int length = 1;
        
        if(A[0] == elem)
        {
            curr = 0;
            length = 0;
        }
        else curr = 1;
        for(int i = 1; i < n; i++)
        { 
            if(A[i] != elem)
            {
                A[curr] = A[i];
                curr++;
                length++;
            }
            
        }
        return length;
    }

vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> result;
        
        result.push_back(-1);
        result.push_back(-1);
        
        
        int start = 0;
        int end = n-1;
        int left;
        int right;
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(A[mid] < target)
            {
                start = mid +1;
            }
            else if(A[mid] > target)
            {
                end = mid -1;
            }
            else
            {
                left = mid;
                right = mid;
                while(0 < left && A[left-1] == target)
                {
                    left--;
                }
                while(right < end && A[right+1] == target)
                {
                    right++;
                }
                
                vector<int> res;
                res.push_back(left);
                res.push_back(right);
                return res;
            }
        }

        return result;
        
    }

void findSum(vector<int> &num, int target, int sum, int start, vector<int> &sol, vector<vector<int> > &result, vector<bool> &visited)
    {
        if(sum == target)
        {
            result.push_back(sol);
            return;
        }
        
        if(sum > target) return;
        
        for(int i = start; i < num.size(); i++)
        {
            if(num[i] <= target && !visited[i])
            {
                //if(i>0 && num[i] == num[i-1] && !visited[i-1]) continue;
                
                visited[i] = true;
                sol.push_back(num[i]);
                sum += num[i];
                findSum(num,target,sum,i,sol,result,visited);
                sum -= num[i];
                visited[i] = false;
                sol.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        
        vector<int> sol;
        vector<vector<int> > result;
        
        vector<bool> visited(num.size(),false);
        
        findSum(num,target,0,0,sol,result,visited);
        
        return result;
    }

  string multiply(string num1, string num2) {
        

        if(num1 == "0" || num2 == "0") return "0";

        string result = "";


        vector<int> table(num1.length() + num2.length(), 0);
        int ptr;
        int carry = 0;
        for(int i = 0; i < num1.length(); i++)
        {
            int x = num1[i] - '0';
            for(int j = 0; j < num2.length(); j++)
            {
                int y = num2[j] - '0';
                ptr = i + j + 1;
                table[ptr] += (x * y);
            }
        }
        
        for(int i = ptr; i >= 0; i--)
        {
          int temp = table[i];
          if(temp >9)
            carry = temp/10;
          else carry = 0;
          table[i] = table[i]%10;
          table[i-1] += carry;
        }

        int start = 0;
        if(table[0] == 0) start = 1;
        for(int i = start; i <= ptr; i++)
        {
            result += to_string(table[i]);
        }
        
        return result;
        
    }

int strStr(char *haystack, char *needle) {
        
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        
        for(int i = 0; i <= hlen - nlen; i++)
        {
            int index = i;
            for(int j = 0; j <= nlen; j++, index++)
            {
                if(j == nlen) return i;
                if(needle[j] != haystack[index]) break;
                if(!haystack[index]) return -1;
            }

        }
        return -1;
    }

void findPermute(vector<int> &num, vector<bool> &visited, vector<int> solution, vector<vector<int> > &result, int start )
    {
        if(start == num.size())
        {
          cout << "return" << endl;
            result.push_back(solution);
            return;
        }
        
        for(int i = 0 ; i < num.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                
                solution.push_back(num[i]);
                //cout << i << "\t" << num[i] << "\t" << start << "\t" << solution.size() << endl;
 
                findPermute(num,visited,solution,result,start+1);
                
                solution.pop_back();
                
                visited[i] = false;
            }
        }
    }




    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int> > result;
        vector<bool> visited(num.size(),false);
        vector<int> solution;
        
        findPermute(num,visited,solution,result,0);
        
        return result;
    }

    void printTable(vector<int> list)
    {
      for(int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
      cout << endl;
    }

int uniquePaths(int m, int n) {
        
        
        vector<int> table(n+1,0);
        
        table[1] = 1;
        printTable(table);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                table[j+1] = table[j] + table[j+1];
                printTable(table);
            }
        }
        return table.back();
        
    }

int main()
{

  cout << uniquePaths(2,2) << endl;

/*
  vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  vector<vector<int> > result = permute(list);

  for(int i = 0; i < result.size(); i++)
  {
    for(int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";

    }
    cout << endl;
  }
*/


  //cout << strStr("mississippi","mississippi") << endl;

  //cout << multiply("123", "123") << endl;

/*
  vector<int> list;
  list.push_back(10);
  list.push_back(1);
  list.push_back(2);
  list.push_back(7);
  list.push_back(6);
  list.push_back(1);
  list.push_back(5);
  list.push_back(1);

  vector<vector<int> > result = combinationSum2(list,8);

  for(int i = 0; i < result.size(); i++)
  {
    for(int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
*/

/*
  int arr[1] = {1};
  //int list[10] = {1,1,1,2,2,2,5,6,7,8};
  vector<int> res = searchRange(arr,1,1);
  //vector<int> res = searchRange(list,10,2);

  for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
*/


/*
  int list[2] = {3,3};

  cout << removeElement(list,2,5) << endl << endl;
*/


  //for(int i = 0; i < 2; i++) cout << list[i] << endl;

  //cout << isValid("]") << endl;
  
  //letterCombinations("23");


/*
  int arr[6] = {-1, 0, 1, 2, -1,-4};
  vector<int> list;
  for(int i = 0; i < 6; i++) list.push_back(arr[i]);

  vector<vector<int> > result = threeSum(list);
  
  for(int i = 0; i < result.size(); i++)
  {
    for(int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
*/

  //cout << isPalindrome(2147447412) << endl;
 
  //cout << convert("abcdefghijklmn",3) << endl;
  
  //cout << longestPalindrome("ababe") << endl;


/*
  int a[5] = {1,9,9,9,9};
  vector<int> list;

  for(int i = 0; i < 5; i++) list.push_back(a[i]);

  incc(list);

  for(int i = 0; i < list.size(); i++) cout << list[i] << " ";
  cout << endl;
*/

/*
  vector<int> list;
  list.push_back(3);
  list.push_back(30);
  list.push_back(34);
  list.push_back(5);
  list.push_back(9);
  
  for(int i = 0; i < list.size(); i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;


  largestNumber(list);
*/

/*
  int list[10] = {1,2,3,4,5,6,7,8,9,10};

  rotate(list,10,4);
*/

  //for(int i = 0; i < 10; i++) cout << list[i] << endl;

/*
  int a[5] = {9,9,9,9,9};
  vector<int> list;

  for(int i = 0; i < 5; i++) list.push_back(a[i]);

  vector<int> newL = inc(list);

  for(int i = 0; i < newL.size();i++)
  {
    cout << newL[i] << " ";
  }

  cout << endl;
*/


/*
  printStrings("abcde",0,2);

  int x = 16;

  int y = ~x;

  cout << y << endl;
*/

/*
  string strList[10] = {"ab","cd","ef","gh","ij","kl","mn","op","qr","st"};
  vector<string> list;

  for(int i = 0; i < 10; i++) list.push_back(strList[i]);

  string encodedStr = encode(list);
  cout << encodedStr << endl;

  vector<string> decodedList = decode(encodedStr);

  for(int i = 0; i < decodedList.size(); i++) cout << decodedList[i] << endl;

  cout << compareStringVector(list,decodedList) << endl;
*/

  //cout << intToBitString(2) << endl;

  //cout << isPowerTwo(32) << endl;

  //cout << incrementString("0") << endl;
  //cout << decrementString("-123") << endl;

  //cout << FindMinInsert("helloworldasdf",0,13) << endl;




  /*

  int * p = new int[2];

  p[0] = 1;
  p[1] = 2;
  string s1 = "hello";
  string s2 = "hello world";
  cout << sizeof(s1) << endl;
  cout << sizeof(s2) << endl;

  cout << "Size of string: " << sizeof(string) << " bytes" << endl;
  cout << "Size of bool: " << sizeof(bool) << " bytes"  << endl;
  cout << "Size of char: " << sizeof(char) << " bytes" << endl;
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes"  << endl;
  cout << "Size of float: " << sizeof(float) << " bytes"  << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes"  << endl;
  */


  /*
  vector<int> a, b;
  
  int aArr[] =  {1,3,5,7,9,11,13,15,17};
  int bArr[] = {2,4,6,8,10,12,14,16,18};
  for(int i = 0; i < 9; i++)
  {
    a.push_back(aArr[i]);
    b.push_back(bArr[i]);
  }

  vector<int> new_list = mergeSortedList(a,b);
  for(int i = 0; i < new_list.size(); i++)
  {
    cout << new_list[i] << endl;
  }
  */

/*
  string str = "abc";
  permutations(str,0,3);
*/

/*
  int list[11] = {-40,-20,-1,1,2,3,5,7,9,12,13};

  cout << findMagic(list,0,10) << endl;
*/

  /*
  cout << countWays(9) << endl;
  int arr[100];
  fill_n(arr,100,-1);
  cout << countWaysDP(9,arr) << endl;
  */

/*
  int arr[11] = {27,1,2,3,4,5,6,7,8,9,10};

  vector<int> list;
  for(int i = 0; i < 11; i++)
    list.push_back(arr[i]);

  vector<int> ret = findSubSum(list,4);

  for(int i = 0; i < ret.size(); i++)
    cout << ret[i] << endl;
*/

/*
  if(findPairSum(arr,19))
    cout << "Pair Sum Found" << endl;
  else
    cout << "Pair Sum Not Found" << endl;
*/

  /*
  cout << gcd(144,12) << endl;
  cout << gcdr(144,12) << endl;
  cout << lcm(144,12) << endl;
  cout << lcm(144,12) * gcd(144,12) << endl;
  */



  /*
  // stringReverse Tester
  string str = "hello world";
  cout << str << endl;
  stringReverse(&str);
  cout << str << endl;
  */

  /*
  int a[10] = {1,5,9,17,34,48,55,75,123,235};
  int b[10] = {2,7,12,23,44,51,63,89,211,333};
  int c[10] = {301,302,303,304,305,306,307,308,309,310};

  for(int i = 1; i <= 20; i++)
  {
    cout << i << " - " << findKthLargest(b,c,i) << endl;
  }
  
  
  for(int i = 1; i <= 20; i++)
  {
    cout << i << " - " << findKthSmallest(a,b,i) << endl;
  }
  */


  //array<int,100> arr = {1,2,3,4,5};
  //cout << arr[0] << endl;

  return 0;
}
