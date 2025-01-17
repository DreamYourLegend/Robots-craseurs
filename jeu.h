#ifndef JEU_H
#define JEU_H
#include <vector>
#include "entite.h"
#include "position.h"

const int NBPOINTMECHANT = 100;

class jeu
{
    friend class afficherJeu;

public:
    jeu();
    jeu(int nbVieuxRobots, int nbNouveauxRobots,int tailleTerrain, char typePartie);
    ~jeu();
    void run();
    void ajouterEntite(entite* entite1);
    void creerDebris(position& pos);
    void supprimerEntite(entite* entite1);
    void jouerUnTour();
    void collision();
    void finDePartie(bool jeuTermine=false);
private:
    int d_nbVieuxRobots;
    int d_nbNouveauxRobots;
    int d_tailleTerrain;
    char d_typePartie;
    std::vector<entite *> d_vectEntite;
    int d_score;
};
#endif // JEU_H
