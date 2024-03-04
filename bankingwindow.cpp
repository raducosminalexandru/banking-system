#include "bankingwindow.h"
#include "ui_bankingwindow.h"

BankingWindow::BankingWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BankingWindow)
{
    ui->setupUi(this);

}

BankingWindow::~BankingWindow()
{
    delete ui;
}

void BankingWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username == "test" && password == "test"){
        MenuWindow = new Menu(this);
        MenuWindow->show();
        this->hide();
    }

    else{
        QMessageBox::warning(this,"Eroare!","Ati introdus credentiale invalide!");
    }
}

