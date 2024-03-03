#ifndef BANKINGWINDOW_H
#define BANKINGWINDOW_H

#include <QDialog>

namespace Ui {
class BankingWindow;
}

class BankingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankingWindow(QWidget *parent = nullptr);
    ~BankingWindow();

private:
    Ui::BankingWindow *ui;
};

#endif // BANKINGWINDOW_H
