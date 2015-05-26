#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
  if(s.length() <= 1)
  {
    return s.length();
  } 

  bool letter[256] = {false};
  int prev = 0;
  int length = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if(!letter[s[i]])
    {
      letter[s[i]] = true;
    }
    else
    {
      while(s[prev] != s[i])
      {
        letter[s[prev]] = false;
        prev++;
      }
      prev++;
    }
    length = max(length,i-prev+1);
  
  }
  return length;
}

int countPrimes(int n) {
        int count = 0;

        vector<bool> visited(n,false);
        
        for(int i = 2; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                visited[i] = true;
                int j = i;
                while(j < n)
                {
                    j += i;
                    visited[j] = true;
                }
            }
            
        }
        
        return count;
}


bool isIsomorphic(string s, string t) {
        unordered_map<char,char> l;
        unordered_map<char,char> r;

        for(int i = 0; i < s.length(); i++)
        {
          if(l.find(t[i]) != l.end() && l[t[i]] != s[i])
          {
            return false;
          }
          else
          {
            l[t[i]] = s[i];
          }

          if(r.find(s[i]) != r.end() && r[s[i]] != t[i])
          {
            return false;
          }
          else
          {
            r[s[i]] = t[i];
          }

        }




        return true;
    }

bool isHappy(int n) {
        unordered_set<int> set;

        while(n != 1)
        {
            if(set.find(n) != set.end()) return false;
            else set.insert(n);
            int sum = 0;
            cout << n << endl;
            while(n != 0)
            {
                int x = n%10;
                x = x * x;
                sum += x;
                n = n / 10;
            }
            n = sum;
        }
        return true;
        
    }

uint32_t reverseBits(uint32_t n) {
        stack<int> stk;
        int result = 0;
        for(int i = 0; i < 32; i++)
        {
            int x = n & 1;
            cout << x;
            stk.push(x);
            n = n >> 1;

            result = result << 1;
            result = result | x;
        }
        return result;
    }

bool compare(string s1, string s2)
{
  return s1 + s2 > s2 + s1;
}

int titleToNumber(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
          cout << s[i] << "\t" << pow(26,s.length()-i-1) << endl;
            count += (s[i] - 'A' + 1) * pow(26,s.length()-i-1);
        }
        return count;
    }

    int compareVersion(string version1, string version2) {
        string v1pre = "";
        string v1post = "";
        string v2pre = "";
        string v2post = "";
        

        for(int i = 0; i < version1.length(); i++)
        {
            if(version1[i] != '.')
            {
                v1pre += version1[i];
            }
            else
            {
                for(int j = i+1; j < version1.length(); j++)
                {
                    v1post += version1[j];
                }
                break;
            }
        }
        
        for(int i = 0; i < version2.length(); i++)
        {
            if(version2[i] != '.')
            {
                v2pre += version2[i];
            }
            else
            {
                for(int j = i+1; j < version2.length(); j++)
                {
                    v2post += version2[j];
                }
                break;
            }
        }

        //cout << v1pre << "." << v1post << endl;
        //cout << v2pre << "." << v2post << endl;
        
        /*
        int v1prei = stoi(v1pre);
        int v2prei = stoi(v2pre);
        int v1posti = stoi(v1post);
        int v2posti = stoi(v2post);
        */
        if(v1pre > v2pre) return -1;
        else if(v1pre < v2pre) return 1;
        else
        {
            if(v1post > v2post) return -1;
            else if(v1post < v2post) return 1;
            else return 0;
        }
    }

void removeDuplicates(int list[], int size)
{
  
  int ptr = 1;
  for(int i = 1; i < size; i++)
  {
    if(list[i-1] != list[i])
    {
      list[ptr] = list[i];
      ptr++;
    }
  }

}
 
int main()
{
   cout << lengthOfLongestSubstring("abcbdefg") << endl;

   cout << "PRIME: " << countPrimes(10000) << endl;

   cout << "isIsomorphic: " << isIsomorphic("ab","aa") << endl;

   cout << "isHappy: " << isHappy(19) << endl;

   cout << "ReverseBit: " << reverseBits(1) << endl;

   cout << "titleToNumber: " << titleToNumber("BA") << endl;

   cout << "compareVersion: " << compareVersion("1","0") << endl;

   //int list[] = {1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 6, 6, 6,7,7,7,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
   //int list[] = {1,2,3,4,5,6,7,8,9};
   int list[] = {1};
   removeDuplicates(list,1);
   
  for(int i = 0; i < 1; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;


   return 0;
}

