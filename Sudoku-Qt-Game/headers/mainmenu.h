#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_mediumButton_clicked();

    void on_easyButton_clicked();

   // void onDataAvailable(const QString &data);

    void on_hardButton_clicked();
signals:


private:
    Ui::MainMenu *ui;

};

#endif // MAINMENU_H
