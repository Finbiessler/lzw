/*! \file CArrayDec.cpp
/*
 * CArrayDec.cpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#include "CArrayDec.hpp"

CArrayDec::CArrayDec() {
	for(int i = 0; i < 256; i++)
			m_symbolTable[i].setSymbol(intToString(i)); //Initialisiert die ersten 256 Stellen des Dict. mit den ASCII-Zeichen
}

CArrayDec::~CArrayDec(){}

std::string CArrayDec::decode(const vector<unsigned int> &input){
	//Initialsierung der Variablen
	std::string output = "";	//Output string (decodierte Zeichenkette) wird mit leerem String initialisiert
	unsigned int nextPosDict = 256; 		//Nächste freie Stelle im Dictionary, startet bei 256 da die Stellen 0-255 vor Beginn schon mit Werten initialisiert wurden

	//str:  Zeichenkette für aktuellen Ausgabestring
	//strV: Zeichenkette für vorherigen Ausgabestring
	// beide werden mit dem leeren String initialisiert
	std::string str = "";
	std::string strV = "";

	//Iterator auf den Angang des Eingabestroms setzen
	vector<unsigned int>::const_iterator itr;
	itr = input.begin();

	//Decodierung startet
	if(itr == input.end()){ //Wenn input leer, leeren output returnen
		return "";
	}else{

		//Erste Zeichenkette auslesen und in strV speichern
		strV = m_symbolTable[*itr].getSymbol();
		//Ausgabe der ersten Zeichenkette
		output = strV;

		//Schleife über Inputvektor input (Indexwerte die empfangen wurden)
		for(itr = ++input.begin(); itr != input.end(); itr++){
			//String zum Indexwert *itr ermitteln
			if(*itr == nextPosDict){
				//SPEZIALFALL: Index wurde noch nicht gespeichert
				//strV mit erstem Zeichen an das Ende angehängt #
				//ist der neue Eintrag
				str = strV + strV[0];
			}else{
				//Decodierung des empfangenen Indexvalues
				str = m_symbolTable[*itr].getSymbol();
			}

			//String welcher decodiert wurde an den Output anhängen
			output += str;
			//Vorheriger Ausgabe + erstes der neuen Zeichenkette
			//ist der neue Eintrag
			m_symbolTable[nextPosDict].setSymbol(strV + str[0]);
			//nächste freie Stelle im Dictionary "weiterschalten"
			nextPosDict++;

			//Zeichenkette die schon decodiert wurde für den nächsten Schritt sichern
			strV = str;
		}
		return output;
	}
}
