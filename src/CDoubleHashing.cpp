/*!\file CDoubleHashing.cpp
 * \brief Definition der Klasse CDoubleHashing
 */
/*
 * CDoubleHashing.cpp
 *
 *  Created on: 30.05.2020
 *      Author: fin_b
 */

#include "CDoubleHashing.hpp"
CDoubleHashing::CDoubleHashing() {
	// TODO Auto-generated constructor stub

}

CDoubleHashing::~CDoubleHashing() {
	// TODO Auto-generated destructor stub
}

CDoubleHashing& CDoubleHashing::getInstance(){
	return m_instanz;
}

CDoubleHashing CDoubleHashing::m_instanz;

unsigned int CDoubleHashing::hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt){
	unsigned int x = 0.5*(I+J)*(I+J+1)+J;
	return ((x+attempt*(1+(x % (dict_size-2)))) % dict_size);
}



