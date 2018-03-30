#ifndef FENFRACTION_H
#define FENFRACTION_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QStringList>
#include <QBoxLayout>
#include <QComboBox>
#include <QPushButton>

#include "fractiongui.h"
#include "gbarretitre.h"

class FenFraction : public QMainWindow
{
public:
    FenFraction(QWidget *parent = Q_NULLPTR);

    static QStringList getFilesList();


private:
    // GUI principal
    QWidget *widgetLayoutCentral;
    QVBoxLayout *layoutVPincipal;
    QBoxLayout *layoutFraction;
    GBarreTitre *barreTitre;

    // FractionGuis
    FractionGui *fractionUn;
    FractionGui *fractionDeux;
    FractionGui *fractionReduire;
    FractionGui *fractionReponse;

    QComboBox *comboOperateur;
    QPushButton *pushCalculer;
};

#endif // FENFRACTION_H
