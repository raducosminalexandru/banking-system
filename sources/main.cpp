#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.change_name();
    w.show();
    w.show();
    w.show();
    return a.exec();
}
