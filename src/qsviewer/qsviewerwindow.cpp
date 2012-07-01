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


#include "qsviewerwindow.h"
#include "ui_qsviewerwindow.h"

#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QFileDialog>
#include <QKeyEvent>

#include <QDebug>

QSViewerWindow::QSViewerWindow(const QString &sourceFile, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QSViewerWindow)
{
    ui->setupUi(this);

    m_view = new QDeclarativeView(this);
    m_view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    m_view->engine()->addImportPath("qrc:/");
    m_view->engine()->addPluginPath("qrc:/");

    if (sourceFile.isEmpty())
        m_view->setSource(QUrl("viewer.qml"));
    else
        m_view->setSource(QUrl(sourceFile));

    setCentralWidget(m_view);

    // Remove the status bar
    setStatusBar(0);
//    installEventFilter(this);
}

QSViewerWindow::~QSViewerWindow()
{
    delete ui;
}


bool QSViewerWindow::eventFilter(QObject *object, QEvent *event)
{
    qDebug() << "filter ";
    if (object == m_view) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            qDebug() << "key: " << keyEvent->key();
            if (keyEvent->key() == Qt::Key_Escape) {
                qDebug() << "esc";
                m_view->showMaximized();
            }
        }
    } else {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(object, event);
    }
    qDebug() << "bla";
}

void QSViewerWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "aaa: " << event->key();
    if (event->key() == Qt::Key_Escape) {
        menuBar()->show();
        showMaximized();
    }
}

void QSViewerWindow::on_action_Quit_triggered()
{
    qApp->quit();
}

void QSViewerWindow::on_action_Fullscreen_triggered()
{
    menuBar()->hide();
    showFullScreen();
}

void QSViewerWindow::on_action_Open_triggered()
{
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Open Presentation"),
                                                          QDir::homePath(),
                                                          tr("QML files (*.qml)"));
    m_view->setSource(fileName);
}
