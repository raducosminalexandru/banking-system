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
    int ok = 0;

    /*if(username == "test" && password == "test"){
        MenuWindow = new Menu(this);
        MenuWindow->change_name();
        MenuWindow->show();
        this->hide();
    }

    else{
        QMessageBox::warning(this,"Eroare!","Ati introdus credentiale invalide!");
    }
    */

    std::map<std::string,std::pair<std::string,int>> data_map = user_details("/home/cosmin/banking-system/username",
                                                                             "/home/cosmin/banking-system/passwords",
                                                                             "/home/cosmin/banking-system/funds");

    for(auto i:data_map){
        if(i.first == username.toStdString()){
            ok = 1;
            if(i.second.first == password.toStdString()){
                MenuWindow = new Menu(this);
                MenuWindow->change_name();
                MenuWindow->show();
                this->hide();
            }

            else{
                QMessageBox::warning(this,"Eroare!","Ati introdus credentiale invalide!");
            }

            break;
        }
    }

    if(ok == 0){
        QMessageBox::warning(this,"Eroare!","Numele nu exista in baza de date!");
    }
}

