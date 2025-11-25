#include "lost.h"
#include "ui_lost.h"
#include "mainmenu.h"

void Lost::on_try_again_clicked(){
    MainMenu* w = new MainMenu();
    w->show();
    exit = false;
    this->close();
}

void Lost::on_exit_clicked(){
    this->close();
    exit = true;
}

Lost::~Lost(){
    delete ui;
}


Lost::Lost(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lost)
{
    ui->setupUi(this);


}

