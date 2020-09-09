//!\file CTrieDec.hpp
/*
 * CTrieDec.hpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#ifndef CTRIEDEC_HPP_
#define CTRIEDEC_HPP_

#include "CDec.hpp"
#include "CArray.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

//! Klasse CTrieDec zum decodieren von Zeichenketten mit dem LZW-Algorithmus, auf Basis einer Triedatenstruktur
/*!
 * CTrieDec() ist der parameterlose Konstruktor
 * ~CTrieDec() ist der virtuelle Destruktor
 */

class CTrieDec: public CDec {
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors.
	 */
	CTrieDec();
	/*!
	 * Deklaration des virtuellen Destruktors.
	 */
	virtual ~CTrieDec();
	/*!
	 * Decodiert den String mit Hilfe des LZW-Algorithmus auf Basis einer Trie Datenstruktur
	 * @param input zu decodierender Inputstring als vector
	 * @return decodierter String
	 */
	std::string decode(const vector<unsigned int>& input);
private:
	CArray<CKnot, LZW_DICT_SIZE> m_symbolTable; //!Private Membervariable welche das Dictionary des Algorithmus abstrahiert
};

#endif /* CTRIEDEC_HPP_ */
