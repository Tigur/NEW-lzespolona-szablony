#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

/*
 * Opisy przedstawione w tym pliku nalezy odpowiednio zmienic.
 */


/*!
 * \file
 * \brief  Tu powiniena sie znalezc krotka informacja o zawartosci pliku
 *
 * Tutaj ta powinna znalexc sie mozliwie pelna informacja o pliku.
 */


/*!
 * \brief Krotki opis klasy mowiacy o tym jakie pojecie dana klasa modeluje
 *
 *  Rozszerzony opis klasy
 */
class LZespolona {
  /*!
   * \brief Krotki opis pola
   *
   * Pelny opis pola.
   */
   double  _re;
  /*!
   * \brief Krotki opis pola
   *
   * Pelny opis pola.
   */
   double  _im;

 public:
  /*!
   * \brief Krotki opis konstruktora
   *
   * Pelny opis konstruktora.
   */
   LZespolona();

  /*!
   * \brief Krotki opis metody
   *
   *  Pelny opis metody
   */
   double  Re() const;
  /*!
   * \brief Krotki opis metody
   *
   *  Pelny opis metody
   */
   double& Re();
  /*!
   * \brief Krotki opis metody
   *
   *  Pelny opis metody
   */
   double  Im() const;
  /*!
   * \brief Krotki opis metody
   *
   *  Pelny opis metody
   */
   double& Im();

  /*!
   * \brief Krotki opis przeciazenia operatora
   *
   *  Pelny opis przeciazenia operatora
   */
   LZespolona  operator + (const LZespolona&  Arg2) const;
  /*!
   * \brief Krotki opis przeciazenia operatora
   *
   *  Pelny opis przeciazenia operatora
   */
  LZespolona  operator * (const LZespolona&  Arg2) const;
};


/*!
 * \brief Krotki opis przeciazenia operatora
 *
 *  Pelny opis przeciazenia operatora
 */
std::ostream&  operator << ( std::ostream&      StrmWy,  
                             const LZespolona&  WyswietlanaLiczba
			   ); 

#endif
