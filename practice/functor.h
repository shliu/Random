class Functor{
private:
  //member data goes here
  double y;
  int myint;
public:
  Functor(double x):y(x){};
  double operator()(*double x){return x*y};//
  void sety();
};


Functor f(2);
double y = f(3);


//functor is an object taht acts like a function, but can contain member data
