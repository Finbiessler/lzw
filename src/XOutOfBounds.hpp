//! \file XOutOfBounds.hpp
/*
 * XOutOfBounds.hpp
 *
 *  Created on: 14.05.2020
 *      Author: fin_b
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

#include <exception>
#include <string>
#include <iostream>
///! Klasse XOutOfBounds erbt von std::exception und ist somit eine spezielle Exception
/*!
 * XOutOfBounds(const char* msg) ist der Konstruktor
 * virtual ~XOutOfBounds() throw() ist der virtuelle Destruktor der Klasse
 * const char* what() const throw() ist die überschriebene Memberfunktion aus der klasse exception
 *
 * std::string m_msg ist die private Membervariable für die Fehlermeldung
 */
class XOutOfBounds : public std::exception {
	public:
		/*!
		 * Der konstruktor initialisert die Membervariable m_msg mit dem Parameter msg
		 * @param msg Fehlernachricht welche ausgegeben werden soll
		 */
		XOutOfBounds(const char* msg);
		/*!
		 * Ist der virtuelle Destruktor der Klasse
		 */
		virtual ~XOutOfBounds() throw();
		/*!
		 * Liefert die Fehlernachricht als c_string. Greift nur lesend zu. Wird what() aus exception wird überschrieb
		 * @return enthält die Fehlermeldung als c_string
		 */
		const char* what() const throw();
	private:
		std::string m_msg; //!< Private Membervariable zum speichern der Fehlermeldung
};

#endif /* XOUTOFBOUNDS_HPP_ */
