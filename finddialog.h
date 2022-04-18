#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QTextDocument>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

signals:
    void FindButtonClick(const QString &keyword, QTextDocument::FindFlags options);

private slots:
    void on_findButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::FindDialog *ui;
    QString m_keyword;

};

#endif // FINDDIALOG_H
