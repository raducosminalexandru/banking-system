#include "withdrawal.h"
#include "ui_withdrawal.h"
#include "new_action.h"

withdrawal::withdrawal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::withdrawal)
{
    setWindowTitle("Retragere");
    ui->setupUi(this);
    ui->NEWS->hide();
}

withdrawal::~withdrawal()
{
    delete ui;
}

void withdrawal::on_IESIRE_clicked()
{
    another_action = new new_action(this);
    another_action->show();
    this->hide();
}


void withdrawal::on_RETRAGE_clicked()
{
    QString funds_withdrawal = ui->AMOUNT->text();

    for(int i = 0; i < funds_withdrawal.size(); i++){
        if(!funds_withdrawal[i].isDigit()){
            if(funds_withdrawal[i] != '.'){
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

    float funds_withdrawal_converted = funds_withdrawal.toFloat();

    if(funds_withdrawal_converted > g_funds){
        QMessageBox::warning(this,"Atentie!","Doriti sa retrageti o suma mai mare decat cea pe care o aveti!");
        ui->AMOUNT->clear();
    }

    else {
        g_funds = g_funds - funds_withdrawal_converted;
        ui->NEWS->show();
        ui->NEWS->setText("Felicitari, acum aveti suma de " + QString::number(g_funds, 'f', 4) + ".");
        ui->AMOUNT->clear();
        modify_funds(path_funds, path_aux);
    }
}

void withdrawal::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Retragere",
                                                               tr("Esti sigur?\n"),
                                                               QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        qApp->exit();
    }
}

