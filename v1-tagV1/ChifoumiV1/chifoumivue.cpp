#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"

Chifoumi :: UnCoup  genererCoup();
/* duplique la méthode privée de la classe Chifoumi,
   pour ne pas modifier le code de la classe en la rendant publique
*/

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

    QString stringsScoreJ;
    QString stringsScoreM;

    scoreJ = 0;
    scoreM = 0;

    stringsScoreJ.setNum(scoreJ);
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
    ui->bPierre->setEnabled(true);
    ui->bPapier->setEnabled(true);
    ui->bCiseau->setEnabled(true);
}

void ChifoumiVue::choixPierre()
{
    //Generation du coup Joueur
    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/pierre_115.png"));

    // Generer le coup machine pour faire jouer la machine...
    Chifoumi tourMachine; //
    Chifoumi :: UnCoup coupMachine;
    tourMachine.setCoupMachine(genererCoup());
    switch (coupMachine) {
        case pierre :


    }
    tourMachine.majScores(tourMachine.determinerGagnant());
}

void ChifoumiVue::choixPapier()
{
    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/papier_115.png"));
    // Generation de coup pour faire jouer la machine...
}

void ChifoumiVue::choixCiseau()
{
    ui->figureJoueur->setPixmap(QPixmap(":/figureBouton/images/ciseau_115.png"));
    // Generation de coup pour faire jouer la machine...
}

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup genererCoup()
{
    Chifoumi::UnCoup valeurGeneree;   // valeur à retourner
    unsigned int nbAleatoire;
    nbAleatoire = rand()%(4-1) + 1;
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = Chifoumi::pierre;
        break;
    case 2 :
        valeurGeneree = Chifoumi::papier;
        break;
    case 3 :
        valeurGeneree = Chifoumi::ciseau;
        break;
    default:
        break;
    }
    return valeurGeneree;
}
