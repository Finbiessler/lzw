//! \file CDoubleHashing.hpp
/*
 * CDoubleHashing.hpp
 *
 *  Created on: 30.05.2020
 *      Author: fin_b
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_
//! Klasse CDoubleHashing zum hashen zweier natürlichen Zahlen mit Hilfe von doppeltem Hashing
/*!
 *CDoubleHashing() ist der private Konstruktor (wegen Sigleton)
 *virtual ~CDoubleHashing() ist der Destruktor
 *static CDoubleHashing& getInstance() liefert Referenz auf m_instanz ist statisch weil m_instanz statisch ist
 *unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt) berechnet und liefert den Hashwert zweier natürlicher Zahlen
 *CDoubleHashing(const CDoubleHashing& other) = delete sperrt Kopierkonstruktor
 *CDoubleHashing operator=(CDoubleHashing& other) = delete sperrt den Zuweisungsoperator
 *
 *
 *static CDoubleHashing m_instanz ist die private statische Membervariable für das deklarieren der Instanz, so dass nur ein Objekt von CDoubleHashing existieren kann
 */
class CDoubleHashing {
public:
	/*!
	 * virtueller Destruktor von CDoubleHashing
	 */
	virtual ~CDoubleHashing();
	/*!
	 * Liefert Referenz auf die einzig existierende Instanz von CDoubleHashing
	 * @return enthält Referenz auf m_instanz
	 */
	static CDoubleHashing& getInstance();
	/*!
	 * Berechnet hashwert von zwei Zahlen I und J mit doppeltem Hashing
	 * @param I 1. zu hashende Zahl
	 * @param J 2. zu hashende Zahl
	 * @param dict_size representiert die größe der Hashtabelle
	 * @param attempt Zähler für doppeltes hashing
	 * @return liefert den aus I und J berechneten Hashwert
	 */
	unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt);
private:
	/*!
	 * Deklaration des parameterlosen Konstruktors als private Memberfunktion.
	 */
	CDoubleHashing();
	/*!
	 * Sperrt den Kopierkonstruktor
	 * @param other eine andere Instanz von CDoubleHashing
	 */
	CDoubleHashing(const CDoubleHashing& other) = delete; //Kopierkonstruktor gesperrt
	/*!
	 * Sperrt den Zuweisungsoperator
	 * @param other eine andere Instanz von CDoubleHashing
	 * @return Instanz von CDoubleHashing
	 */
	CDoubleHashing operator=(CDoubleHashing& other) = delete; //Zweisungsoperator gesperrt
	static CDoubleHashing m_instanz; //!< Private Membervariable für die einzige Instanz von CDoubleHashing
};

#endif /* CDOUBLEHASHING_HPP_ */
