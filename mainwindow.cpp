#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          widget(new MainWidget(this)),
                                          menuBar(new QMenuBar(this)),
                                          statusbar(new QStatusBar(this))
{
    setMenuBar(menuBar);
    setStatusBar(statusbar);

    aboutQtAct = new QAction(QIcon(":/pic/icon/qt-icon.png"), tr("&关于Qt"), this);
    aboutAct = new QAction(QIcon(":/pic/icon/about.png"), tr("&关于SerialAsst"), this);
    helpMenu = menuBar->addMenu(tr("&帮助"));
    helpMenu->addAction(aboutQtAct);
    helpMenu->addAction(aboutAct);
    setCentralWidget(widget);
    statusbar->showMessage(tr("准备就绪"));
    connect(widget, MainWidget::sendStatus, this, setNewMsg);
    timeLabel = new QLabel(statusbar);
    statusBar()->addPermanentWidget(timeLabel);
    timeLabel->setText(QDateTime::currentDateTime().toString());

    connect(aboutQtAct, &QAction::triggered, this, &showAboutQt);
    connect(aboutAct, &QAction::triggered, this, showAbout);
    connect(widget, MainWidget::sendDateTime, this, setDateTime);
    resize(900, 600);
}

void MainWindow::setNewMsg(QString msg)
{
    statusBar()->showMessage(msg);
}

void MainWindow::setDateTime(QString datetime)
{
    timeLabel->setText(datetime);
}

void MainWindow::showAboutQt()
{
      QMessageBox *aboutWindow = new QMessageBox(this);
      aboutWindow->aboutQt(this);
}

void MainWindow::showAbout()
{

}
