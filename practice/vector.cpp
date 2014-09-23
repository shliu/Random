#include <iostream>
#include <vector>

void Show(const int x){
  std::cout << x;
}


int main(){
  using namespace std;

  vector<int> my_vec({1,123,32,12,321});;

  for_each(my_vec.begin(), my_vec.end(), Show);
  return 0;
}
