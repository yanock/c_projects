#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include "Arme.h"

class Personnage
{
    public:

    Personnage();
    Personnage(std::string nomArme, int degatsArme);
    ~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    void afficherEtat() const;
    // Tout ce qui suit est priv� (inaccessible depuis l'ext�rieur)
    private:

    int m_vie;
    int m_mana;
    Arme m_arme;
};

#endif // PERSONNAGE_H
