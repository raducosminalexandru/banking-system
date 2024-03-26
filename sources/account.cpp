#include "account.h"
#include "ui_account.h"

account::account(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::account)
{
    setWindowTitle("Verificare conturi");
    ui->setupUi(this);
    ui->NAME->setText("Nume: " + QString::fromStdString(g_username));
    ui->FUND->setText("Fonduri: " + QString::number(g_funds, 'f', 4));
}

account::~account()
{
    delete ui;
}
