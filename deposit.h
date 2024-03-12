#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <QMessageBox>
#include "global.h"
#include "modify_files.h"

namespace Ui {
class deposit;
}

class deposit : public QDialog
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

private slots:
    void on_DEPUNE_clicked();

    void on_IESIRE_clicked();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
