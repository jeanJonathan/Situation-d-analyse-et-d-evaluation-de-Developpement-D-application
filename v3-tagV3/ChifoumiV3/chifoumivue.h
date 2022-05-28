#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "presentation.h" // pour accéder au type UnEtatJeu
#include "modele.h" // pour accéder au type UnCoup
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class Presentation; // Pour faire pointer la Vue sur la présentation et inversement
class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();

    // Getter et Setters des propriétés de Vue
    void setPresentation(Presentation *p_presentation);
    Presentation * getPresentation();

    /** Ordres provenant de la Présentation */
    // affichage des éléments du Jeu : scores et coups
    void afficherScoreJoueur(unsigned int scoreJ);
    void afficherScoreMachine(unsigned int scoreM);
    void afficherCoupJoueur(Modele::UnCoup coupJ);
    void afficherCoupMachine(Modele::UnCoup coupM);
    // met à jour la visibilité et accessibilité des élèments de l'interface,
    // en fonction de l'état du jeu
    void majActivationBoutons(Presentation :: UnEtatJeu e);

    void modificationColor(); //


    // Gestionnaires d'événements associés aux éléments interactifs de l'interface
private slots:
    void choisirCiseau();
    void choisirPierre();
    void choisirPapier();
    void demanderNouvellePartie();
    void choisirQuitter();
    void aProposDe();

private:
    Ui::ChifoumiVue *ui;
    Presentation* laPresentation; // pointeur sur l'objet Présentation

    /** Méthodes utilitaires à la vue */
    // Pour notifier à la presentation dans le cas ou le joueur à choisir une figure
    void demanderCoupJoueur();
    // Fournit le chemin d'accès à la ressource image correspondant au paramètre c (UnCoup)
    QString imageDernierCoup(Modele::UnCoup c);//
};
#endif // CHIFOUMIVUE_H


/*
void nvlleConnexion(QObject *c); //Pour interpeler la Présentation suite à une Connexion de l'utilisateur
//
void supprConnexion(QObject *c); //Pour interpeler la Présentation suite à une deconnexion de l'utilisateur
//
void majInterface(Modele ::UnCoup coup);

public:
    ///Méthodes  Controlant la Vue par la Presentation
    void coupJoueurJoue(Modele::UnCoup p_coup);
    // Pour interpeller la vue pour lui dire quelle figure (p_coup) a été choisie
    void notificationAccepter();// Pour notifier l'action du joueur
*/
