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

#ifndef QUICKSHOW2PDF_H
#define QUICKSHOW2PDF_H

#include <QtCore/QRect>
#include <QtGui/QPainter>
#include <QtGui/QPrinter>
#include <QtDeclarative/QDeclarativeView>

class QWidget;
class QTimerEvent;

class Quickshow2pdf : public QDeclarativeView
{
    Q_OBJECT
public:
    Quickshow2pdf(QWidget *parent = 0);
    ~Quickshow2pdf();

    QRect pageRect() const;
protected:
    void initQPrinter();

    void timerEvent(QTimerEvent *event);

protected slots:
    void sourceLoaded(QDeclarativeView::Status status);

private:
    int m_page;
    int m_nSlides;
    int m_timerId;

    QPrinter m_printer;
    QPainter m_painter;
    QRect m_pageRect;
};

#endif // QUICKSHOW2PDF_H
