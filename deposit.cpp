#include "deposit.h"
#include "ui_deposit.h"

float g_funds;

deposit::deposit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deposit)
{
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
            QMessageBox::warning(this,"Eroare!","Nu ati introdus un numar valid");
            return;
        }
    }

    float funds_deposit_converted = funds_deposit.toFloat();
    g_funds = g_funds + funds_deposit_converted;

    ui->NEWS->show();
    ui->NEWS->setText("Felicitari, acum aveti suma de " + QString::number(g_funds));
    ui->AMOUNT->clear();

    modify_funds("/home/cosmin/banking-system/funds","/home/cosmin/banking-system/auxiliar");
}


void deposit::on_IESIRE_clicked()
{
    exit(1);
}

