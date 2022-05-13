/********************************************************************************
** Form generated from reading UI file 'chifoumivue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMIVUE_H
#define UI_CHIFOUMIVUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChifoumiVue
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *bPierre;
    QPushButton *bPapier;
    QPushButton *bCiseau;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *figureVersus;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *labelScoreM;
    QLabel *figureJoueur;
    QLabel *figureMachine;
    QLabel *labelScoreJ;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *bNouvellePartie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChifoumiVue)
    {
        if (ChifoumiVue->objectName().isEmpty())
            ChifoumiVue->setObjectName(QString::fromUtf8("ChifoumiVue"));
        ChifoumiVue->resize(366, 361);
        centralwidget = new QWidget(ChifoumiVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(59, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        bPierre = new QPushButton(groupBox);
        bPierre->setObjectName(QString::fromUtf8("bPierre"));
        bPierre->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pierre_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPierre->setIcon(icon);
        bPierre->setIconSize(QSize(70, 100));
        bPierre->setAutoDefault(false);
        bPierre->setFlat(true);

        horizontalLayout_2->addWidget(bPierre);

        bPapier = new QPushButton(groupBox);
        bPapier->setObjectName(QString::fromUtf8("bPapier"));
        bPapier->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/papier_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPapier->setIcon(icon1);
        bPapier->setIconSize(QSize(70, 100));
        bPapier->setAutoDefault(false);
        bPapier->setFlat(true);

        horizontalLayout_2->addWidget(bPapier);

        bCiseau = new QPushButton(groupBox);
        bCiseau->setObjectName(QString::fromUtf8("bCiseau"));
        bCiseau->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/ciseau_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bCiseau->setIcon(icon2);
        bCiseau->setIconSize(QSize(70, 100));
        bCiseau->setAutoDefault(false);
        bCiseau->setFlat(true);

        horizontalLayout_2->addWidget(bCiseau);

        horizontalSpacer_6 = new QSpacerItem(59, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        figureVersus = new QLabel(centralwidget);
        figureVersus->setObjectName(QString::fromUtf8("figureVersus"));
        figureVersus->setPixmap(QPixmap(QString::fromUtf8(":/images/versus_70.png")));
        figureVersus->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(figureVersus, 2, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 5, 1, 1);

        labelScoreM = new QLabel(centralwidget);
        labelScoreM->setObjectName(QString::fromUtf8("labelScoreM"));
        labelScoreM->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelScoreM, 1, 5, 1, 1);

        figureJoueur = new QLabel(centralwidget);
        figureJoueur->setObjectName(QString::fromUtf8("figureJoueur"));
        figureJoueur->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(figureJoueur, 2, 5, 1, 1);

        figureMachine = new QLabel(centralwidget);
        figureMachine->setObjectName(QString::fromUtf8("figureMachine"));
        figureMachine->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(figureMachine, 2, 1, 1, 1);

        labelScoreJ = new QLabel(centralwidget);
        labelScoreJ->setObjectName(QString::fromUtf8("labelScoreJ"));
        labelScoreJ->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelScoreJ, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        bNouvellePartie = new QPushButton(centralwidget);
        bNouvellePartie->setObjectName(QString::fromUtf8("bNouvellePartie"));

        gridLayout_2->addWidget(bNouvellePartie, 3, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        ChifoumiVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChifoumiVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 366, 21));
        ChifoumiVue->setMenuBar(menubar);
        statusbar = new QStatusBar(ChifoumiVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChifoumiVue->setStatusBar(statusbar);

        retranslateUi(ChifoumiVue);

        bPierre->setDefault(false);
        bPapier->setDefault(false);
        bCiseau->setDefault(false);


        QMetaObject::connectSlotsByName(ChifoumiVue);
    } // setupUi

    void retranslateUi(QMainWindow *ChifoumiVue)
    {
        ChifoumiVue->setWindowTitle(QCoreApplication::translate("ChifoumiVue", "ChifoumiVue", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ChifoumiVue", "Choisissez une figure :", nullptr));
        bPierre->setText(QString());
        bPapier->setText(QString());
        bCiseau->setText(QString());
        figureVersus->setText(QString());
        label->setText(QCoreApplication::translate("ChifoumiVue", "Vous", nullptr));
        label_2->setText(QCoreApplication::translate("ChifoumiVue", "Machine", nullptr));
        labelScoreM->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        figureJoueur->setText(QCoreApplication::translate("ChifoumiVue", "Choix machine", nullptr));
        figureMachine->setText(QCoreApplication::translate("ChifoumiVue", "Choix joueur", nullptr));
        labelScoreJ->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        bNouvellePartie->setText(QCoreApplication::translate("ChifoumiVue", "Nouvelle Partie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChifoumiVue: public Ui_ChifoumiVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMIVUE_H
