#include "won.h"
#include "ui_won.h"
#include "mainmenu.h"

void Won::on_play_again_clicked(){
    MainMenu* w = new MainMenu();
    w->show();
    exit = false;
    this->close();
}

void Won::on_exit_clicked(){
    this->close();
    exit = true;
}

Won::~Won(){
    delete ui;
}


Won::Won(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Won)
{
    ui->setupUi(this);


}

