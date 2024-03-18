#include "deposit.h"
#include "ui_deposit.h"
#include "new_action.h"

float g_funds;
std::string path_aux("/home/cosmin/banking-system/auxiliar");

deposit::deposit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deposit)
{
    setWindowTitle("Depunere");
    ui->setupUi(this);
    ui->NEWS->hide();
}

deposit::~deposit()
{
    delete ui;
}

void deposit::on_DEPUNE_clicked()
{
    QString funds_deposit = ui->AMOUNT->text();

    for(int i = 0; i < funds_deposit.size(); i++){
        if(!funds_deposit[i].isDigit()){
            if(funds_deposit[i] != '.'){
                QMessageBox::warning(this,"Eroare!","Nu ati introdus un numar valid!");
                ui->AMOUNT->clear();
                return;
            }

            else{
                if(i == 0){
                    QMessageBox::warning(this,"Eroare!","Nu ati introdus un numar valid!");
                    ui->AMOUNT->clear();
                    return;
                }

                else continue;
            }
        }
    }

    float funds_deposit_converted = funds_deposit.toFloat();
    g_funds = g_funds + funds_deposit_converted;

    ui->NEWS->show();
    ui->NEWS->setText("Felicitari, acum aveti suma de " + QString::number(g_funds, 'f', 4) + ".");
    ui->AMOUNT->clear();

    modify_funds(path_funds,path_aux);
}


void deposit::on_IESIRE_clicked()
{
    another_action = new new_action(this);
    another_action->show();
    this->hide();
}

void deposit::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Depunere",
                                                               tr("Esti sigur?\n"),
                                                               QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        qApp->exit();
    }
}


