#ifndef AFFICHERJEU_H
#define AFFICHERJEU_H
#include "jeu.h"

class afficherJeu
{
    afficherJeu();
    afficherJeu(jeu& leJeu);
    void afficheMenu() const;

private:
    jeu* d_pointeurJeu;
};

#endif // AFFICHERJEU_H
