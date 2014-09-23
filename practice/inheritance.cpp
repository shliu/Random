#include <iostream>

class Animal{
public:
  virtual ~Animal(){};
  virtual void Eat() = 0;
  virtual void Move( int direction ) = 0;
};



class Cat : public Animal{
public:
  ~Cat(){};
  void Eat(){
    std::cout << "Omnomnom" << std::endl;
  }
  void Move( int direction ){
    std::cout << "Kitty moves ";
    switch (direction){
      case 1:
        std::cout << "North";
        break;
      case 2:
        std::cout << "East";
        break;
      case 3:
        std::cout << "South";
        break;
      case 4:
        std::cout << "West";
        break;
    }
  }
};



class Dog : public Animal{
public:
  ~Dog(){};
  void Eat(){
    std::cout << "wolfwolf" << std::endl;
  }
  void Move( int direction ){
    std::cout << "Puppy moves ";
    switch (direction){
      case 1:
        std::cout << "North";
        break;
      case 2:
        std::cout << "East";
        break;
      case 3:
        std::cout << "South";
        break;
      case 4:
        std::cout << "West";
        break;
    }
  }
};



int main(){
  /*
  Animal array[2] = {new Cat, new Dog};
  array[0].Eat();
  array[1].Eat();
  return 0;
  */
  Dog mydog;
  Cat mycat;

  mydog.Eat();
  mycat.Eat();
}
