#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    // CREATION ET INITIALISATION DES OBJECTS GRAPHIQUES

    // Personnalisation des widgets
    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/rien_115.png"));
    ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/rien_115.png"));

    ui->bPierre->setIcon(QPixmap(":/figureBouton/images/pierre_115.png"));
    ui->bPapier->setIcon(QPixmap(":/figureBouton/images/papier_115.png"));
    ui->bCiseau->setIcon(QPixmap(":/figureBouton/images/ciseau_115.png"));
    ui->figureVersus->setPixmap(QPixmap(":/figureBouton/images/versus_70.png"));

    QString stringsScoreJ;
    QString stringsScoreM;

    scoreJ = 0;
    scoreM = 0;

    stringsScoreJ.setNum(scoreJ);
    stringsScoreM.setNum(scoreM);
    ui->labelScoreJ->setText(stringsScoreJ);
    ui->labelScoreM->setText(stringsScoreM);

    // CONNEXION DES SIGNAUX ET SLOTS
    QObject::connect(ui->bNouvellePartie, SIGNAL(clicked()), this, SLOT(demanderNewPartie()));
    QObject::connect(ui->bPierre, SIGNAL(clicked()), this, SLOT(choixPierre()));
    QObject::connect(ui->bPapier, SIGNAL(clicked()), this, SLOT(choixPapier()));
    QObject::connect(ui->bCiseau, SIGNAL(clicked()), this, SLOT(choixCiseau()));
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

/* DEFINITION DES SLOTS*/

void ChifoumiVue::demanderNewPartie()
{
    qDebug() << "Vous venez de demarrer une nouvelle partie" << Qt :: endl;
    qDebug() << "L'etat du jeu est dans l'etat initial " << Qt :: endl;
    ui->bPierre->setEnabled(true);
    ui->bPapier->setEnabled(true);
    ui->bCiseau->setEnabled(true);

    this->tourmachine->initScores();

    QString stringsScoreJ;
    QString stringsScoreM;

    scoreJ = 0;
    scoreM = 0;

    stringsScoreJ.setNum(scoreJ);
    stringsScoreM.setNum(scoreM);
    ui->labelScoreJ->setText(stringsScoreJ);
    ui->labelScoreM->setText(stringsScoreM);

    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/rien_115.png"));
    ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/rien_115.png"));

}

void ChifoumiVue::choixPierre(){
    qDebug() << "Vous avez choisir de jouer pierre " << Qt :: endl;
    qDebug() << "La partie est en cours " << Qt :: endl;

    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/pierre_115.png"));
    this->tourmachine->setCoupJoueur(Chifoumi :: UnCoup::pierre);
    this->tourmachine->setCoupMachine(this->tourmachine->genererUnCoup());
    switch (this->tourmachine->getCoupMachine()) {
    case Chifoumi::UnCoup::pierre:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/pierre_115.png"));
        break;

    case Chifoumi::UnCoup::papier:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/papier_115.png"));
        break;

    case Chifoumi::UnCoup::ciseau:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/ciseau_115.png"));
        break;

    default:
        break;
    }
    this->tourmachine->majScores(tourmachine->determinerGagnant());

    QString stringsScoreJ;
    QString stringsScoreM;

    stringsScoreJ.setNum(this->tourmachine->getScoreJoueur());
    stringsScoreM.setNum(this->tourmachine->getScoreMachine());

    ui->labelScoreJ->setText(stringsScoreJ);
    ui->labelScoreM->setText(stringsScoreM);

    this->tourmachine->setScoreJoueur(this->tourmachine->getScoreJoueur());
    this->tourmachine->setScoreMachine(this->tourmachine->getScoreMachine());
}



void ChifoumiVue::choixPapier(){
    qDebug() << "Vous avez choisir de jouer papier. C'est au tour de la machine" << Qt :: endl;
    qDebug() << "La partie est en cours " << Qt :: endl;

    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/papier_115.png"));
    this->tourmachine->setCoupJoueur(Chifoumi :: UnCoup::papier);
    this->tourmachine->setCoupMachine(this->tourmachine->genererUnCoup());
    switch (this->tourmachine->getCoupMachine()) {
    case Chifoumi::UnCoup::pierre:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/pierre_115.png"));
        break;

    case Chifoumi::UnCoup::papier:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/papier_115.png"));
        break;

    case Chifoumi::UnCoup::ciseau:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/ciseau_115.png"));
        break;

    default:
        break;
    }

    this->tourmachine->majScores(tourmachine->determinerGagnant());

    QString stringsScoreJ;
    QString stringsScoreM;

    stringsScoreJ.setNum(this->tourmachine->getScoreJoueur());
    stringsScoreM.setNum(this->tourmachine->getScoreMachine());

    ui->labelScoreJ->setText(stringsScoreJ);
    ui->labelScoreM->setText(stringsScoreM);

    this->tourmachine->setScoreJoueur(this->tourmachine->getScoreJoueur());
    this->tourmachine->setScoreMachine(this->tourmachine->getScoreMachine());
}

void ChifoumiVue::choixCiseau(){
    qDebug() << "Vous avez choisir de jouer ciseau. C'est au tour de la machine" << Qt :: endl;
    qDebug() << "La partie est en cours " << Qt :: endl;

    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/ciseau_115.png"));
    this->tourmachine->setCoupJoueur(Chifoumi :: UnCoup::ciseau);
    this->tourmachine->setCoupMachine(this->tourmachine->genererUnCoup());
    switch (this->tourmachine->getCoupMachine()) {
    case Chifoumi::UnCoup::pierre:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/pierre_115.png"));
        break;

    case Chifoumi::UnCoup::papier:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/papier_115.png"));
        break;

    case Chifoumi::UnCoup::ciseau:
        ui->figureMachine->setPixmap(QPixmap(":/figureBouton/images/ciseau_115.png"));
        break;

    default:
        break;
    }

    this->tourmachine->majScores(tourmachine->determinerGagnant());

    QString stringsScoreJ;
    QString stringsScoreM;

    stringsScoreJ.setNum(this->tourmachine->getScoreJoueur());
    stringsScoreM.setNum(this->tourmachine->getScoreMachine());

    ui->labelScoreJ->setText(stringsScoreJ);
    ui->labelScoreM->setText(stringsScoreM);

    this->tourmachine->setScoreJoueur(this->tourmachine->getScoreJoueur());
    this->tourmachine->setScoreMachine(this->tourmachine->getScoreMachine());
}

