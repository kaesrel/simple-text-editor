#include <QFileDialog>
#include <fstream>
#include <string>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      findDialog(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                            tr("Open Text File"), ".", tr("Text Files (*.txt)"));

    if (filename.isEmpty())
        return;

    ui->label->setText(filename);

    ifstream ifs(filename.toStdString());
    string str;

    while (getline(ifs, str))
    {
        ui->textEdit->append(QString::fromStdString(str));
    }
}


void MainWindow::on_actionFind_triggered()
{
    if (findDialog == nullptr)
    {
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(FindButtonClick(QString,QTextDocument::FindFlags)),
                this, SLOT(on_findDialog_button_clicked(QString,QTextDocument::FindFlags)));
    }

    findDialog->show();
    findDialog->raise();  // bring it to foreground
    findDialog->activateWindow();  // make the program focus on the findDialog dialog
}


void MainWindow::on_findDialog_button_clicked(QString keyword, QTextDocument::FindFlags options)
{
    if (!ui->textEdit->find(keyword, options))
    {
        QMessageBox msg;
        msg.setText(("No match found."));
        msg.exec();
    }
}



