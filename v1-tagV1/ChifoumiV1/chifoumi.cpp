/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe métier (= modèle) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODèLE ---------------------------

Chifoumi::Chifoumi():
    scoreJoueur(0),scoreMachine(0),coupJoueur(rien),coupMachine(rien)
{
    //ctor
    // partie modèle
}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

char Chifoumi::determinerGagnant() {
    //Initialisation des variables
    char gagnantARetourner;
    // gagnantARetourner >> avant de commencer >> gagnantARetourner
    // match nul
    gagnantARetourner = 'N';

    // gagnantARetourner >> Traitement du jeu >> gagnantARetourner
    if(coupJoueur == pierre){
        if(coupMachine == papier){
           gagnantARetourner = 'M';
        }
        else if(coupMachine == ciseau){
            gagnantARetourner = 'J';
        }
    }
    else if(coupJoueur == papier){
        if(this->coupMachine == ciseau){
            gagnantARetourner = 'M';
        }
        else if(coupMachine == pierre){
            gagnantARetourner = 'J';
        }
    }
    else if(coupJoueur == ciseau){
        if(coupMachine == pierre){
            gagnantARetourner = 'M';
        }
        else if(coupMachine == papier){
            gagnantARetourner = 'J';
        }
    }
    // gagnantARetourner >> Retourner le gagant
    return gagnantARetourner;
}

         ///* Méthodes utilitaires du Modèle

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur à retourner
    int randCoup = randMinMax(0,3);
    switch (randCoup) {
        case 0 : valeurGeneree = pierre;
        break;
    case 1 : valeurGeneree = papier;
        break;
    case 2: valeurGeneree = ciseau;
        break;
    }
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    if(p_gagnant == 'J'){scoreJoueur++;
    }
    else if (p_gagnant == 'M') {scoreMachine++;
    }
}

void Chifoumi::initScores() {
    scoreJoueur = 0;
    scoreMachine=0;
}

void Chifoumi::initCoups() {
    coupJoueur = rien;
    coupMachine=rien;
}
