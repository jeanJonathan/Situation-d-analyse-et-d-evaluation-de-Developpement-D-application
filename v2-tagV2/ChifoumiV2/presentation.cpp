#include "presentation.h"

Presentation::Presentation()
{

}
Presentation::UnEtatJeu Presentation::getEtatJeu(){
    return etatJeu;
}

chifoumievue* Presentation::getVue(){
    return laVue;
}

Modele* Presentation::getModele(){
    return leModele;
}


void Presentation::setEtatJeu(UnEtatJeu p_etat){
    etatJeu = p_etat;
}

void Presentation::setVue(chifoumievue* p_vue){
    laVue = p_vue;
}

void Presentation::setModele(Modele* p_modele){
    leModele = p_modele;
}



void Presentation::coupJoueurJoue(Modele::UnCoup p_coup){
    leModele->setCoupJoueur(p_coup);
    leModele->setCoupMachine(leModele->genererUnCoup());

    /*Adapter au contenue des slots de la V1*/

    const char gagnant = leModele->determinerGagnant();
    if(gagnant == 'J'){
        unsigned int score_joueur = leModele->getScoreJoueur()+1;
        leModele->setScoreJoueur(score_joueur);
        //laVue->setScoreJoueur(score_joueur);

    }
    else if(gagnant == 'M'){
        unsigned int score_machine = leModele->getScoreMachine()+1;
        leModele->setScoreMachine(score_machine);
        //laVue->setScoreMachine(score_machine);
    }

    Modele::UnCoup coup_machine = leModele->getCoupMachine();
    /*laVue->setCoupMachine(coup_machine);
    laVue->setCoupJoueur(p_coup);*/

}

void Presentation::newPartieDemandee()
{
    switch(etatJeu)
    {
    case etatInitial:
        // changement d'état
        setEtatJeu(partieEnCours);
        // activité 1
        getModele()->initScores();
        getModele()->initCoups();
        afficherValeursJoueurs();
        majActivationBoutons(getEtatJeu());
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 3
        getModele()->initScores();
        getModele()->initCoups();
        afficherValeursJoueurs();
        ui->bNouvellePartie->setFocus();
        break;
    }
    /*
    leModele->initScores();
    leModele->initCoups();

    etatJeu = partieEnCours;

    unsigned int score_joueur = leModele->getScoreJoueur();
    unsigned int score_machine = leModele->getScoreMachine();
    */

    /*laVue->majInterface(etatJeu);
    laVue->setScoreMachine(score_machine);
    laVue->setScoreJoueur(score_joueur);*/
    /*
    Modele::UnCoup coup_machine = leModele->getCoupMachine();
    Modele::UnCoup coup_joueur = leModele->getCoupJoueur(); */
    /*laVue->setCoupJoueur(coup_joueur);
    laVue->setCoupMachine(coup_machine);*/

}

void Presentation::clickBoutonPapier()
{
    leModele->setCoupJoueur(Modele :: papier);
    //laVue->majInterface(leModele->getCoupJoueur());
}

void Presentation::clickBoutonPierre()
{
    leModele->setCoupJoueur(Modele :: pierre);
    //laVue->majInterface(leModele->getCoupJoueur());
}

void Presentation::clickBoutonCiseau()
{
    leModele->setCoupJoueur(Modele :: ciseau);
    //laVue->majInterface(leModele->getCoupJoueur());
}

void Presentation::clickDemanderNewPartie()
{
    leModele->initScores();
    leModele->initCoups();
    laVue->majInterface(leModele->getCoupJoueur());
}
