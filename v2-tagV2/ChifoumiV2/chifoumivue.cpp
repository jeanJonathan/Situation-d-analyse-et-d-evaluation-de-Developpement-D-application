#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QDebug>

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

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

void ChifoumiVue::demanderNouvellePartie()
{
   laPresentation->newPartieDemandee();
}

void ChifoumiVue::coupJoueurJoue(Modele::UnCoup p_coup)
{
    laPresentation->coupJoueurJoue(p_coup);
}

Presentation *ChifoumiVue::getPresentation()
{
    return laPresentation;
}

void ChifoumiVue::setPresentation(Presentation *p_presentation)
{
    laPresentation = p_presentation;
}


void ChifoumiVue::setScoreJoueur(unsigned short int p_score)
{
    qDebug() << "scoreJoueur: " << p_score << Qt :: endl;
}


void ChifoumiVue::setScoreMachine(unsigned short int p_score)
{

    qDebug() << "scoreMachine: " << p_score << Qt :: endl;
}


void ChifoumiVue::setCoupJoueur(Modele::UnCoup p_coup)
{
    switch(p_coup)
    {
      case  Modele::ciseau :
            qDebug() << "dernierCoupJoueur : CISEAU" << Qt :: endl;
            break;
      case Modele::papier :
            qDebug() << "dernierCoupJoueur : PAPIER" << Qt :: endl;
            break;
      case Modele::pierre :
            qDebug() << "dernierCoupJoueur : PIERRE" << Qt :: endl;
            break;
      default:
            qDebug() << "dernierCoupJoueur : --" << Qt :: endl;
            break;
    }
    qDebug() << Qt :: endl;
}


void ChifoumiVue::setCoupMachine(Modele::UnCoup p_coup)
{
    switch(p_coup)
    {
      case  Modele::ciseau :
            qDebug() << "dernierCoupMachine : CISEAU" << Qt :: endl;
            break;
      case Modele::papier :
            qDebug() << "dernierCoupMachine : PAPIER" << Qt :: endl;
            break;
      case Modele::pierre :
            qDebug() << "dernierCoupMachine : PIERRE" << Qt :: endl;
            break;
      default:
            qDebug() << "dernierCoupMachine : --" << Qt :: endl;
            break;
    }
    qDebug() << Qt :: endl;
}


void ChifoumiVue::majInterface(Presentation::UnEtatJeu p_etat)
{
    switch(p_etat)
    {
      case Presentation::etatInitial :
            qDebug() << "Interface conforme a : ETAT INITIAL" << Qt :: endl;
            break;
      case Presentation::partieEnCours :
            qDebug() << "Interface conforme a : PARTIE EN COURS" << Qt :: endl;
            break;
      default: break;
    }

    qDebug() << Qt :: endl;
}

void ChifoumiVue::majInterface(Modele::UnCoup coup)
{
    switch (coup) {
        case Modele::pierre:
        /*Description des elements formuler dans le slots de la v1*/

        break;
        case Modele::pierre:

        break;
        case Modele::pierre:

        break;
    default:
        break;
    }
}
void ChifoumiVue::majActivationBoutons(Presentation :: UnEtatJeu e)
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
