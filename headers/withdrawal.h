#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include "global.h"
#include "modify_files.h"

class new_action;

namespace Ui {
class withdrawal;
}

class withdrawal : public QDialog
{
    Q_OBJECT

public:
    explicit withdrawal(QWidget *parent = nullptr);

    ~withdrawal();

private slots:
    void on_IESIRE_clicked();

    void on_RETRAGE_clicked();

private:
    Ui::withdrawal *ui;
    new_action *another_action;
    void closeEvent(QCloseEvent *event) override;
};

#endif // WITHDRAWAL_H
