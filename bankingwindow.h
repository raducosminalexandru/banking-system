#ifndef BANKINGWINDOW_H
#define BANKINGWINDOW_H

#include <QDialog>
#include "menu.h"
#include "mapping.h"
#include "global.h"

#include <QMessageBox>
#include <fstream>
#include <string>
#include <map>
#include <utility>

namespace Ui {
class BankingWindow;
}

class BankingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankingWindow(QWidget *parent = nullptr);
    void change_name(){
        this->setWindowTitle("Autentificare");
    }
    std::string return_username();
    ~BankingWindow();

private slots:
    void on_login_clicked();

private:
    Ui::BankingWindow *ui;
    Menu *MenuWindow;
};

#endif // BANKINGWINDOW_H
