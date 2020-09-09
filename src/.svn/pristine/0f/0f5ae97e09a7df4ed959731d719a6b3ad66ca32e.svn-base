//! \file CArray.hpp
/*
 * CArray.hpp
 *
 *  Created on: 13.05.2020
 *      Author: fin_b
 */

#include <algorithm>

#ifndef CARRAY_HPP_
#define CARRAY_HPP_
#include "XOutOfBounds.hpp"
//! Templateklasse CArray, mit den Templateparametern T für den Typ des Arrays und N (unsigned int) für die Länge des Feldes ist eine Klasse für Arrays jeglichen Typs
/*!
 * CArray() ist der parameterloser Konstruktor
 * CArray(const T& array) ist der Kopierkonstruktor
 * virtual ~CArray() ist der virtuelle Destruktor
 * T& operator[](unsigned int index) ist der Indexoperator für die Arrayklasse
 *
 * T* entries ist die private Membervariable für die Speicherung der eigentlichen Daten des Arrays
 */
template<typename T, unsigned int N>
class CArray{
public:
	CArray();
	CArray(const T& array);
	virtual ~CArray();
	T& operator[](unsigned int index);
private:
	T* entries; //!< Private Membervariable für Zeiger auf Anfang des Feldes entries
};

template<typename T, unsigned int N>
/*!
 * Konstruktor welcher Speicher für das Array entries dynamisch vom heap allokiert
 */
CArray<T, N>::CArray(){
	 entries = new T[N];
}
/*!
 * Kopierkonstruktor für die Templateklasse CArray
 * @tparam T Typ des Arrays
 * @tparam N Länge des Arrays
 * @param array Array als welches das neue Array initialisiert werden soll
 */
template<typename T, unsigned int N>
CArray<T, N>::CArray(const T& array){
	 entries = new T[N];
	 for(int i = 0; i < N; i++)
		 entries[i] = array[i];
}
/*!
 * virtueller Destruktor welcher den dynamisch allozierten Speicher wieder restlos frei gibt
 * @tparam T Typ des Arrays
 * @tparam N Länge des Arrays
 */
template<typename T, unsigned int N>
CArray<T, N>::~CArray(){
	if(entries != nullptr){
		delete[] entries;
		entries = nullptr;
	}
}
/*!
 * Indexoperator für die Templateklasse. Greift auf entries[index] zu.
 * @tparam T Typ des Arrays
 * @tparam N Länge des Arrays
 * @param index Index auf welchen zugegriffen werden soll
 * @return liefert  den Inhalt von entries[index]
 */
template<typename T, unsigned int N>
T& CArray<T, N>::operator[](unsigned int index){
	if(index >= N)
		throw XOutOfBounds("Index zu gross");
	return entries[index];
}
#endif /* CARRAY_HPP_ */
