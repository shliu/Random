#include <iostream>
/*
  This program demonstrates operator overloading.
  One instance displays normal op overloading
  Second instance displays friend op overloading
  Third instance display friend ostream op overloading
*/ 

class Time{
private:
  int hours;
  int minutes;
public:
  Time();
  Time(int h, int m = 0);
  Time operator+(const Time & t) const;
  Time operator*(double mult) const;
  friend Time operator*(double mult, const Time & t);
  friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

Time::Time() : hours(0), minutes(0){
  //hours = minutes = 0;
}

Time::Time(int h, int m) : hours(h), minutes(m){
  //hours = h;
  //minutes = m;
}

Time Time::operator+(const Time & t) const{
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator*(double mult) const{
  Time result;
  long totalminutes = hours * mult * 60 + minutes * mult;
  result.hours = totalminutes / 60;
  result.minutes = totalminutes % 60;
  return result;
}

Time operator*(double mult, const Time & t){
  return t * mult;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
  os << t.hours << " hours, " << t.minutes << " minutes";
  return os;
}




int main(int argc, char* argv[]){
  using std::cout;
  using std::endl;
  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planning time = " << planning << endl;

  cout << "coding time = " << coding << endl;

  cout << "fixing time = " << fixing << endl;

  total = coding + fixing;
  cout << "coding + fixing = " << total << endl;

  total = 2 * coding; 
  cout << "2 * coding = " << total << endl;
  return 0;
}





