// multimap::equal_elements
#include <iostream>
#include <map>
using namespace std;

int main ()
{
  multimap<char,int> mymm;
  multimap<char,int>::iterator it;
  pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret;

  mymm.insert(pair<char,int>('a',10));
  mymm.insert(pair<char,int>('b',20));
  mymm.insert(pair<char,int>('b',30));
  mymm.insert(pair<char,int>('b',40));
  mymm.insert(pair<char,int>('c',50));
  mymm.insert(pair<char,int>('c',60));
  mymm.insert(pair<char,int>('d',60));

  cout << "mymm contains:\n";
  for (char ch='a'; ch<='d'; ch++)
  {
    cout << ch << " =>";
    ret = mymm.equal_range(ch);
    for (it=ret.first; it!=ret.second; ++it)
      cout << " " << (*it).second;
    cout << endl;
  }

  return 0;
}