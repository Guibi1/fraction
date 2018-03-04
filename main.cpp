#include <QApplication>
#include <QString>
#include <QTranslator>

#include "guibi.h"
#include "fenfraction.h"
#include "stylefraction.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Installation de la traduction
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("calcul_") + locale);
    app.installTranslator(&translator);

    // Applique le style
    app.setStyle(new StyleFraction);

    // Démmare l'application
    FenFraction fen;
    if (!demmarerApp(fen, fen.getFilesList(), false))
        return -1;

    return app.exec();
}

