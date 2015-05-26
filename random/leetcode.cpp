#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>



using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
  vector<int> result;
  unordered_map<int, int> mapping;

  for(int i = 0; i < numbers.size(); i++)
  {
    mapping[numbers[i]] = i;
  }
  for(int i = 0; i < numbers.size(); i++)
  {
    const int gap = target - numbers[i];
    if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
    {
      result.push_back(i + 1);
      result.push_back(mapping[gap] + 1);
      break;
    }
  }

  return result;
}


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


int main()
{

  cout << lengthOfLongestSubstring("abcabcbb") << endl;

}



