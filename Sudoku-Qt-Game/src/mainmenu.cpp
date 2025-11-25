#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "sudokuwindow.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);


}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_easyButton_clicked()
{
    // dynamically allocating the sudoku window and setting default parameters
    this->close();

    sudokuwindow *easysudoku = new sudokuwindow(this, "Difficulty: Easy", 20);
    easysudoku->setWindowTitle("sudoku");
    easysudoku->setAttribute(Qt::WA_DeleteOnClose,true);
    easysudoku->show();
    easysudoku->lives = 3;

}


void MainMenu::on_mediumButton_clicked()
{
    // dynamically allocating the sudoku window and setting default parameters
    this->close();
    sudokuwindow* mediumsudoku = new sudokuwindow(this, "Difficulty: Medium", 35);
    mediumsudoku->setWindowTitle("sudoku");
    mediumsudoku->setAttribute(Qt::WA_DeleteOnClose,true);
    mediumsudoku->show();
    mediumsudoku->lives = 2;

}


void MainMenu::on_hardButton_clicked()
{
    // dynamically allocating the sudoku window and setting default parameters
    this->close();
    sudokuwindow* hardsudoku = new sudokuwindow(this, "Difficulty: Hard", 50);
    hardsudoku->setWindowTitle("sudoku");
    hardsudoku->setAttribute(Qt::WA_DeleteOnClose,true);
    hardsudoku->show();
    hardsudoku->lives = 1;

}
