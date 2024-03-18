#ifndef NEW_ACTION_H
#define NEW_ACTION_H

#include <QDialog>

#include "menu.h"

namespace Ui {
class new_action;
}

class new_action : public QDialog
{
    Q_OBJECT

public:
    explicit new_action(QWidget *parent = nullptr);
    ~new_action();

private slots:
    void on_YES_clicked();

    void on_pushButton_2_clicked();

    void on_NO_clicked();

private:
    Ui::new_action *ui;
    Menu* menu_window;
};

#endif // NEW_ACTION_H
