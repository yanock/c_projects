#include "Arme.h"

using namespace std;

Arme::Arme() : m_nom("epée toute rouillée"), m_degats(12)
{
}

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
}

void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl;
}

int Arme::getDegats() const
{
    return m_degats;
}

string Arme::getNom() const
{
    return m_nom;
}

void Arme::setDegats(int degats)
{
    m_degats = degats;
}

void Arme::setNom(string nom)
{
    m_nom = nom;
}
