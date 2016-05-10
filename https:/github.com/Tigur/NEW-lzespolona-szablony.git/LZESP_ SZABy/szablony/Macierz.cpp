#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::istream& operator >> (std::istream &wejscie, Macierz<typ> &Mac)
{
    Wektor W[ROZMIAR];
    for(int Ind=0;Ind<ROZMIAR;Ind++)
    {
        wejscie >> W[Ind];
        Mac[Ind]=W[Ind];
    }
    return wejscie;

}
std::ostream& operator << (std::ostream &wyjscie, const Macierz<typ> &Mac)
{
    wyjscie << Mac[0]<< "  "
    << Mac[1]<< "  "
     << Mac[2];

     return wyjscie;

}

Macierz<typ> & Macierz<typ> :: Wyzerujprawo ( int i, Wektor podzielony)
    {

		  for(int j=ROZMIAR-1;j>i;j--)
		{
		  (*this)[j]=(*this)[j]-(podzielony*(*this)(i,j));

		}
		  cout<< "Wyzerowane"<< endl;
		  cout<< "po Wyzerowaniu: \n"<< endl;
		  (*this).WypiszMacierz<typ>();

      return (*this);
    }



bool Macierz<typ> :: ZamienKolumny( int i) 
{
  if ((*this)(i,i) != 0) return true;
  
  Macierz<typ> Mp=(*this);
  
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

 void WstawWolny(Macierz<typ> & M, Wektor wolny, int pozycja)
{
  M[pozycja]=wolny;

  
}
void LiczenieNiewiadomych(Wektor & X,float TabNiewiadomych[])
{
  X[0]=TabNiewiadomych[1]/TabNiewiadomych[0];
  X[1]=TabNiewiadomych[2]/TabNiewiadomych[0];
  X[2]=TabNiewiadomych[3]/TabNiewiadomych[0];
}


void Macierz<typ>:: WypiszMacierz<typ>() const
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

float Macierz<typ>oweSzarady(Macierz<typ> M,float & wyz)// roszady
{
  int wiersz=0,kolumna=0;
  // Macierz<typ> Mpomoc;
  Wektor  W_jed;
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
  M.WypiszMacierz<typ>();

    return wyz;
}





/*
int main ()
{

}
*/
