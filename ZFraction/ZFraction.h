/*
 * ZFraction.h
 *
 *  Created on: Mar 21, 2012
 *      Author: yanock
 */

#ifndef ZFRACTION_H_
#define ZFRACTION_H_

#include <iostream>

class ZFraction
{
public:

	ZFraction(int numerateur, int denominateur);
	ZFraction(int numerateur);
	ZFraction();

	bool estEgal(ZFraction const& b) const;
	bool estPlusPetitQue(ZFraction const& b) const;
	void afficher(std::ostream &out) const;
	ZFraction multiplier(ZFraction const& b) const;
	ZFraction additionner(ZFraction const& b) const;

private:

int m_numerateur;      //Le numérateur de la fraction
int m_denominateur;    //Le dénominateur de la fraction

};

ZFraction operator+(ZFraction const& a, ZFraction const& b);

bool operator==(ZFraction const& a, ZFraction const& b);

ZFraction operator*(ZFraction const& a, ZFraction const& b);

bool operator>(ZFraction const& a, ZFraction const& b);

std::ostream& operator<<(std::ostream& out, ZFraction const& zFraction);

int pgcd(int a, int b);


#endif /* ZFRACTION_H_ */
