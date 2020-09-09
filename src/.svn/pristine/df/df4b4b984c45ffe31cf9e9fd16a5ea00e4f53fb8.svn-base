/*
 * CEntry.cpp
 *
 *  Created on: 06.05.2020
 *      Author: fin_b
 */

#include "CEntry.hpp"

CEntry::CEntry() : m_symbol(""){
	m_number++;
}

CEntry::~CEntry() {
	m_number--;
}

const std::string& CEntry::getSymbol()const{
	return m_symbol;
}

void CEntry::setSymbol(std::string input){
	m_symbol = input;
}

unsigned int CEntry::getNumber(){
	return m_number;
}

unsigned int CEntry::m_number = 0; //Wird vor ausführung des Hauptprogrammes auf 0 gesetzt (damit im Hauptprogramm richtig gezählt wird)
