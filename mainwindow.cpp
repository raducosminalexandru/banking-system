#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "bankingwindow.h"

/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/../Downloads/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}
*/

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
    OperationalWindow =new BankingWindow(this);
    OperationalWindow->change_name();
    OperationalWindow->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::close();
}

