// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QPainter>
#undef loop /* ugh, remove this when the #define loop is gone from util.h */
#include <QApplication>

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f) :
    QSplashScreen(pixmap, f)
{
    // set reference point, paddings
    int paddingLeftCol1         = 5;
    int paddingTopCols          = 376;
    int paddingLeftCol2         = 300;
    int line1 = 0;
    int line2 = 13;
    int line3 = 26;

    float fontFactor            = 1.0;

    // define text to place
    QString titleText       = QString(QApplication::applicationName()).replace(QString("-testnet"), QString(""), Qt::CaseSensitive); // cut of testnet, place it as single object further down
    QString versionText     = QString("Version %1 ").arg(QString::fromStdString(FormatFullVersion()));
    QString copyrightText1   = QChar(0xA9)+QString(" 2009-2014 ") + QString(tr("The Bitcoin developers"));
    QString copyrightText2   = QChar(0xA9)+QString(" 2011-2014 ") + QString(tr("The Litecoin developers"));
    QString copyrightText3   = QChar(0xA9)+QString(" 2017-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The vDinar developers"));

    QString font            = "Arial";

    // load the bitmap for writing some text over it
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
        newPixmap     = QPixmap(":/images/splash_testnet");
    }
    else {
        newPixmap     = QPixmap(":/images/splash");
    }

    QPainter pixPaint(&newPixmap);
    pixPaint.setPen(QColor(255,90,0));

    // draw copyright owners and years
    pixPaint.setFont(QFont(font, 9*fontFactor));
    pixPaint.drawText(paddingLeftCol1,paddingTopCols+line1,copyrightText1);
    pixPaint.drawText(paddingLeftCol1,paddingTopCols+line2,copyrightText2);
    pixPaint.drawText(paddingLeftCol1,paddingTopCols+line3,copyrightText3);

    // draw version
    pixPaint.setFont(QFont(font, 9*fontFactor));
    pixPaint.drawText(paddingLeftCol2,paddingTopCols+line3,versionText);

    pixPaint.end();

    this->setPixmap(newPixmap);
}
