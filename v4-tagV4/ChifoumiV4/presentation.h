#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <QObject>
#include <QDebug>

#include "modele.h"
class ChifoumiVue;
class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);
    ~Presentation();

public:
    enum UnEtatJeu {etatInitial,partieEnCours,etatFinal};// Pour gerer l'etat du Jeu


    //Méthodes traitant les évènements du Jeu à interagir avec la Vue

    //Methode Getters et Setters de la Presentation
    UnEtatJeu getEtatJeu();
        // retourne l'état du jeu
    ChifoumiVue* getVue();
        // retourne un pointeur sur la Vue
    Modele* getModele();
        // retourne un pointeur sur le Modèle

    void setEtatJeu(UnEtatJeu p_etat);
        // initialise l'attribut etatJeu
    void setVue(ChifoumiVue* p_vue);
        // initialise l'attribut etatJeu
    void setModele(Modele* p_modele);
        // initialise l'attribut etatJeu
    //void choisirCoup(Modele::UnCoup p_coup);
    void finPartie();

public slots:
    void choisirPapier();
    void choisirPierre();
    void choisirCiseau();
    void demanderNouvellePartie();
    void choixQuitter();
    void aProposDe();

private:
    UnEtatJeu etatJeu; // Puisque c'est la presentation qui traite l'etat du jeu.
                       //Pour transferer à la presentation la gestion du diagramme d'etat presentation
    ChifoumiVue* laVue;  // La fenetre principale de l'application
    Modele* leModele;    // Pour pointer vers l'objet Modèle
};

#endif // PRESENTATION_H

/*
public slots:
void choisirCoup(Modele::UnCoup p_coup);
// remplacerait les 3 slots :
void choisirPierre();
void choisirPapier();
void choisirCiseau();
*/
