//! \file CEntry.hpp
/*
 * CEntry.hpp
 *
 *  Created on: 06.05.2020
 *      Author: fin_b
 */

#ifndef CENTRY_HPP_
#define CENTRY_HPP_
#include <string>
//! Klasse CEntry zum speichern von Zeichenketten
/*!
 * CEntry() ist der Konstruktor
 * virtual ~CEntry() ist der virtuelle Destruktor der Klasse
 * const std::string& getSymbol() const ist die getter-Funktion der Klasse f�r die Membervariable m_symbol const da die Funktion nur lesend zugreifen soll
 * void setSymbol(std::string input) ist die setter-Funktion f�r die Membervariable m_symbol
 * static unsigend int getNumber() ist die getter-Funktion f�r die Membervariable m_number
 */
class CEntry {
public:
	/*!
	 * Parameterloser Konstruktor welcher den string m_symbol mit "" und die statische Membervariable m_number bei jedem Aufruf inkrementiert (Anzahl der Objekte von CEntry z�hlen)
	 */
	CEntry();
	/*!
	 * Der virtuelle Destruktor welcher bei jedem Aufruf die statische Membervariable m_number dekrementiert
	 */
	virtual ~CEntry();
	/*!
	 * Getter-Funktion f�r m_symbol
	 * @return enth�lt den Inhalt der privaten Membervariable m_symbol
	 */
	const std::string& getSymbol() const;
	/*!
	 * Setter-Funktion f�r m_symbol. Setzt m_symbol auf input.
	 * @param input string welcher m_symbol zugewiesen werden soll
	 */
	void setSymbol(std::string input);
	/*!
	 * Statische getter-Funktion f�r statische Membervariable m_number
	 * @return liefert den Inhalt der statischen Membervariable m_number
	 */
	static unsigned int getNumber();
private:
	std::string m_symbol; //!< Private Membervaraible zum speichern der Zeichenkette
	static unsigned int m_number; //!< statische Membervariable f�r den Z�hlstand wie viele Objekte der Klasse CEntry insgesamt existieren
};

#endif /* CENTRY_HPP_ */
