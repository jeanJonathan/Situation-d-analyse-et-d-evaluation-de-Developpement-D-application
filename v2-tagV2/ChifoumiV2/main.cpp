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
    //Creation d'un objet Chifoumi
    Modele *m = new Modele();
    //Creation de la presentation
    Presentation *p = new Presentation();

    //Application du modele MVP
    p->setModele(m);
    p->setVue(&w);
    w.setPresentation(p);

    w.show();
    return a.exec();
}
