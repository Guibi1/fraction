#include "stylefraction.h"

StyleFraction::StyleFraction()
{

}

// Dessine les objets
void StyleFraction::drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    int rectX;
    int rectY;
    int rectW;
    int rectH;
    opt->rect.getRect(&rectX, &rectY, &rectW, &rectH);

    p->setRenderHint(QPainter::Antialiasing);

    switch (pe) {
    // Si c'est un QPushButton
    case PE_PanelButtonCommand:
        if (opt->state & State_Enabled)
        {
            QLinearGradient lg;
            lg.setStart(0, 0);
            lg.setFinalStop(0, rectH + 2);
            lg.setSpread(QGradient::ReflectSpread);
            lg.setColorAt(0, QColor(8, 163, 0));
            lg.setColorAt(0.5, QColor(9, 188, 0));
            lg.setColorAt(1, QColor(5, 107, 0));
            p->save();
            p->setPen(QColor(2, 70, 2));
            p->setBrush(QBrush(lg));
            p->drawRoundedRect(rectX, rectY, rectW, rectH, 4, 4, Qt::AbsoluteSize);
            p->restore();
        }

        else if (opt->state & State_MouseOver && opt->state & State_Enabled)
        {
            QLinearGradient lg;
            lg.setStart(0, 0);
            lg.setFinalStop(0, rectH + 2);
            lg.setSpread(QGradient::ReflectSpread);
            lg.setColorAt(0, QColor(68, 166, 68));
            lg.setColorAt(0.5, QColor(102, 214, 102));
            lg.setColorAt(1, QColor(49, 130, 49));

            p->save();
            p->setPen(QColor(39, 79, 39));
            p->setBrush(QBrush(lg));
            p->drawRoundedRect(rectX, rectY, rectW, rectH, 4, 4, Qt::AbsoluteSize);
            p->restore();
        }

        else if (opt->state & (State_Sunken | State_On) && opt->state & State_Enabled)
        {
            QLinearGradient lg;
            lg.setStart(0, 0);
            lg.setFinalStop(0, rectH + 2);
            lg.setSpread(QGradient::ReflectSpread);
            lg.setColorAt(0, QColor(16, 130, 16));
            lg.setColorAt(0.5, QColor(24, 153, 24));
            lg.setColorAt(1, QColor(32, 114, 32));

            p->save();
            p->setPen(QColor(24, 71, 24));
            p->setBrush(QBrush(lg));
            p->drawRoundedRect(rectX, rectY, rectW, rectH, 4, 4, Qt::AbsoluteSize);
            p->restore();
        }

        else
        {
            p->save();
            p->setPen(QColor(173, 178, 181));
            p->setBrush(QBrush(QColor(187, 232, 187)));
            p->drawRoundedRect(rectX, rectY, rectW, rectH, 4, 4, Qt::AbsoluteSize);
            p->restore();
        }
        break;

    case PE_IndicatorSpinUp:

        p->save();
        p->setPen(QColor(173, 178, 181));
        p->setBrush(QBrush(QColor(187, 232, 187)));
        p->drawRect(rectX, rectY, rectW, rectH);
        p->restore();
        break;

    case PE_IndicatorSpinDown:

        p->save();
        p->setPen(QColor(173, 178, 181));
        p->setBrush(QBrush(QColor(187, 232, 187)));
        p->drawRect(rectX, rectY, rectW, rectH);
        p->restore();
        break;

    default:
        QCommonStyle::drawPrimitive(pe, opt, p, w);
        break;
    }
}

void StyleFraction::drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *w) const
{
    int rectX;
    int rectY;
    int rectW;
    int rectH;
    opt->rect.getRect(&rectX, &rectY, &rectW, &rectH);



    if (cc == CC_SpinBox)
    {
        const QStyleOptionSpinBox *optSB = qstyleoption_cast<const QStyleOptionSpinBox *>(opt);

        if (optSB->state & State_Enabled)
        {
            if (optSB->stepEnabled & QAbstractSpinBox::StepUpEnabled)
            {
                p->save();
                p->setPen(QColor(0, 0, 0));
                p->setBrush(QBrush(QColor(Qt::blue)));
                p->drawRect(rectX, rectY, rectW, rectH);
                p->restore();
            }

            else
            {
                p->save();
                p->setPen(QColor(100, 100, 100));
                p->setBrush(QBrush(QColor(Qt::cyan)));
                p->drawRect(rectX, rectY, rectW, rectH);
                p->restore();
            }

            if (optSB->stepEnabled & QAbstractSpinBox::StepDownEnabled)
            {
                p->save();
                p->setPen(QColor(0, 0, 0));
                p->setBrush(QBrush(QColor(Qt::blue)));
                p->drawRect(rectX, rectY, rectW, rectH);
                p->restore();
            }

            else
            {
                p->save();
                p->setPen(QColor(100, 100, 100));
                p->setBrush(QBrush(QColor(Qt::cyan)));
                p->drawRect(rectX, rectY, rectW, rectH);
                p->restore();
            }
            drawPrimitive(PE_IndicatorSpinUp, opt, p, w);
        }
    }

    else
        QCommonStyle::drawComplexControl(cc, opt, p, w);
}

void StyleFraction::drawControl(ControlElement ce, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    QCommonStyle::drawControl(ce, opt, p, w);
}

// Pour le "isHover"
void StyleFraction::polish(QWidget *w)
{
    w->setAttribute(Qt::WA_Hover, true);
}

// Pour le "isHover"
void StyleFraction::unpolish(QWidget *w)
{
    w->setAttribute(Qt::WA_Hover, false);
}

// Dessine le texte
void StyleFraction::drawItemText(QPainter *p, const QRect &rect, int align, const QPalette &pal, bool enabled, const QString &text, QPalette::ColorRole textRole) const
{
    if(enabled)
    {
        if (p->background().color() == QColor())
            p->setPen(QPen(QColor(Qt::white)));

        else
            p->setPen(QPen(QColor(Qt::black)));
    }

    else
        p->setPen(QPen(QColor(125, 125, 125)));

    p->drawText(rect, align, text);
}

void StyleFraction::drawItemPixmap(QPainter *p, const QRect &rect, int alig, const QPixmap &pix) const
{
    p->drawPixmap(rect, pix);
}






