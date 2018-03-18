#include "fractiongui.h"

FractionGui::FractionGui(QWidget *parent)
{
    FractionGui(&Fraction(0, 0), parent);
}

FractionGui::FractionGui(Fraction const& fraction, QWidget *parent) :
    QGroupBox(parent()),
    spinNum(new QSpinBox),
    spinDeno(new QSpinBox)
{
    setFraction(fraction);
}

/// -*-*- SETs/GETs -*-*-
void FractionGui::setFraction(Fraction const& fraction)
{
    spinNum->setValue(fraction.numerateur());
    spinDeno->setValue(fraction.denominateur());
}

Fraction FractionGui::getFraction()
{
    return Fraction(spinNum->value(), spinDeno->value());
}
