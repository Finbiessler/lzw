/*! \file CArrayEnc.cpp
/*
 * CArrayEnc.cpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#include "CArrayEnc.hpp"

CArrayEnc::CArrayEnc(){
	for(int i = 0; i < 256; i++)
		m_symbolTable[i].setSymbol(intToString(i)); //Initialisiert die ersten 256 Stellen des Dict. mit den ASCII-Zeichen
}

CArrayEnc::~CArrayEnc() {}

vector<unsigned int> CArrayEnc::encode(const std::string &input){
	//Benötigte Variablen:
	vector<unsigned int> output; 	//Output-Vektor (encodierter String)
	//str:  Zeichenkette welche im Dictionary enthalten ist
	//strX: Um x (ein character) erweiterete Zeichenkette str, welche im Dictionary gesucht wird
	std::string str = "";
	std::string strX = "";
	int nextPosDict = 256; 			//Nächste freie Stelle im Dictionary, startet bei 256 da die Stellen 0-255 vor Beginn schon mit Werten initialisiert wurden

	if(input.begin() == input.end()) return output;//wenn input leer, leeren output returnen (nichts zu encodieren)

	for(std::string::const_iterator itr = input.begin(); itr != input.end(); itr++){	//durch den gesamten Inputstring iterieren
		strX = str + *itr;
		int strXPos = findInDict(strX); //strX im Dict. suchen

		if(strXPos >= 0){	// strX ist im Dict. vorhanden
			str = strX;
		}else{				// strX ist nicht im Dict. vorhanden
			output.push_back(findInDict(str));			//Dictionary Index von str in den Output schreiben
			m_symbolTable[nextPosDict].setSymbol(strX);	//strX im Dictionary speichern
			nextPosDict++;	//nächste freie Position im Dict. berechen
			str = *itr;		//Neuer str ist nur das aktuell letzte Zeichen X
		}
	}
	//Letzte Zeichenkette in den Outputvektor schreiben und output returnen
	output.push_back(findInDict(str));
	return output;
}

int CArrayEnc::findInDict(const std::string &str){
	for(int i = 0; i < LZW_DICT_SIZE; i++){			//Iteriert durch das gesamte Dictionary
		if(m_symbolTable[i].getSymbol() == str)
			return i;								//Return Index wenn string und Dictionaryeintrag matchen
	}
	return -1;										//String im Dictionary nicht gefunden
}

