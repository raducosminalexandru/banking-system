#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mapping.h"
#include <QLabel>
#include "global.h"
#include "deposit.h"
#include <QMessageBox>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    void change_name(){
        this->setWindowTitle("Meniu");
    }
    ~Menu();

private slots:
    void on_pushButton_3_clicked();

    void on_IESIRE_clicked();

    void on_IESIRE_MENIU_clicked();

    void on_RETRAGERE_clicked();

    void on_VERIFICARE_BALANTA_clicked();

    void on_DEPUNERE_clicked();

    void on_VERIFICARE_CONTURI_clicked();

private:
    Ui::Menu *ui;
    deposit* dep;
};

#endif // MENU_H
