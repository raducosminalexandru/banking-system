#include "new_action.h"
#include "ui_new_action.h"

new_action::new_action(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::new_action)
{
    ui->setupUi(this);
}

new_action::~new_action()
{
    delete ui;
}

void new_action::on_YES_clicked()
{
    menu_window = new Menu();
    menu_window->show();
    this->close();
}


void new_action::on_NO_clicked()
{
    qApp->exit();
}

