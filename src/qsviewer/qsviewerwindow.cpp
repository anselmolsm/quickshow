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

    if (sourceFile.isEmpty())
        m_view->setSource(QUrl("qrc:/viewer.qml"));
    else
        m_view->setSource(QUrl(sourceFile));

    setCentralWidget(m_view);

    // Remove the status bar
    setStatusBar(0);

    // ESC quits the full screen mode
    connect(m_view->engine(), SIGNAL(quit()), this, SLOT(quitFullScreen()));
}

QSViewerWindow::~QSViewerWindow()
{
    delete ui;
}

void QSViewerWindow::on_action_Quit_triggered()
{
    qApp->quit();
}

void QSViewerWindow::quitFullScreen()
{
    if (!isFullScreen())
        return;

    menuBar()->show();
    showMaximized();
}

void QSViewerWindow::on_action_Fullscreen_triggered()
{
    menuBar()->hide();
    showFullScreen();
}

void QSViewerWindow::on_action_Open_triggered()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
                                                          tr("Open Presentation"),
                                                          QDir::homePath(),
                                                          tr("QML files (*.qml)"));
    if (fileName.isEmpty())
        return;

    m_view->setSource(fileName);
}
