#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          widget(new MainWidget(this)),
                                          menuBar(new QMenuBar(this)),
                                          statusbar(new QStatusBar(this))
{
    setMenuBar(menuBar);
    setStatusBar(statusbar);

    aboutQtAct = new QAction(/*QIcon(":/pic/icon/qt-icon.png"), */tr("&关于Qt"), this);
    aboutAct = new QAction(/*QIcon(":/pic/icon/about.png"), */tr("&关于SerialAsst"), this);
    helpMenu = menuBar->addMenu(tr("帮助(&H)"));
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
      QMessageBox *aboutQtWindow = new QMessageBox(this);
      aboutQtWindow->aboutQt(this);
}

void MainWindow::showAbout()
{
    QMessageBox *aboutWindow = new QMessageBox(this);
    aboutWindow->setStandardButtons(QMessageBox::Ok);
    aboutWindow->setText(tr("<h1>SerialAsst</h1>"
                             "<p>Based on Qt 5.10.0 (MinGW 5.3.0, 32bit)</p>"
                             "Source Code: <a href=\"https://github.com/TurnMeOn/SerialAsst\">https://github.com/TurnMeOn/SerialAsst</a><br/>"
                             "<address>"
                            "Email: <a href=\"mailto:cmy1113@yeah.net?subject=SerialAsst Feedback\">TurnMeOn</a>"
                            "</address>"));
    aboutWindow->show();
}
