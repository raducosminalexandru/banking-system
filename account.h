#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>

#include "global.h"

namespace Ui {
class account;
}

class account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();

private:
    Ui::account *ui;
};

#endif // ACCOUNT_H
