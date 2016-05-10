#include <iostream>
#include "lzespolonaa.hh"

using namespace std;

/*
  LZespolona()
  {
    (*this)._re=0;
    (*this)._im=0;
  }
*/



double LZespolona::   Re() const { return _re; }

double & LZespolona:: Re() {return (*this)._re;}

double LZespolona::  Im() const { return (*this)._im;}
  
double & LZespolona:: Im() { return (*this)._im;}
  
LZespolona LZespolona::  operator + (const LZespolona&  Arg2) const
{
  LZespolona wynik;
  wynik.Re()= (*this).Re() + Arg2.Re();


  return wynik;
}
  
LZespolona LZespolona ::  operator * (const LZespolona&  Arg2) const
{
 LZespolona wynik;
  wynik.Re()= (*this).Re() + Arg2.Re();

  return wynik;
}

ostream& operator << ( ostream & wyjscie, const LZespolona& Liczba)
{
  wyjscie <<"{ " << Liczba.Re() << " + "<< Liczba.Im() << "i }"<< endl;
  

  return wyjscie; 
}


std :: istream & operator >> ( std :: istream & wejscie, LZespolona & Liczba)
{
    LZespolona licz;
  char klamra, i, plus_minus;
  wejscie >> klamra;
  wejscie >> Liczba.Re();
      wejscie >> plus_minus;
    wejscie >>Liczba.Im();
    wejscie >> i;
    wejscie >> klamra;
    
    if (plus_minus!='+'||plus_minus!='-'){ cerr << " zle wprowadzono znak  miedzy czescia rzeczywista a zespolona ! " << endl;}
      if (i!='i'){cerr<< " czesc zespolona musi zawierac znak i"<< endl; }
  
      return wejscie;
}
