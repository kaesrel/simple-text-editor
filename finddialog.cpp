#include "finddialog.h"
#include "ui_finddialog.h"
#include <QMessageBox>

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_findButton_clicked()
{
    m_keyword = ui->lineEdit->text();

    if (!m_keyword.isEmpty())
    {
        QTextDocument::FindFlags options;
        if (ui->backwardBox->isChecked())
            options |= QTextDocument::FindBackward;
        if (ui->wordBox->isChecked())
            options |= QTextDocument::FindWholeWords;
        if (ui->caseBox->isChecked())
            options |= QTextDocument::FindCaseSensitively;

        emit FindButtonClick(m_keyword, options);
    }
}


void FindDialog::on_closeButton_clicked()
{
    this->close();
}

