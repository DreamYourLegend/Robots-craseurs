#include "jeu.h"
#include<vector>
#include<string>
#include "obstacle.h"
#include "position.h"
#include "joueurFacile.h"
#include "joueurDifficile.h"

jeu::jeu():
d_nbVieuxRobots{3}, d_nbNouveauxRobots{1} , d_tailleTerrain{200} ,
d_typePartie{'F'} , d_vectEntite{} ,d_score{0}
{
    position p { d_tailleTerrain / 2 , d_tailleTerrain / 2 };
    joueurFacile *j1 = new joueurFacile { p } ;
    d_vectEntite.push_back(j1);
}

jeu::jeu(int nbVieuxRobots, int nbNouveauxRobots, int tailleTerrain, char typePartie):
d_nbVieuxRobots{nbVieuxRobots}, d_nbNouveauxRobots{nbNouveauxRobots},d_tailleTerrain{tailleTerrain}, d_typePartie{typePartie},
d_vectEntite{},d_score{0}
{
    if(d_typePartie=='D')
    {
        position p { static_cast < int > ( d_tailleTerrain / 2 ) , static_cast < int > ( d_tailleTerrain / 2 ) };
        joueurDifficile *j1 = new joueurDifficile{ p };
        d_vectEntite.push_back(j1);
    }
    else
    {
        position p { static_cast < int > ( d_tailleTerrain / 2 ) , static_cast < int > ( d_tailleTerrain / 2 ) };
        joueurFacile *j1 = new joueurFacile{ p };
        d_vectEntite.push_back(j1);
    }
}

jeu::~jeu() {}

void jeu::run()
{

}

void jeu::ajouterEntite(entite* entite1)
{
    d_vectEntite.push_back(entite1);
}

void jeu::creerDebris(position& pos)
{
    obstacle *debris1=new obstacle{pos};
    d_vectEntite.push_back(debris1);
}

void jeu::supprimerEntite(entite* entite1)
{
    delete entite1;
    entite1=d_vectEntite[d_vectEntite.size()-1];
    d_vectEntite.pop_back();
}

void jeu::jouerUnTour()
{
    for( unsigned int i = 0 ; i < d_vectEntite.size() ; i++)
    {
        d_vectEntite[i]->deplacePerso();
    }
    collision();
}

void jeu::collision()
{
    if(!d_vectEntite.empty())
    {
        for( unsigned int i = 0 ; i < d_vectEntite.size() - 1 ; i++)
        {
            for( unsigned int j = 1 ; j < d_vectEntite.size() ; j++)
            {
                while(d_vectEntite[i]->getPosition()==d_vectEntite[j]->getPosition()) //si la derni�re case avait la m�me position avant remplacement
                {
                    if(d_vectEntite[i]->getNom()[1]=='J'||d_vectEntite[j]->getNom()[1]=='J') //si joueur entre en collision Game Over
                    {
                        finDePartie(true);
                    }
                    else
                        supprimerEntite(d_vectEntite[j]);
                        d_score+=NBPOINTMECHANT;
                }
            }
            creerDebris(d_vectEntite[i]->getPosition());
            supprimerEntite(d_vectEntite[i]);
            d_score+=NBPOINTMECHANT;
        }
    }
}

void jeu::finDePartie(bool jeuTermine=false)
{
    if(jeuTermine)
    {

    }
}





