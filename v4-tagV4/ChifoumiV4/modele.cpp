#include "modele.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODèLE ---------------------------

Modele::Modele():
    scoreJoueur(0),
    scoreMachine(0),
    coupJoueur(rien),
    coupMachine(rien){}

Modele::~Modele()
{
    //dtor
}

        /// Getters

Modele::UnCoup Modele::getCoupJoueur(){
    return this->coupJoueur;
}

Modele::UnCoup Modele::getCoupMachine() {
    return this->coupMachine;
}

unsigned int Modele::getScoreJoueur() {
    return this->scoreJoueur;
}

unsigned int Modele::getScoreMachine() {
    return this->scoreMachine;
}

char Modele::determinerGagnant() {
    char gagnantARetourner;

        // avant de commencer : match nul
        gagnantARetourner = 'N';

        // il sera modifié dans l'un des cas suivants

        if(this->coupJoueur == pierre){

            if(this->coupMachine == papier){
                gagnantARetourner = 'M';
            }
            else if(this->coupMachine == ciseau){
                gagnantARetourner = 'J';
            }

        }
        else if(this->coupJoueur == papier){

            if(this->coupMachine == ciseau){
                gagnantARetourner = 'M';
            }
            else if(this->coupMachine == pierre){
                gagnantARetourner = 'J';
            }

        }
        else if(this->coupJoueur == ciseau){

            if(this->coupMachine == pierre){
                gagnantARetourner = 'M';
            }
            else if(this->coupMachine == papier){
                gagnantARetourner = 'J';
            }

        }

        return gagnantARetourner;
}

         ///* Méthodes utilitaires du Modèle

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Modele::UnCoup Modele::genererUnCoup(){
    UnCoup valeurGeneree;   // valeur à retourner
    int randCoup = randMinMax(0,3);

    switch(randCoup){
        case 0:
            valeurGeneree = pierre;
            break;
        case 1:
            valeurGeneree = papier;
            break;
        case 2:
            valeurGeneree = ciseau;
            break;
    }

    return valeurGeneree;
}

        /// Setters

void Modele::setCoupJoueur(UnCoup p_coup) {
    this->coupJoueur = p_coup;
}

void Modele::setCoupMachine(UnCoup p_coup) {
    this->coupMachine = p_coup;
}

void Modele::setScoreJoueur(unsigned int p_score) {
    this->scoreJoueur = p_score;
}

void Modele::setScoreMachine(unsigned int p_score) {
    this->scoreMachine = p_score;
}

void Modele::majScores(char p_gagnant) {
    if( p_gagnant == 'J'){
        this->scoreJoueur++;
    }
    else if( p_gagnant == 'M'){
        this->scoreMachine++;
    }
}

void Modele::initScores() {
    this->scoreJoueur = 0;
    this->scoreMachine = 0;
}

void Modele::initCoups() {
    this->coupJoueur = rien;
    this->coupMachine = rien;
}
