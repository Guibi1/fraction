#ifndef FRACTIONGUI_H
#define FRACTIONGUI_H

#include <QGroupBox>
#include <QSpinBox>

#include "fraction.h"


class FractionGui : public Fraction, QGroupBox
{
     Q_OBJECT

public:
    FractionGui(QWidget *parent = Q_NULLPTR);
    FractionGui(Fraction const& fraction, QWidget *parent = Q_NULLPTR);

    Fraction getFraction();


public slots:
    void setFraction(Fraction const& fraction);


private:
    QSpinBox *spinNum;
    QSpinBox *spinDeno;
};

#endif // FRACTIONGUI_H
