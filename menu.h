#ifndef MENU_H
#define MENU_H

#include <QDialog>

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

private:
    Ui::Menu *ui;
};

#endif // MENU_H
