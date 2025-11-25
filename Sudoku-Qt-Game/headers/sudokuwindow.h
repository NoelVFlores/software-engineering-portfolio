#ifndef sudokuwindow_H
#define sudokuwindow_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QVector>
#include <QTextEdit>
#include <QObject>

namespace Ui {
class sudokuwindow;
}

class sudokuwindow: public QDialog
{
    Q_OBJECT

public:
    explicit sudokuwindow(QWidget *parent = nullptr);
    ~sudokuwindow();
    sudokuwindow(QWidget *parent = nullptr, QString message = "default", int K = 20);


    int randomGenerator(int num);
    bool CheckIfSafe(int i, int j, int num);
    bool unUsedInRow(int i, int num);
    bool unUsedInCol(int j, int num);
    bool fillRemaining(int i, int j);
    void removeKDigits(int numRemoved);
    void fillBox(int row, int col);
    bool unUsedInBox(int rowStart, int colStart, int num);
    void fillDiagonal();
    void fillValues(int numRemoved);

    int lives = 3;


    int** mat;

    int N = 9;

    // number of columns/rows.
    int SRN = 3;

    // square root of N
  //  int K = 20;
    // No. Of missing digits


    int arr[9][9] = {{0}};
    int originalArr[9][9];


signals:

    void dataAvailable(const QString &data);


public slots:


private slots:

void on_SolverButton_clicked();


void on_sudokuwindow_destroyed();

void on_SubmitButton_clicked();

private:
    Ui::sudokuwindow *ui;
    QVector<QTextEdit*> textEdits;

    QString str[9][9];
    int SolvedArr[9][9];


};


#endif // sudokuwindow_H




