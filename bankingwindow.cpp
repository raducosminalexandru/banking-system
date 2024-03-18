#include "bankingwindow.h"
#include "ui_bankingwindow.h"

std::string g_username;
int g_position = 0;
std::string path_usernames("/home/cosmin/banking-system/username");
std::string path_funds("/home/cosmin/banking-system/funds");
std::string path_passwords("/home/cosmin/banking-system/passwords");


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

std::string BankingWindow::return_username(){
    QString username = ui->username->text();
    return username.toStdString();
}

void BankingWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    int ok = 0;

    std::map<std::string,std::pair<std::string,int>> data_map = user_details(path_usernames,
                                                                             path_passwords,
                                                                               path_funds);

    for(auto i:data_map){
        g_position++;
        if(i.first == username.toStdString()){
            ok = 1;
            if(i.second.first == password.toStdString()){
                g_username = username.toStdString();
                g_funds = i.second.second;
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

