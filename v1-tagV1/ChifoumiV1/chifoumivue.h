#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();

public slots:
    void demanderNewPartie();
    void choixPierre();
    void choixPapier();
    void choixCiseau();


private:
    Ui::ChifoumiVue *ui;

    int scoreJ ;
    int scoreM ;
};
#endif // CHIFOUMIVUE_H
