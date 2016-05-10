#ifndef WEKTOR_H
#define WEKTOR_H


 

#include "rozmiar.h"
#include <iostream>

using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template <class typ_pol>
class Wektor {

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */





  typ_pol Wsp[ROZMIAR];

 public:
  typ_pol operator[]  (int Ind) const { return Wsp[Ind]; }
  typ_pol & operator[]  (int Ind) { return Wsp[Ind]; }
  typ_pol operator & (const Wektor < typ_pol > & V2) const;
  typ_pol  IloczynSkal( const Wektor < typ_pol > & V2 ) const
  {

    typ_pol Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += (*this)[Ind]*V2[Ind];
    return Wynik;
  }
 // float  operator * ( const Wektor & V1, const Wektor & V2) {return V1.IloczynSkal(V2);}

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
};





















template <class typ>
inline typ  operator * ( const Wektor<typ> & V1, const Wektor<typ> & V2) {return V1.IloczynSkal(V2);}
// -------------------------------------------------------------------------------------------------------------------------------------








template <class typ>
istream & operator >> (istream & wejscie, Wektor<typ> & W)
{
  typ r0,r1,r2;
  cout << "Wprowadz 3 wspolzedne Wektora w kolejnosci: r0, r1, r2"<< endl;
  wejscie>> r0>> r1 >> r2;
  W[0]=r0; W[1]=r1; W[2]=r2;

  return wejscie;

}

template <class typ>
ostream & operator << (ostream & wyjscie, const Wektor<typ> & W)

{
  cout << W[0] << "  "
       << W[1] << "  "
       <<W[2] << endl;

  return wyjscie;

}
template <class typ>
Wektor<typ>  operator * ( const Wektor<typ> & V1, const typ d)



{
  Wektor<typ> Wynik;
  for (int Ind=0;Ind<ROZMIAR;++Ind) // sprawdziæ czy nie crushuje
    Wynik[Ind] =V1[Ind]*d;

  return Wynik;

}

template <class typ>
Wektor<typ> operator + (const Wektor<typ> & V1, const Wektor<typ> & V2)

{
  Wektor<typ> Wynik;
  for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik[Ind] = V1[Ind]+V2[Ind];
  return Wynik;
}



//float operator + (const Wektor & V1, const typ_pol d);




template <class typ>
Wektor<typ> operator - (const Wektor<typ> & V1, const Wektor<typ> & V2)

{
  Wektor<typ> Wynik;
  for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik[Ind] = V1[Ind]-V2[Ind];
  return Wynik;
}


//float operator - (const Wektor & V1, const typ_pol d);




template <class typ>
Wektor<typ> operator / (const Wektor<typ> & V1, const typ d)
{
  Wektor<typ> Wynik;
  for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik[Ind] = V1[Ind]/d;
  return Wynik;
}



#endif

