#ifndef FENFRACTION_H
#define FENFRACTION_H

#include <QMainWindow>
#include <QPushButton>
#include <QStringList>

class FenFraction : public QMainWindow
{
public:
    FenFraction(QWidget *parent = Q_NULLPTR);

    static QStringList getFilesList();

    QPushButton *push;
};

#endif // FENFRACTION_H
