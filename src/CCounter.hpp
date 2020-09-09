//! \file CCounter.hpp
#pragma once

//! Klasse CCounter zum Setzen, Inkrementieren und Vergleichen von Zählerständen
/*!
 * CCounter() ist der parameterlose Konstruktor
 * ~CCounter() ist der Destruktor
 * int getValue() liefert den Zählerstand
 * void setValue(int) setzt den Zählerstand
 * void count() inkrementiert den Zählerstand
 * bool operator<(CCounter&) prüft, ob Argument größeren Zählerstand besitzt
 * bool operator>(CCounter&)
 *
 * int m_value ist die private Membervariable für den Zählerstand.
 * Wir verwenden die Konvention, dass der Namen privater Membervariablen mit m_ beginnt.
 */
class CCounter
{
public:
	/*!
	 * Deklaration des parameterlosen Konstruktors.
	 */
	CCounter();
	/*!
	 * Destruktor von CCounter
	 */
	virtual ~CCounter();
	/*!
	 * Gib den Wert der Zählervariable aus.
	 * @return  enthält den Wert der Zählervariable m_value.
	 */
	int getValue() const;
	/*!
	 * Setze die Zählervariable.
	 * @param value    Die Zählervariable m_value wird auf den Wert der Parametervariable value gesetzt.
	 */
	void setValue(int value);
	/*!
	 * Inkrementiert den Zählerstand um 1
	 */
	virtual void count();
	/*!
	 * Prüft, ob der Zählerstand kleiner ist, als der Eingabeparameter.
	 * Die Memberfunktion operator<() steht für den Operator < .
	 * @param other  ist der Eingabeparameter.
	 * @return ist wahr, falls der Zählerstand kleiner als der Eingabeparameter ist.
	 */
	bool operator<(const CCounter& other) const;
	/*!
	 * Prüft, ob der Zählerstand größer ist, als der Eingabeparameter.
	 * Die Memberfunktion operator>() steht für den Operator > .
	 * @param other  ist der Eingabeparameter.
	 * @return ist wahr, falls der Zählerstand größer als der Eingabeparameter ist.
	 */
	bool operator>(const CCounter& other) const;

private:
	int m_value; //!< Private Membervariable für den Zählerstand.
};
