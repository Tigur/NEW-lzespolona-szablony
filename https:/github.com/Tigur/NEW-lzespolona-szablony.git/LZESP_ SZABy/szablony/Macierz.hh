 
#ifndef MACIERZ_HH
#define MACIERZ_HH

#include<cassert>
#include<cstdlib>
#include "Wektor.h"
#include "rozmiar.h"
//#include"UkladRownanLiniowych.hh"
#include <iostream>
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <class typ_pol>
class Macierz {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

public:
	Wektor<typ_pol> Kolumna[ROZMIAR];
    const Wektor<typ_pol> & operator[] (int Kol) const { return Kolumna[Kol]; }
    Wektor<typ_pol> & operator[] (int Kol) { return Kolumna[Kol]; }
    const typ_pol operator() (int Wi, int Ko) const {return Kolumna[Ko][Wi];}
    typ_pol& operator() (int Wi, int Ko) {return Kolumna[Ko][Wi];}
  /*
  Macierz & operator / (typ_pol d)
		{
			for (int i=0;i<ROZMIAR;i++)
			{
				(*this)[i]=(*this)[i]/d;
			}

    		return (*this);
		}
  */
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

  //    int i=0; // index w rozwinięciu La place'a
  




  bool  ZamienKolumny ( int i, int j)
  {
  if ((*this)(i,i) != 0) return true;
  
  Macierz<typ_pol> Mp=(*this);
  
  for(int j=ROZMIAR-1; j>i; j--)
    {


		  if ((*this)(i,j)!=0)
		{
		  (*this)[i]=(*this)[j];
		  (*this)[j]=Mp[i];

		  return true;
		}


    }
  cout << "Macierz nie ma rozwiazan !  " << endl;
  abort();
  return false;
}
  
  
 
  //  Wektor<typ> & AlgorytmLiczenia ();

  
  Wektor<typ_pol>  Zjedynkuj ( int i, int & zamian_kol) 
    {
      Wektor<typ_pol> podzielony;
      
		 if ( (*this)(i,i)!=0)  // unikamy dzielenia przez zero. rozpatrujemy przypadek
		 {
		   podzielony= (*this)[i]/(*this)(i,i); // jedynkuje - czyli dziele przez identyczna wartosc cala kolmne.
				return podzielony;
		 }
		else
		 {

			if (ZamienKolumny (i))
			{
			  zamian_kol++;

				cout << "Zamiana kolumn udana :)" << endl;
				cout << " po zamianie " << endl;
				(*this).WypiszMacierz();
				cout << "\n\n";

				podzielony= (*this)[i]/(*this)(i,i);
				


			}
			else
			{
			cerr<< "WYZNACZIK GŁOWNY = 0"<< endl;
			abort();
			}
			return podzielony;
		 }
      assert(0);
    }

  Macierz &  Wyzerujprawo ( int i, Wektor<typ_pol> podzielony)
      {

		  for(int j=ROZMIAR-1;j>i;j--)
		{
		  (*this)[j]=(*this)[j]-(podzielony*(*this)(i,j));

		}
		  cout<< "Wyzerowane"<< endl;
		  cout<< "po Wyzerowaniu: \n"<< endl;
		  (*this).WypiszMacierz();

      return (*this);
    }
    
    
  void WypiszMacierz() const
  {

	int i=0,j=0;


	for ( i=0;i<ROZMIAR;i++)
	{
		for ( j=0;j<ROZMIAR;j++)
			{cout << (*this)(i,j)<< "  ";}


		cout << "Linia "<< i<< endl;
	}
	cout<< "\n"<< endl;
  }

};

template <class typ>     
void WstawWolny(Macierz<typ> & M, Wektor<typ> wolny, int pozycja)
{
  M[pozycja]=wolny;

  
}

template <class typ>
inline typ & LiczWyzn(Macierz<typ> M, typ & w, int zamian_kol)                                            ////LICZ!!!!!!
    {
    	 w=1; // liczba neutralna względem mnozenia

		  for (int i=ROZMIAR-1;i>=0;i--)
		{
		  w=w*M(i,i);
		}
		  if(zamian_kol%2)
		    w=w*(-1);
	return w;

    }
template <class typ>
typ MacierzoweSzarady(Macierz<typ> M, typ& wyz)
{
  int wiersz=0,kolumna=0;
  // Macierz<typ> Mpomoc;
  Wektor<typ>  W_jed;
  int zamian_kol=0;
  
  while(wiersz<ROZMIAR)
    {
      W_jed = M.Zjedynkuj(wiersz,zamian_kol);
	 // cout << " po jedynkowaniu : \n"<< endl;

	  M.Wyzerujprawo(wiersz,W_jed);
	  //cout << "po zerowaniu : \n"<< endl;



     wiersz++;
    }

  cout << LiczWyzn(M,wyz,zamian_kol)<< "   - Wyznacznik... macierz : "<< endl;
  M.WypiszMacierz();

    return wyz;
}

template <class typ>
void LiczenieNiewiadomych(Wektor<typ> & X,typ TabNiewiadomych[])
{
  X[0]=TabNiewiadomych[1]/TabNiewiadomych[0];
  X[1]=TabNiewiadomych[2]/TabNiewiadomych[0];
  X[2]=TabNiewiadomych[3]/TabNiewiadomych[0];
}


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 * 
 * Przeciazenie operatora wejscia - przyjmuje obiekty typu Macierz
 *
 *
 *
 */
template <class typ>
std::istream& operator >> (std::istream &wejscie, Macierz<typ> &Mac)
{
  Wektor<typ> W[ROZMIAR];
    for(int Ind=0;Ind<ROZMIAR;Ind++)
    {
        wejscie >> W[Ind];
        Mac[Ind]=W[Ind];
    }
    return wejscie;

}

/*
 *
 *  Przeciazenie operatora wyjscia - przyjmuje obiekty typu Macierz
 *
 *
 *
 *
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */


template <class typ>
std::ostream& operator << (std::ostream &wyjscie, const Macierz<typ> &Mac)
{
    wyjscie << Mac[0]<< "  "
    << Mac[1]<< "  "
     << Mac[2];

     return wyjscie;

}


#endif
