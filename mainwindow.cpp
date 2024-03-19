#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "bankingwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {color : white; }");
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::close();
    OperationalWindow =new BankingWindow();
    OperationalWindow->change_name();
    OperationalWindow->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::close();
}

