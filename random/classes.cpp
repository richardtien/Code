
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>


using namespace std;


class A
{
  public:
    A()
    {
      cout << "Constructor A" << endl;
    }

    virtual void print()
    {
      cout << "Print from A" << endl;
    }

    virtual void abs() = 0;
};

class B : public A
{
  public:
    B()
    {
      cout << "Constructor B" << endl;
    }

    void print()
    {
      cout << "Print from B" << endl;
    }

    static void woot()
    {
      cout << "static" << endl;
    }

    void abs() {}
};

int main()
{

  //A * a = new A();
  cout << "*************" << endl;
  A * b = new B();
  cout << "*************" << endl;
  
  //a->print();

  b->print();

  B::woot();





}



