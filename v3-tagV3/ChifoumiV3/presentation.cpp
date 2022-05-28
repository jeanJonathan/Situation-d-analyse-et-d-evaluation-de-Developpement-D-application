#include "presentation.h"
#include "chifoumivue.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    setEtatJeu(etatInitial);
    //   etat = etatInitial;
}
Presentation::~Presentation()
{
}
Presentation::UnEtatJeu Presentation::getEtatJeu(){
    return etatJeu;
}

ChifoumiVue* Presentation::getVue(){
    return laVue;
}

Modele* Presentation::getModele(){
    return leModele;
}


void Presentation::setEtatJeu(UnEtatJeu p_etat){
    etatJeu = p_etat;
}

void Presentation::setVue(ChifoumiVue* p_vue){
    laVue = p_vue;
}

void Presentation::setModele(Modele* p_modele){
    leModele = p_modele;
}

void Presentation::demanderNouvellePartie()
{
    qDebug() << "je suis Presentation : bouton Nvlle Partie cliqué " << Qt::endl;

    switch(getEtatJeu())
    {
    case etatInitial:
        // changement d'état
        setEtatJeu(partieEnCours);
        // activité 1
        getModele()->initScores();
        getModele()->initCoups();

        getVue()->afficherScoreJoueur(getModele()->getScoreJoueur());
        getVue()->afficherScoreMachine(getModele()->getScoreMachine());
        getVue()->afficherCoupJoueur(getModele()->getCoupJoueur());
        getVue()->afficherCoupMachine(getModele()->getCoupMachine());

        // mettre à jour l'état des éléments interactifs
       getVue()->majActivationBoutons(getEtatJeu());
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 3
        getModele()->initScores();
        getModele()->initCoups();
      //  afficherles scores et coups
        getVue()->afficherScoreJoueur(getModele()->getScoreJoueur());
        getVue()->afficherScoreMachine(getModele()->getScoreMachine());
        getVue()->afficherCoupJoueur(getModele()->getCoupJoueur());
        getVue()->afficherCoupMachine(getModele()->getCoupMachine());

        // mettre à jour l'état des éléments interactifs
       getVue()->majActivationBoutons(getEtatJeu());
        break;
    case etatFinal:
        //getVue()->
        // CLose() et affichage d'un message box

     default: break;
    }
}

void Presentation::choisirQuitter()
{
    qDebug() << "je suis Presentation : bouton choisirQuitter cliqué " << Qt::endl;
    laVue->close();
}

void Presentation::aProposDe()
{
    qDebug() << "je suis Presentation : bouton aProposDe cliqué " << Qt::endl;
}

void Presentation::choisirPierre()
{
    qDebug() << "Je suis la presentation bouton pierre " << Qt :: endl;
    switch(getEtatJeu())
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Modele::pierre);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        getVue()->afficherScoreJoueur(getModele()->getScoreJoueur());
        getVue()->afficherScoreMachine(getModele()->getScoreMachine());
        getVue()->afficherCoupJoueur(getModele()->getCoupJoueur());
        getVue()->afficherCoupMachine(getModele()->getCoupMachine());
        getVue()->modificationColor();
        break;
    case etatFinal:
        break;
        //
    }

}

void Presentation::choisirCiseau()
{
    qDebug() << "Je suis la presentation bouton ciseau" << Qt :: endl;
    switch(getEtatJeu())
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Modele::ciseau);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        getVue()->afficherScoreJoueur(getModele()->getScoreJoueur());
        getVue()->afficherScoreMachine(getModele()->getScoreMachine());
        getVue()->afficherCoupJoueur(getModele()->getCoupJoueur());
        getVue()->afficherCoupMachine(getModele()->getCoupMachine());
        getVue()->modificationColor();
        break;
    case etatFinal:
        break;

    }
}

void Presentation::choisirPapier()
{
    qDebug() << "Je suis la presentation bouton Papier" << Qt :: endl;
    switch(getEtatJeu())
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Modele::papier);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        getVue()->afficherScoreJoueur(getModele()->getScoreJoueur());
        getVue()->afficherScoreMachine(getModele()->getScoreMachine());
        getVue()->afficherCoupJoueur(getModele()->getCoupJoueur());
        getVue()->afficherCoupMachine(getModele()->getCoupMachine());
        getVue()->modificationColor();
        break;
    case etatFinal:
        break;
    }
}

/*
void Presentation::choisirCoup(Modele::UnCoup p_coup)
{

}
*/
