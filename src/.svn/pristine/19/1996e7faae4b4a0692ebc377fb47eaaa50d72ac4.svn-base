//!\file CTrieDec.cpp
/*
 * CTrieDec.cpp
 *
 *  Created on: 22.06.2020
 *      Author: fin_b
 */

#include "CTrieDec.hpp"

CTrieDec::CTrieDec() {
	for(int i = 0; i < 256; i++){
		m_symbolTable[i].setSymbol(intToString(i)); //Initialisiert die ersten 256 Stellen des Dict. mit den ASCII-Zeichen
		m_symbolTable[i].setParent(-1);				//Vaterknoten jedes Knotens mit -1 initialisieren
	}
}

CTrieDec::~CTrieDec() {
}

string CTrieDec::decode(const vector<unsigned int>& input){
	//input -  Indizes welche empfangen werden

	//output ist der Ausgabestring
	std::string output = "";

	//Ausgabestring aus vorherigem Schritt
	std::string StrV = "";

	//Ausgabestring aus aktuellem Schritt
	std::string Str = "";

	//Iterator über input
	vector<unsigned int>::const_iterator itr;

	//Index für Backtracking
	int iBack = 0;

	//positionParent: position vom Vaterknoten
	unsigned int parentPosition = 0;
	//valueSymbol: ASCII-Value des nächsten Characters des Eingabestrings
	unsigned int symbolValue = 0;

	//Hashvalue, ändert sich beim rehashing aber nicht
	unsigned int hashValue = 0;

	//Index der temporären Adresse beim hashing und rehashing
	unsigned int index = 0;

	//Counter für das Zählen der Rehashing-Versuche
	CForwardCounter CounterAttempts;
	CounterAttempts.setValue(0);	//wird mit 0 initialisiert

	//Decodierungsstart
	itr = input.begin();
	if(itr == input.end()) {
		return output; //Leeren string zurückgeben wenn input leer ist
	} else {
		//Speichern des ersten empfangenen Index
		parentPosition = *itr;

		//Speichern des ersten Strings in StrV
		StrV = m_symbolTable[parentPosition].getSymbol();

		//Weil partent -1 sein MUSS braucht es nicht eingelesen zu werden
		output = StrV;

		//Schleife welche über input iteriert
		for(itr = ++input.begin(); itr != input.end(); itr++){

			//Zum indexvalue *itr den string ermitteln
			if(m_symbolTable[*itr].getParent() == -2){
				//Special case: Nicht vorhandener Index *itr

				//Für neuen Eintrag
				symbolValue = charToInt(StrV.front());

				//aktueller String
				Str = StrV + StrV.front();
			} else{
				//Vorhandener Index
				//Diesen Index decodieren
				Str = m_symbolTable[*itr].getSymbol();

				//Backtracking zur Wurzel des Tries
				iBack = m_symbolTable[*itr].getParent();
				while(iBack >= 0){
					//Symbol ändern
					Str = m_symbolTable[iBack].getSymbol() + Str;
					iBack = m_symbolTable[iBack].getParent();
				}
				//Neuer Eintrag
				symbolValue = charToInt(Str.front());
			}

			//Str ist jetzt decodierter String (neu)
			//StrV vorheriger String

			//Decoded String an output anhängen
			output = output + Str;

			//Hashvlaue berechnen (h(x))
			hashValue = CDoubleHashing::getInstance().hash(parentPosition, symbolValue, LZW_DICT_SIZE, CounterAttempts.getValue());
			index = hashValue; //Adresse durchs Hashen

			//Rehashing wenn Index bereits belegt
			while((m_symbolTable[index].getSymbol() != "") && !(m_symbolTable[index].getSymbol()[0] == symbolValue && m_symbolTable[index].getParent() == parentPosition )){
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
				//Verlängerter String als neuen Eintag ins Dictionary einfügen
				m_symbolTable[index].setParent(parentPosition);
				m_symbolTable[index].setSymbol(intToString(symbolValue));


				parentPosition = *itr;
			}

			//String welcher decodiert wurde für nächsten Schritt speichern
			StrV = Str;
		}
		return output;
	} //nicht-leerer Datenstrom (End)
}

