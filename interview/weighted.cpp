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

class Vertex
{
  public:
    int value;
    Vertex(int n) : value(n) {}
};

class Obj
{
  public:
    Obj * getInstance()
    {
      if(!instance)
      {
        instance = new Obj();
      }
      return instance;
    }

  private:
    static Obj * instance;
};

    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        int result = 0;
        for(int i = 0; i < height.size()-1; i++)
        {
            for(int j = i+1; j < height.size(); j++)
            {
                if(right[i] < height[j])
                {
                  right[i] = height[j];
                }
            }
        }

        for(int i = height.size()-1; i > 0; i--)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(left[i] < height[j])
                {

                  left[i] = height[j];
                }
            }
        }


        
        for(int i = 0; i < height.size(); i++)
        {
            int min = std::min(left[i],right[i]);
            if(min > height[i]) result += min - height[i];
        }
        return result;
        
        
    }

int main()
{
  vector<int> list;
  //[0,1,0,2,1,0,1,3,2,1,2,1]
  list.push_back(0);
  list.push_back(1);
  list.push_back(0);
  list.push_back(2);
  list.push_back(1);
  list.push_back(0);
  list.push_back(1);
  list.push_back(3);
  list.push_back(2);
  list.push_back(1);
  list.push_back(2);
  list.push_back(1);

  cout << trap(list) << endl;

  return 0;
}

