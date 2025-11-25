#ifndef WON_H
#define WON_H

#include <QWidget>
#include "ui_won.h"

namespace Ui {
class Won;
}

class Won : public QWidget
{
    Q_OBJECT

public:
    explicit Won(QWidget *parent = nullptr);
    ~Won();
    bool exit;

private:
    Ui::Won *ui;

private slots:
    void on_play_again_clicked();
    void on_exit_clicked();
};

#endif // WON_H
