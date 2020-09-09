//!\file CArrayDec.hpp
/*
 * CArrayDec.hpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#ifndef CARRAYDEC_HPP_
#define CARRAYDEC_HPP_

#include "CDec.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

//! Klasse CArrayDec zum decodieren von Zeichenketten mit dem LZW-Algorithmus, auf Basis einer Arraydatenstruktur
/*!
 * CArrayDec() ist der parameterlose Konstruktor
 * ~CArrayDec() ist der virtuelle Destruktor
 */

class CArrayDec: public CDec {
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors.
	 */
	CArrayDec();
	/*!
	 * Deklaration des virtuellen Destruktors.
	 */
	virtual ~CArrayDec();
	/*!
	 * Stellt (decodiert) den String anhand des Input-Vektors mit dem LZW-Algorithmus wieder her
	 * @param in Vektor aus unsigned int mit welchem der eigentliche String restauriert wird
	 * @return der eigentliche decodierte String
	 */
	std::string decode(const vector<unsigned int> &in);
private:
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable; //!<Private Membervariable der Templateklasse CArray von CEntrys der Gr��e LZW_DICT_SIZE, welche das Dictionary abstrahiert
};

#endif /* CARRAYDEC_HPP_ */
