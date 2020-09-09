//!\file CTrieEnc.hpp
/*
 * CTrieEnc.hpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#ifndef CTRIEENC_HPP_
#define CTRIEENC_HPP_

#include "CEnc.hpp"
#include "CArray.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"

//! Klasse CTrieEnc zum encodieren von Zeichenketten mit dem LZW-Algorithmus, auf Basis einer Triedatenstruktur
/*!
 * CTrieEnc() ist der parameterlose Konstruktor
 * ~CTrieEnc() ist der virtuelle Destruktor
 * encode(const std::string& input) encodiert den Eingabestring input nach dem LZW-Algorithmus
 */

class CTrieEnc: public CEnc {
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors.
	 */
	CTrieEnc();
	/*!
	 * Deklaration des virtuellen Destruktors.
	 */
	virtual ~CTrieEnc();
	/*!
	 * Codiert den String mit Hilfe des LZW-Algorithmus auf Basis einer Trie Datenstruktur
	 * @param input zu codierender Inputstring
	 * @return codierter String als Vector aus unsigned int welcher genutzt werden kann um den String wieder herzustellen
	 */
	vector<unsigned int> encode(const std::string& input);

private:

	CArray<CKnot, LZW_DICT_SIZE> m_symbolTable; //!Private Membervariable welche das Dictionary des Algorithmus abstrahiert

};

#endif /* CTRIEENC_HPP_ */
