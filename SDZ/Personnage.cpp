#include "Personnage.h" // Ne pas oublier

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100), m_arme("Ep�e rouill�e", 10)
{
    // Rien � mettre dans le corps du constructeur, tout a d�j� �t� fait !
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

Personnage::~Personnage()
{}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats; // On enl�ve le nombre de d�g�ts re�us � la vie du personnage

    if (m_vie < 0) // Pour �viter d'avoir une vie n�gative
    {
        m_vie = 0; // On met la vie � 0 (�a veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats()); // On inflige � la cible les d�g�ts que causent notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) // Interdiction de d�passer 100 de vie
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
