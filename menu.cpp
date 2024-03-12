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

}


void Menu::on_VERIFICARE_BALANTA_clicked()
{

}


void Menu::on_VERIFICARE_CONTURI_clicked()
{

}


void Menu::on_pushButton_3_clicked()
{

}

void Menu::on_IESIRE_clicked()
{
    exit(1);
}


