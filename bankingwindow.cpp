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
