#include "chifoumivue.h"

#include <QApplication>
#include "chifoumi.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChifoumiVue w;
    Chifoumi *modele = new Chifoumi();
    w.setModele(modele);
    w.afficherValeursJoueurs();
    w.show();
    return a.exec();
}
