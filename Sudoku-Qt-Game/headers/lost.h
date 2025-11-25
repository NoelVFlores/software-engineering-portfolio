#ifndef LOST_H
#define LOST_H

#include <QWidget>
#include "ui_lost.h"

namespace Ui {
class Lost;
}

class Lost : public QWidget
{
    Q_OBJECT

public:
    explicit Lost(QWidget *parent = nullptr);
    ~Lost();
    bool exit;

private:
    Ui::Lost *ui;

private slots:
    void on_try_again_clicked();
    void on_exit_clicked();
};

#endif // LOST_H
