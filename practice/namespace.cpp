#include <iostream>
namespace say{
  void hello(){
    std::cout << "hello world" << std::endl;
  }
}

int main(){
  say::hello();
  return 0;
}
