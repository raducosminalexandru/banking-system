#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->BUN_VENIT->setText("Bine ai venit, " + QString::fromStdString(g_username));
}



Menu::~Menu()
{
    delete ui;
}



void Menu::on_DEPUNERE_clicked()
{
    dep = new deposit(this);
    dep->show();

    this->hide();
}


void Menu::on_RETRAGERE_clicked()
{
    wit = new withdrawal(this);
    wit->show();
    this->hide();
}


void Menu::on_VERIFICARE_BALANTA_clicked()
{
    bal = new balance_check(this);
    bal->show();
    this->hide();
}


void Menu::on_VERIFICARE_CONTURI_clicked()
{
    acc = new account(this);
    acc->show();
    this->hide();
}


void Menu::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.bcr.ro/ro/persoane-fizice/help-center"));
}

void Menu::on_IESIRE_clicked()
{
    qApp->exit();
}


