#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "chifoumi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue;
class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
    enum UnEtatJeu {etatInitial, partieEnCours}; // états du jeu selon le diagramme état-transition

    Chifoumi* getModele();
    void setModele(Chifoumi *m);
    void afficherValeursJoueurs();
    UnEtatJeu getEtat();
    void setEtat(UnEtatJeu e);
    void majActivationBoutons(UnEtatJeu e);

public slots:
    void nouvellePartie();
    void choixPierre();
    void choixCiseaux();
    void choixPapier();

private:
    Ui::ChifoumiVue *ui;
    Chifoumi* leModele;
    QString imageDernierCoup(Chifoumi::UnCoup c);
    UnEtatJeu etat;


};
#endif // CHIFOUMIVUE_H
