#include "fractiongui.h"

FractionGui::FractionGui(QWidget *parent)
{
    FractionGui(Fraction(0, 0), parent);
}

FractionGui::FractionGui(Fraction const& fraction, QWidget *parent) :
    QWidget(parent),
    layoutPrincipal(new QBoxLayout(QBoxLayout::LeftToRight, this)),
    spinNum(new QSpinBox),
    spinDeno(new QSpinBox)
{
    setFraction(fraction);

    // GUI
    QFrame ligne;
        ligne.setFrameShadow(QFrame::Sunken);
        ligne.setLineWidth(1);

    layoutPrincipal->addWidget(spinNum);
        layoutPrincipal->addWidget(&ligne);
        layoutPrincipal->addWidget(spinDeno);
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
