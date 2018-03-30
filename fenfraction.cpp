#include "fenfraction.h"

FenFraction::FenFraction(QWidget *parent)
    : QMainWindow(parent),
      widgetLayoutCentral(new QWidget),
      layoutVPincipal(new QVBoxLayout(widgetLayoutCentral)),
      layoutFraction(new QBoxLayout(QBoxLayout::LeftToRight)),
      barreTitre(0),
      fractionUn(new FractionGui),
      fractionDeux(new FractionGui),
      fractionReduire(new FractionGui),
      fractionReponse(new FractionGui),
      comboOperateur(new QComboBox),
      pushCalculer(new QPushButton(tr("Calculer")))
{
    setWindowTitle("Fraction");
    setCentralWidget(widgetLayoutCentral);

    // GUI
    barreTitre = new GBarreTitre(this);



    layoutFraction->addWidget(fractionUn);
        layoutFraction->addWidget(comboOperateur);
        layoutFraction->addWidget(fractionDeux);

    layoutVPincipal->addWidget(barreTitre, 0, Qt::AlignTop);
        layoutVPincipal->setContentsMargins(11, 0, 11, 11);
        layoutVPincipal->addLayout(layoutFraction);
        layoutVPincipal->addWidget(pushCalculer, 0, Qt::AlignCenter);
        layoutVPincipal->addWidget(fractionReponse, 0, Qt::AlignBaseline);
}

QStringList FenFraction::getFilesList()
{
    QStringList listeFichiers;

    return listeFichiers;
}
