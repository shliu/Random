#include <iostream>

class Test{
private:
  static int m_val;
public:
  Test(){++m_val;};
  ~Test(){--m_val;};
  static int Show(){return m_val;};
};

int Test::m_val = 0;


int main(){
  std::cout << Test::Show() << std::endl;
  {
    Test obj1, obj2;
    std::cout << Test::Show() << std::endl;
  }
  std::cout << Test::Show() << std::endl;
}
