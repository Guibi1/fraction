#ifndef STYLEFRACTION_H
#define STYLEFRACTION_H

#include <QStyle>
#include <QProxyStyle>
#include <QStyleOption>
#include <QStyleOptionComplex>
#include <QPainter>
#include <QWidget>
#include <QColor>
#include <QtDebug>

#include <QPushButton>
#include <QSpinBox>


class StyleFraction : public QProxyStyle
{
    Q_OBJECT

public:
    StyleFraction();
    virtual void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = Q_NULLPTR) const;
    virtual void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *w = Q_NULLPTR) const;
    virtual void drawControl(ControlElement ce, const QStyleOption *opt, QPainter *p, const QWidget *w = Q_NULLPTR) const;


    virtual void polish(QWidget *w);
    virtual void unpolish(QWidget *w);
    virtual void drawItemText(QPainter *p, const QRect &rect, int align, const QPalette &pal, bool enabled, const QString &text, QPalette::ColorRole textRole) const;
    virtual void drawItemPixmap(QPainter *p, const QRect &rect, int alig, const QPixmap &pix) const;
};

#endif // STYLEFRACTION_H
