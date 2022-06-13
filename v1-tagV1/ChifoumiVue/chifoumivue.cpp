#include "chifoumivue.h"
#include "ui_chifoumivue.h"

#include <QDebug>

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    connect(ui->bPierre,SIGNAL (clicked()), this, SLOT(choixPierre()));
    connect(ui->bPapier,SIGNAL (clicked()), this, SLOT(choixPapier()));
    connect(ui->bCiseau,SIGNAL (clicked()), this, SLOT(choixCiseaux()));
    connect(ui->bNouvellePartie,SIGNAL (clicked()),this,SLOT(nouvellePartie()));

    etat = etatInitial;
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::choixPierre()
{
    switch(etat)
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Chifoumi::pierre);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        afficherValeursJoueurs();
        ui->bNouvellePartie->setFocus();
        break;
    }
}

void ChifoumiVue::choixPapier()
{
    switch(etat)
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Chifoumi::papier);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        afficherValeursJoueurs();
        ui->bNouvellePartie->setFocus();
        break;
    }
}

void ChifoumiVue::choixCiseaux()
{
    switch(etat)
    {
    case etatInitial:
        // ---
        break;
    case partieEnCours:
        // pas de changement d'état
        // activité 2
        getModele()->setCoupJoueur(Chifoumi::ciseau);
        getModele()->setCoupMachine(getModele()->genererUnCoup());
        getModele()->majScores(getModele()->determinerGagnant());

        afficherValeursJoueurs();
        ui->bNouvellePartie->setFocus();
        break;
    }
}

ChifoumiVue::UnEtatJeu ChifoumiVue::getEtat()
{
    return etat;
}

void ChifoumiVue::setEtat(UnEtatJeu e)
{
    etat = e;
}

void ChifoumiVue::majActivationBoutons(UnEtatJeu e)
{
    switch (e)
    {
    case etatInitial:
        ui->bCiseau->setEnabled(false);
        ui->bPapier->setEnabled(false);
        ui->bCiseau->setEnabled(false);
        ui->bNouvellePartie->setEnabled(true);
        ui->bNouvellePartie->setFocus();
        break;
    case partieEnCours:
        ui->bCiseau->setEnabled(true);
        ui->bPapier->setEnabled(true);
        ui->bPierre->setEnabled(true);
        ui->bNouvellePartie->setEnabled(true);
        ui->bNouvellePartie->setFocus();
        break;
    default:
        break;
    }
}

void ChifoumiVue::nouvellePartie()
{
    switch(etat)
    {
    case etatInitial:
        // changement d'état
        setEtat(partieEnCours);
        // activité 1
        getModele()->initScores();
        getModele()->initCoups();
        afficherValeursJoueurs();
        ui->labelScoreJ->setStyleSheet("color:blue;");
        ui->labelJ->setStyleSheet("color:blue;");
        majActivationBoutons(getEtat());
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
}

Chifoumi *ChifoumiVue::getModele()
{
    return leModele;
}

void ChifoumiVue::setModele(Chifoumi* m)
{
    leModele = m;
}

void ChifoumiVue::afficherValeursJoueurs()
{
    QString scoreM = "";
    QString scoreJ = "";
    ui->figureJoueur->setPixmap(QPixmap(imageDernierCoup(leModele->getCoupJoueur())));
    ui->figureMachine->setPixmap(QPixmap(imageDernierCoup(leModele->getCoupMachine())));
    ui->labelScoreJ->setText(scoreJ.number(leModele->getScoreJoueur()));
    ui->labelScoreM->setText(scoreM.number(leModele->getScoreMachine()));
}

QString ChifoumiVue::imageDernierCoup(Chifoumi::UnCoup coupJoue)
{
    QString image = ""; // valeur à retourner
    switch(coupJoue)
    {
    case Chifoumi::pierre:
        image = ":/images/pierre_115.png";
        break;
    case Chifoumi::papier:
        image = ":/images/papier_115.png";
        break;
    case Chifoumi::ciseau:
        image = ":/images/ciseau_115.png";
        break;
    case Chifoumi::rien:
        image = ":/images/rien_115.png";
        break;
    default:
        break;
    }
    return image;
}
