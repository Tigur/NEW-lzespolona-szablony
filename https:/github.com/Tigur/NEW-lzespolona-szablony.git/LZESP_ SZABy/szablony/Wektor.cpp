



#include "Wektor.h"
#include "rozmiar.h"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

//typ_pol  Wektor<typ>::IloczynSkal( const Wektor<typ> & V2


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



// typ operator + (const Wektor<typ> & V1, const typ d)
// {
//   typ Wynik = 0;
//   for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]+d;
//   return Wynik;
// }

template <class typ>
Wektor<typ> operator - (const Wektor<typ> & V1, const Wektor<typ> & V2)

{
  Wektor<typ> Wynik;
  for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik[Ind] = V1[Ind]-V2[Ind];
  return Wynik;
}


// !!!
// Wektor<typ> operator - (const Wektor<typ> & V1, const typ d)
// {
//   Wektor<typ> Wynik;
//   for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]-d;
//   return Wynik;

template <class typ>
Wektor<typ> operator / (const Wektor<typ> & V1, const typ d)
{
  Wektor<typ> Wynik;
  for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik[Ind] = V1[Ind]/d;
  return Wynik;
}

