#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    // connexions des boutons aux slots
    connect(ui->bNouvellePartie, SIGNAL(clicked()), this, SLOT(demanderNouvellePartie()));
    connect(ui->bPierre, SIGNAL(clicked()), this, SLOT(choisirPierre()));
    connect(ui->bCiseau, SIGNAL(clicked()), this, SLOT(choisirCiseau()));
    connect(ui->bPapier, SIGNAL(clicked()), this, SLOT(choisirPapier()));
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::demanderNouvellePartie()
{
    laPresentation->demanderNouvellePartie();
}

Presentation *ChifoumiVue::getPresentation()
{
    return laPresentation;
}

void ChifoumiVue::choisirCiseau()
{
    laPresentation->choisirCiseau(); // Appel du choix ciseau de la presentation
    ui->bNouvellePartie->setFocus();
}

void ChifoumiVue::choisirPierre()
{
    laPresentation->choisirPierre();
    ui->bNouvellePartie->setFocus();
}

void ChifoumiVue::choisirPapier()
{
    laPresentation->choisirPapier();
    ui->bNouvellePartie->setFocus();
}

void ChifoumiVue::setPresentation(Presentation *p_presentation)
{
    laPresentation = p_presentation;
}

QString ChifoumiVue::imageDernierCoup(Modele::UnCoup coupJoue)
{
    QString image = QString::fromUtf8(""); // valeur à retourner

    switch(coupJoue)
    {
    case Modele::pierre:
        image = ":/images/images/pierre_115.png";
        break;
    case Modele::papier:
        image = ":/images/images/papier_115.png";
        break;
    case Modele::ciseau:
        image = ":/images/images/ciseau_115.png";
        break;
    case Modele::rien:
        image = ":/images/images/rien_115.png";
        break;
    default:
        break;
    }
    return image;
}

void ChifoumiVue::majActivationBoutons(Presentation :: UnEtatJeu e)
{
    switch (e)
   {
   case Presentation::etatInitial:
       ui->bCiseau->setEnabled(false);
       ui->bPapier->setEnabled(false);
       ui->bPierre->setEnabled(false);
       ui->bNouvellePartie->setEnabled(true);
       ui->bNouvellePartie->setFocus();
       break;
   case Presentation::partieEnCours:
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

void ChifoumiVue::modificationColor()
{
    ui->labelJoueur->setStyleSheet("color : blue");
    ui->labelScoreJ->setStyleSheet("color : blue");
}

void ChifoumiVue::afficherScoreJoueur(unsigned int scoreJ)
{
    QString score = "";
    ui->labelScoreJ->setText(score.number(scoreJ));
}

void ChifoumiVue::afficherScoreMachine(unsigned int scoreM)
{
    QString score = "";
    ui->labelScoreM->setText(score.number(scoreM));
}

void ChifoumiVue::afficherCoupJoueur(Modele::UnCoup coupJ)
{
      ui->figureJoueur->setPixmap(QPixmap(imageDernierCoup(coupJ)));
}

void ChifoumiVue::afficherCoupMachine(Modele::UnCoup coupM)
{
    ui->figureMachine->setPixmap(QPixmap(imageDernierCoup(coupM)));
}
/*
void ChifoumiVue::nvlleConnexion(QObject *c)
{
    //pour se connecter avec la presentation
    QObject::connect(ui->bPierre, SIGNAL(clicked()),
    c, SLOT(clickBoutonPierre()));
    QObject::connect(ui->bPapier, SIGNAL(clicked()),
    c, SLOT(clickBoutonPapier()));
    QObject::connect(ui->bNouvellePartie, SIGNAL(clicked()),
    c, SLOT(clickDemanderNewPartie()));
    QObject::connect(ui->bCiseau, SIGNAL(clicked()),
    c, SLOT(clickBoutonCiseau()));

}
*/
/*
void ChifoumiVue::supprConnexion(QObject *c)
{
    //pour se déconnecter de c
    QObject::disconnect(ui->bPierre, SIGNAL(clicked()),
    c, SLOT(clickBoutonPierre()));
    QObject::disconnect(ui->bPapier, SIGNAL(clicked()),
    c, SLOT(clickBoutonPapier()));
    QObject::disconnect(ui->bNouvellePartie, SIGNAL(clicked()),
    c, SLOT(clickDemanderNewPartie()));
    QObject::disconnect(ui->bCiseau, SIGNAL(clicked()),
    c, SLOT(clickBoutonCiseau()));
}
*/
