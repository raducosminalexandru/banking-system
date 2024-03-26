#include "balance_check.h"
#include "ui_balance_check.h"

balance_check::balance_check(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::balance_check)
{
    setWindowTitle("Verificare Balanta");
    ui->setupUi(this);
    ui->MESSAGE->setText("Aveti balanta de " + QString::number(g_funds, 'f', 4) + ".");
}

balance_check::~balance_check()
{
    delete ui;
}

void balance_check::on_IESIRE_clicked()
{
    qApp->exit();
}

