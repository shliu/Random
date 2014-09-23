#include <iostream>
using namespace std;

/*
  the virtual keyword seems to be the same as "look down at my children"
  if there was no virtual keyword, and the same method exists in both
  parent and child, calling the method on a polymorphic object would
  invoke the parent's method
*/

class base{
public:
  base(){
    cout << "base construct" << endl;
  }
  virtual ~base(){
    cout << "base destruct" << endl;
  }
  void hello(){cout << "bye" << endl;};
  //virtual void hello()=0;
};


class child : public base{
public:
  child(){
    cout << "child construct" << endl;
  } 
  ~child(){
    cout << "child destruct" << endl;
  }
  void hello(){cout << "hello" << endl;}

};

int main(){

  
  {
  base* kid;
  kid = new child;
  kid->hello();
  (*kid).hello();
  delete kid;
  }

  cout << endl;

  {
  child kid2;
  }





  return 0;
}
