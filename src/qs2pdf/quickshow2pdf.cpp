/* === This file is part of Quickshow ===
 *
 *   Copyright 2011-2012, Anselmo L. S. Melo <anselmolsm@gmail.com>
 *
 *   Quickshow is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Quickshow is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Quickshow. If not, see <http://www.gnu.org/licenses/>.
 */

#include "quickshow2pdf.h"

#include <QtCore/QTimerEvent>
#include <QtGui/QGraphicsObject>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QKeyEvent>

#include <QDebug>

Quickshow2pdf::Quickshow2pdf(QWidget *parent)
    : QDeclarativeView(parent)
    , m_page(0)
    , m_nSlides(0)
    , m_timerId(0)
{
    initQPrinter();

    connect(this, SIGNAL(statusChanged(QDeclarativeView::Status)),
            this, SLOT(sourceLoaded(QDeclarativeView::Status)));
}

void Quickshow2pdf::initQPrinter()
{
    m_printer.setOutputFormat(QPrinter::PdfFormat);
    m_printer.setFullPage(true);
    m_printer.setOrientation(QPrinter::Landscape);
    m_pageRect = m_printer.pageRect();
    //### output file name
    m_printer.setOutputFileName("/tmp/bla.pdf");

    if (! m_painter.begin(&m_printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }
}

Quickshow2pdf::~Quickshow2pdf()
{
}

void Quickshow2pdf::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QKeyEvent *e = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    m_painter.drawPixmap(this->rect(), QPixmap::grabWidget(this, this->rect()));
    m_page++;

    if (m_page > m_nSlides) {
        m_painter.end();
        killTimer(m_timerId);
        qApp->quit();
    } else {
        m_printer.newPage();
    }

    QApplication::postEvent(this, e);
}

void Quickshow2pdf::sourceLoaded(QDeclarativeView::Status status)
{
    if (status != QDeclarativeView::Ready)
        return;
    QObjectList objectList = rootObject()->children();

    //###
    foreach (QObject *o, objectList) {
        qDebug() << o->metaObject()->className();
        //### Change to check if it inherits Slide_QMLTYPE_5
        if (QString(o->metaObject()->className()).contains("RegularSlide_QMLTYPE_") ||
            QString(o->metaObject()->className()).contains("ImageSlide_QMLTYPE_")) {
            m_nSlides++;
        }
    }

    if (!m_nSlides)
        return;

    setGeometry(m_pageRect);
    m_timerId = startTimer(1000);
}

QRect Quickshow2pdf::pageRect() const
{
    return m_pageRect;
}
