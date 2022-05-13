#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "modele.h"

class chifoumievue;
class Presentation
{
public:
    Presentation();
    ~Presentation();

    explicit Presentation(Modele *m, QObject *parent = nullptr);

public:
    enum UnEtatJeu {etatInitial, partieEnCours};//


    //Méthodes traitant les évènements du Jeu à interagir avec la Vue

    void coupJoueurJoue(Modele::UnCoup p_coup);
    /* Pour traiter les événements du Jeu pour indiquer à la vue que le Joueur à jouer*/
    void newPartieDemandee();
    /* Pour indiquer à la vue que le joueur a demandé une nouvelle partie*/
    void notificationAccepter();/*Pour notifier l'action du joueur*/

    //Methode Getters et Setters de la Presentation
    UnEtatJeu getEtatJeu();
        // retourne l'état du jeu
    chifoumievue* getVue();
        // retourne un pointeur sur la Vue
    Modele* getModele();
        // retourne un pointeur sur le Modèle

    void setEtatJeu(UnEtatJeu p_etat);
        // initialise l'attribut etatJeu
    void setVue(chifoumievue* p_vue);
        // initialise l'attribut etatJeu
    void setModele(Modele* p_modele);
        // initialise l'attribut etatJeu
public slots:
    void clickBoutonPapier();
    void clickBoutonPierre();
    void clickBoutonCiseau();
    void clickDemanderNewPartie();

private:
    UnEtatJeu etatJeu;
    chifoumievue* laVue;  // La fenetre principale de l'application
    Modele* leModele;    // Pour pointer vers l'objet Modèle
};

#endif // PRESENTATION_H
