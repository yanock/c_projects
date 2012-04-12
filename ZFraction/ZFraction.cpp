/*
 * ZFraction.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: yanock
 */

#include "ZFraction.h"
#include <iostream>

using namespace std;


ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
}

ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1)
{
}

ZFraction::ZFraction() : m_numerateur(0), m_denominateur(1)
{
}

ZFraction ZFraction::multiplier(ZFraction const& b) const
{

	int denom, num, ipgcd;

	num =  m_numerateur*b.m_numerateur;
	denom = m_denominateur*b.m_denominateur;

	ipgcd = pgcd(num, denom);

	num/=ipgcd;
	denom/=ipgcd;

	return ZFraction(num, denom);
}

ZFraction ZFraction::additionner(ZFraction const& b) const
{
	int denom, num, ipgcd;



	num =  (m_numerateur*b.m_denominateur)+(b.m_numerateur*m_denominateur);
	denom = m_denominateur*b.m_denominateur;

	ipgcd = pgcd(num, denom);

	num/=ipgcd;
	denom/=ipgcd;

	return ZFraction(num, denom);

}

bool ZFraction::estEgal(ZFraction const& b) const
{
	double da,db;
	da = m_numerateur/m_denominateur;
	db = b.m_numerateur/b.m_denominateur;
	if(da == db)
		return true;
	else
		return false;
}

bool ZFraction::estPlusPetitQue(ZFraction const& b) const
{
	double da,db;
	da = m_numerateur/m_denominateur;
	db = b.m_numerateur/b.m_denominateur;
	if(da < db)
		return false;
	else
		return true;

}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	return a.additionner(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
	return a.estPlusPetitQue(b);
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
	return a.estEgal(b);
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	return a.multiplier(b);
}

void ZFraction::afficher(ostream &out) const
{
    out << m_numerateur << "/" << m_denominateur;
}

ostream& operator<<(ostream& out, ZFraction const& zFraction)
{
    zFraction.afficher(out) ;
    return out;
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}


