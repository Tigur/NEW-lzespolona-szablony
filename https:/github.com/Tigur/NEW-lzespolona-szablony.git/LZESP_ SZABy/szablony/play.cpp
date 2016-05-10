#include <iostream>
#include <cstdio>

#include "Macierz.hh"
#include "Wektor.h"

using namespace std;
int main ()
{

  Wektor <float> Wek1, Wek2;
  float c=4.5;

  cin>>Wek1 >>Wek2;
  cout << "wektor 1 :\n"<< Wek1<<"\n"<< endl;
  cout << "wektor 2 :\n"<< Wek2<<"\n"<< endl;
  cout << "wektor 1 + 2 :\n"<< Wek1 + Wek2<<"\n"<< endl;
  cout << "wektor 1 -2 :\n"<< Wek1 -Wek2<<"\n"<< endl;
  cout << "wektor 1 * "<< c << "  :\n"<< Wek1*c<<"\n"<< endl;  


}
