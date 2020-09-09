/*!\file CForwardCounter.hpp
 * \brief Vorwärtszähler, inkrementiert um 1, Klasse ist abgeleitet von CCounter
 *
 * Klasse aus Übung 2.
 * Methode count() in Basisklasse CCounter wird modifiziert, so dass sie nicht mehr zählt.
 * In CForwardCounter wird die Memberfunktion count() so überschrieben, dass sie
 * mit Schrittweite 1 inkrementiert.
 *
 */
#pragma once
#include "CCounter.hpp"
/*!
 * CForwardCounter, überschreibt die Memberfunktion count() aus Basisklasse CCounter,
 * so dass diese den internen Zählerstand um 1 inkrementiert.
 */
class CForwardCounter : public CCounter
{
public:
	/*!
	 * Parameterloser Konstruktor, setzt den Zählerstand auf 0
	 */
	CForwardCounter();
	/*!
	 * Zähler, inkrementiert den Zählerstand um 1
	 */
	void count();
};



