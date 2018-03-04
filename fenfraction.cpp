#include "fenfraction.h"

FenFraction::FenFraction(QWidget *parent)
    : QMainWindow(parent),
      push(new QPushButton("texte")),
      spin(new QSpinBox())
{
    layout()->addWidget(push);
    layout()->addWidget(spin);
}

QStringList FenFraction::getFilesList()
{
    QStringList listeFichiers;

    return listeFichiers;
}
