#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH



#include <iostream>





class LZespolona {
  double  _re;
  double  _im;


public:
 
  LZespolona();

  double  Re() const;

  double& Re();

  double  Im() const;
  
  double& Im();
  
  LZespolona  operator + (const LZespolona&  Arg2) const;
  
  LZespolona  operator * (const LZespolona&  Arg2) const;
};


std::ostream&  operator << ( std::ostream&  wyjscie ,const LZespolona& Liczba);

std :: istream & operator >> ( std :: istream & wejscie, LZespolona & Liczba);








/*                              ZLE ! PROBA TWORZENIA SZABLONU !

class LZespolona 
{

  typ _re;
  typ _im;

  public:
  typ    Re() const { return _re; }

  typ &  Re() {return (*this)._re;}

  typ   Im() const { return (*this)._im;}
  
  typ &  Im() { return (*this)._im;}
  
  LZespolona   operator + (const LZespolona&  Arg2) const
  {
    LZespolona wynik;
    wynik.Re()= (*this).Re() + Arg2.Re();


    return wynik;
  }
  
  LZespolona  operator * (const LZespolona&  Arg2) const
  {
    LZespolona wynik;
    wynik.Re()= (*this).Re() + Arg2.Re();

    return wynik;
  }

};




std :: ostream& operator << ( std :: ostream & wyjscie, const LZespolona<typ>& Liczba)
{
  wyjscie <<"{ " << Liczba.Re() << " + "<< Liczba.Im() << "i }"<< endl;
  

  
}


std :: istream & operator >> ( std :: istream & wejscie, LZespolona<typ> & Liczba)
{
  typ licz;
  char klamra, i, plus_minus;
  wejscie >> Liczba.Re();
      wejscie >> plus;
    wejscie >>Liczba.Im();
    wejscie >> i;
    
    if (plus_minus!='+'||plus_minus!='-'){ cerr << " zle wprowadzono znak  miedzy czescia rzeczywista a zespolona ! " << endl;}
      if (i!='i'){cerr<< " czesc zespolona musi zawierac znak i"<< endl; }
    
    
}




*/

#endif
