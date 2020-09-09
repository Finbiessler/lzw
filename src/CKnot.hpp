//! \file CKnot.hpp
/*
 * CKnot.hpp
 *
 *  Created on: 17.05.2020
 *      Author: fin_b
 */
//! Klasse CKnot erbt public von CEntry (und hat somit alle Member die CEntry auch hat) und erweitert die Klasse um die Adresse des übergeordneten Knotens
/*!
 * CKnot() ist der parameterlose Konstruktor
 * virtual ~CKnot ist der virtuelle Destruktor
 * int getParent() const ist die getter-Funktion der privaten Membervariable m_parent, und greift nur lesend zu (const)
 * void setParent(int parent) ist die setter-Funktion der privaten Membervariable m_parent
 *
 * int m_parent ist die private Membervaraible zum speichern der Adresse des übergeordneten Knotens
 */
#ifndef CKNOT_HPP_
#define CKNOT_HPP_

#include "CEntry.hpp"

class CKnot: public CEntry {
	public:
		/*!
		 * Ist der parameterlose Konstruktor, er ruft den Konstruktor von CEntry auf und initialisiert m_parent mit 0
		 */
		CKnot();
		/*!
		 * Virtueller Destruktor von CKnot
		 */
		virtual ~CKnot();
		/*!
		 * Liefert die private Membervariable m_parent. Const: greift nur lesend auf das system zu.
		 * @return enthält den Inhalt von m_parent
		 */
		int getParent() const;
		/*!
		 * Setzt die Adresse des übergeordneten Knotens m_parent auf parent
		 * @param parent Adresse des übergeordneten Knotens
		 */
		void setParent(int parent);
	private:
		int m_parent; //!< Private Membervaraible zum Speichern der Adresse des übergeordneten Knotens
};

#endif /* CKNOT_HPP_ */
