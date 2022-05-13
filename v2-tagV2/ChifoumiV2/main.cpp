#include "chifoumivue.h"
#include "modele.h"
#include "presentation.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Creation de la Vue
    ChifoumiVue w;
    //Creation d'un objet jeu
    Modele *m = new Modele();
    //Creation de la presentation
    Presentation *p = new Presentation();

    //Application du modele MVP
    w.setPresentation(p);
    p->setModele(m);
    p->setVue(&w);

    qDebug() << "Score Joueur = "<< m->getScoreJoueur() << Qt :: endl;
    qDebug() << "Score Machine = "<< m->getScoreJoueur() << Qt :: endl;
    qDebug() << "Modele = "<< m << Qt :: endl;
    w.show();
    return a.exec();
}
