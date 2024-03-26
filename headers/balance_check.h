#ifndef BALANCE_CHECK_H
#define BALANCE_CHECK_H

#include <QDialog>

#include "global.h"

namespace Ui {
class balance_check;
}

class balance_check : public QDialog
{
    Q_OBJECT

public:
    explicit balance_check(QWidget *parent = nullptr);
    ~balance_check();

private slots:
    void on_IESIRE_clicked();

private:
    Ui::balance_check *ui;
};

#endif // BALANCE_CHECK_H
