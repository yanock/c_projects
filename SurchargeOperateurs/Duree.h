#ifndef DEF_DUREE
#define DEF_DUREE

class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);

    Duree& operator+=(Duree const& duree);

    void afficher(std::ostream &out) const;

    bool estEgal(Duree const& b) const;

    bool estPlusPetitQue(Duree const& b) const;

    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
};

Duree operator+(Duree const& a, Duree const& b);

std::ostream& operator<<(std::ostream& out, Duree const& duree);

bool operator==(Duree const& a, Duree const& b);

bool operator!=(Duree const& a, Duree const& b);

bool operator<(Duree const& a, Duree const& b);

#endif 

