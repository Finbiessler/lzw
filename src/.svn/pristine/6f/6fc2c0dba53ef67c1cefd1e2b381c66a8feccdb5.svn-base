/*! \file CTrieEnc.cpp
/*
 * CTrieEnc.cpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#include "CTrieEnc.hpp"
#include "CForwardCounter.hpp"
#include "CDoubleHashing.hpp"

CTrieEnc::CTrieEnc() {
	for(int i = 0; i < 256; i++){
		m_symbolTable[i].setSymbol(intToString(i)); //Initialisiert die ersten 256 Stellen des Dict. mit den ASCII-Zeichen
		m_symbolTable[i].setParent(-1);				//Vaterknoten jedes Knotens mit -1 initialisieren
	}
}

CTrieEnc::~CTrieEnc() {

}

vector<unsigned int> CTrieEnc::encode(const string& input){
	//Deklaration des Outputs
	vector<unsigned int> output;
	output.clear();
	//parentPosition: Vaterknoten Position im Dictionary ist da
	unsigned int parentPosition = 0;
	//symbolValue: ASCII-Value des nächsten Zeichens im Input
	unsigned int symbolValue = 0;
	//Hashwert
	unsigned int hashValue = 0;
	//Position, temporäre Adresse für das hashing
	unsigned int index = 0;
	//Counter für das Zählen der Rehashing-Versuche
	CForwardCounter CounterAttempts;
	CounterAttempts.setValue(0);	//wird mit 0 initialisiert

	//Iterator über den Input
	string::const_iterator itr = input.begin();
	//Iterator auf Ende des Inputs für die Endabfrage
	string::const_iterator itrEnd = input.end();

	if(itr == itrEnd) return output; //Wenn der Eingabe-String zu beginn leer ist einfach den leeren Output returnen

	//Erstes Zeichen übernehemen, position ist dessen ASCII_Value, siehe Konstruktor
	parentPosition = charToInt(*itr); 	//Cast erforderlich um negative Werte zu vermeiden

	while(true){
		if(++itr == itrEnd){	//Wenn der Iterator inkrementiert wird und dann auf das ende des Input zeigt, das letzte Zeichen in den Output aufnehmen
			output.push_back(parentPosition);
			return output;		//Output returnen, terminiert
		}

		//Neues Zeichen einlesen
		symbolValue = charToInt(*itr);

		//Hashvlaue berechnen (h(x))
		hashValue = CDoubleHashing::getInstance().hash(parentPosition, symbolValue, LZW_DICT_SIZE, CounterAttempts.getValue());
		index = hashValue; //Adresse durchs Hashen

		//Rehashing wenn Index bereits belegt
		while((m_symbolTable[index].getSymbol() != "") && !(m_symbolTable[index].getSymbol()[0] == static_cast<int>(symbolValue) && m_symbolTable[index].getParent() == static_cast<int>(parentPosition))){
			//Versuchzähler inkrementiern, da gerehasht wird
			CounterAttempts.count();
			//Neuen index berechenen (hi(x)), hashValue ändert sich nicht
			index = CDoubleHashing::getInstance().hash(parentPosition, symbolValue, LZW_DICT_SIZE, CounterAttempts.getValue());

			//Terminierung für den Fall dass, das Dictionary voll ist
			if(index == hashValue) return output; //Zyklus im hashen wurde durchlaufen -> Dict full -> Terminierung
		}

		//Nach rehashen den counter value zurücksetzen
		CounterAttempts.setValue(0);

		//Leere Position gefunden -> vollständiger String noch nicht im Dict
		//sonst String um das nächste Zeichen verlängern
		if(m_symbolTable[index].getSymbol() == ""){
			//Position des letzten gefundenen Zeichens ausgeben
			output.push_back(parentPosition);

			//Verlängerter String als neuen Eintag ins Dictionary einfügen
			m_symbolTable[index].setParent(parentPosition);
			m_symbolTable[index].setSymbol(intToString(symbolValue));

			//Last-first property herstellen -> letztes Zeichen als erstes Zeichen für den neuen String
			parentPosition = symbolValue; //Einzelzeichen -> Position des ASCII-Wert

		} else {

			//Leztes Zeichen wird zum Parent da bisheriger String bereits vorhanden
			parentPosition = index;
			//danach wird im Kopf des while-loops das nächste eingelesen

		}


	}
	return output;
}

