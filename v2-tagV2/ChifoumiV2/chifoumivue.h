#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "presentation.h" // pour accéder au type UnEtatJeu
#include "modele.h" // pour accéder au type UnCoup


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
    // Getter et Setters de la presentation
    void setPresentation(Presentation *p_presentation);
    Presentation * getPresentation();
    //
    void choisirCiseau();
    void choisirPierre();
    void choisirPapier();
    void majActivationBoutons(Presentation :: UnEtatJeu e);

    /*
    void nvlleConnexion(QObject *c); //Pour interpeler la Présentation suite à une Connexion de l'utilisateur
    //
    void supprConnexion(QObject *c); //Pour interpeler la Présentation suite à une deconnexion de l'utilisateur
    //
    void majInterface(Presentation::UnEtatJeu p_etat);
    // met à jour la visibilité et accessibilité des élèments de l'interface, en fonction de l'état du jeu
    void majInterface(Modele ::UnCoup coup);
    */

    /* Methode Controlant la Vue par la Presentation*/
    void coupJoueurJoue(Modele::UnCoup p_coup);// Pour interpeller la vue pour lui dire quelle figure (p_coup) a été choisie
    void demanderNouvellePartie();//Pour indiquer que le joueur à demander une nouvelle partie
    void notificationAccepter();// Pour notifier l'action du joueur

    void setScoreJoueur(unsigned short int p_score);
    // affecte la valeur p_score à l'objet graphique associé au score du joueur

    void setScoreMachine(unsigned short int p_score);
    // affecte la valeur p_score à l'objet graphique associé au score de la machine

    void setCoupJoueur(Modele::UnCoup p_coup);
    // affecte la valeur p_coup à l'objet graphique associé au dernier coup du joueur

    void setCoupMachine(Modele::UnCoup p_coup);
    // affecte la valeur p_coup à l'objet graphique associé au dernier coup de la machine



private:
    Ui::ChifoumiVue *ui;
    Presentation* laPresentation; // pointeur sur l'objet Présentation qui gére le comportement de l'application
    void demanderCoupJoueur();// Pour notifier à la presentation dans le cas ou le joueur à choisir une figure
    QString imageDernierCoup(Modele::UnCoup c);//
};
#endif // CHIFOUMIVUE_H
