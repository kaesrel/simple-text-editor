#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextDocument>
#include "finddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionFind_triggered();

    void on_findDialog_button_clicked(QString keyword, QTextDocument::FindFlags options);

private:
    Ui::MainWindow *ui;
    FindDialog *findDialog;

};
#endif // MAINWINDOW_H
