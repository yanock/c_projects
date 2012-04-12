#include "Personnage.h" // Ne pas oublier

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100), m_arme("Epée rouillée", 10)
{
    // Rien à mettre dans le corps du constructeur, tout a déjà été fait !
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

Personnage::~Personnage()
{}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats; // On enlève le nombre de dégâts reçus à la vie du personnage

    if (m_vie < 0) // Pour éviter d'avoir une vie négative
    {
        m_vie = 0; // On met la vie à 0 (ça veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats()); // On inflige à la cible les dégâts que causent notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) // Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    if (m_vie > 0) // Plus de 0 de vie ?
    {
        return true; // VRAI, il est vivant !
    }
    else
    {
        return false; // FAUX, il n'est plus vivant !
    }
}

void Personnage::afficherEtat() const
{
    cout << "vie : " << m_vie << endl;
    cout << "mana : " << m_mana << endl;
    m_arme.afficher();
}
