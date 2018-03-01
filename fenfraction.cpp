#include "fenfraction.h"

FenFraction::FenFraction(QWidget *parent)
    : QMainWindow(parent),
      push(0)
{
    push = new QPushButton("texte", this);
}

QStringList FenFraction::getFilesList()
{
    QStringList listeFichiers;

    return listeFichiers;
}
