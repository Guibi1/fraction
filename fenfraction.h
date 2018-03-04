#ifndef FENFRACTION_H
#define FENFRACTION_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QStringList>
#include <QLayout>

class FenFraction : public QMainWindow
{
public:
    FenFraction(QWidget *parent = Q_NULLPTR);

    static QStringList getFilesList();

    QPushButton *push;
    QSpinBox *spin;
};

#endif // FENFRACTION_H
