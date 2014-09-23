#include <iostream>
#include <list>
#include <iomanip>



int main(){
  std::list<int> ml;
  std::list<int>::iterator i;

  i = ml.begin();
  ml.insert(i, 0);
  i++;
  ml.insert(i, 1);
  i++;
  ml.insert(i, 2);
  for(std::list<int>::iterator ii=ml.begin(); ii!=ml.end(); ii++)
    std::cout << *ii << " ";
  std::cout << std::endl << "---------------" << std::endl;

  /*
  i = ml.begin();
  int j = 0;
  for(j=0; j<10; j++){
    std::cout << "i at: " << std::setw(10) << *i << " | ";
    ml.insert(i, j);
    std::cout << "Inserting " << j << " to my left | ";
    i++;
    std::cout << "After i++, i at " << *i;
    //std::cout << " back = " << (ml.back());

    std::cout << std::endl << "   ";
    for(std::list<int>::iterator ii=ml.begin(); ii!=ml.end(); ii++)
      std::cout << *ii << " ";
    std::cout << std::endl << "---------------" << std::endl;
  }
  */

  /*
  for(int j=1; j<10; j++)
    ml.push_back(j);

  std::list<int>::iterator ii=ml.begin();
  for(; ii!=ml.end(); ii++)
    std::cout << *ii << " ";
  std::cout << std::endl;
  ii++;
  std::cout << *ii << " ";
  ii++;
  std::cout << *ii << " ";
  ii++;
  std::cout << *ii << " ";
  std::cout << std::endl;
  */ 

  return 0;
}
