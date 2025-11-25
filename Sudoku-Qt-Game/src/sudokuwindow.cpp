#include "sudokuwindow.h"
#include "ui_sudokuwindow.h"
#include "lost.h"
#include "won.h"



QVector<QTextEdit*> findQTextEditWidgets(QWidget* parent) {
    QVector<QTextEdit*> textEdits;

    // Iterate through all direct children of the parent widget
    const QObjectList& children = parent->children();
    for (QObject* child : children) {
        // Check if the child is a QTextEdit
        QTextEdit* textEdit = qobject_cast<QTextEdit*>(child);
        if (textEdit) {
            // If it's a QTextEdit, add it to the vector
            textEdits.append(textEdit);
        }
    }
    // Sort the QTextEdit widgets based on their object names
    std::sort(textEdits.begin(), textEdits.end(),
              [](const QTextEdit* a, const QTextEdit* b) {
                  return a->objectName() < b->objectName();
              });


    return textEdits;
}

// K = # of tiles removed

sudokuwindow::sudokuwindow(QWidget *parent, QString Message, int K) :
    QDialog(parent),
    ui(new Ui::sudokuwindow)
{

    // sets up the default parameters
    ui->setupUi(this);
    ui->DLabel->setText(Message);
    if(Message == "Difficulty: Easy"){
       ui->livesLabel->setText("Lives Remaining: 3");
    }
    else if(Message == "Difficulty: Medium"){
        ui->livesLabel->setText("Lives Remaining: 2");
    }
    else if (Message == "Difficulty: Hard"){
        ui->livesLabel->setText("Lives Remaining: 1");
    }


    // stores the objects of each TextEdit(tile) into a vector
    textEdits = findQTextEditWidgets(this);

    //clears the tiles to ensure they are empty
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            str[i][j] = textEdits[i]->toPlainText();
        }
    }

    //converts the tiles to an integer array so they can be filled
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = str[i][j].toInt();
        }
    }

    //fills the tiles with randomized numbers
    fillValues(K);

    //converts back to a string so they can be inserted into the TextEdit objects
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            str[i][j] = QString::number(arr[i][j]);
            if(str[i][j] == '0')
            {
                str[i][j] = "";
            }
        }
    }

    int p = 0;
    for(int a = 0; a < 9; a++)
    {
        for(int b = 0; b < 9; b++)
        {
            textEdits[p++]->setText(str[a][b]);
        }
    }

    show();
}

//ui->box45->setStyleSheet("background-color:lightgreen;");
/************************************************************/

// Sudoku Generator
void sudokuwindow::fillValues(int numRemoved)
{

    // Fill the diagonal of SRN x SRN arrrices
    fillDiagonal();

    // Fill remaining blocks
    fillRemaining(0, SRN);

    // Remove Randomly K digits to make game
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            originalArr[i][j] = arr[i][j];
        }
    }
    removeKDigits(numRemoved);
}

void sudokuwindow::fillDiagonal()
{
    for (int i = 0; i < N; i = i + SRN)
    {

        // for diagonal box, start coordinates->i==j
        fillBox(i, i);
    }
}

// Fill a 3 x 3 arrrix.
void sudokuwindow::fillBox(int row, int col)
{
    int num;
    for (int i = 0; i < SRN; i++) {
        for (int j = 0; j < SRN; j++) {
            do {
                num = randomGenerator(N);
            } while (!unUsedInBox(row, col, num));
            arr[row + i][col + j] = num;
        }
    }
}

// Random generator
int sudokuwindow::randomGenerator(int num)
{
    return (int)floor(
        (float)(rand() / double(RAND_MAX) * num + 1));
}

// Returns false if given 3 x 3 block contains num.
bool sudokuwindow::unUsedInBox(int rowStart, int colStart, int num)
{
    for (int i = 0; i < SRN; i++) {
        for (int j = 0; j < SRN; j++) {
            if (arr[rowStart + i][colStart + j]
                == num) {
                return false;
            }
        }
    }
    return true;
}

// Check if safe to put in cell
bool sudokuwindow::CheckIfSafe(int i, int j, int num)
{
    return (
        unUsedInRow(i, num) && unUsedInCol(j, num)
        && unUsedInBox(i - i % SRN, j - j % SRN, num));
}

// check in the row for existence
bool sudokuwindow::unUsedInRow(int i, int num)
{
    for (int j = 0; j < N; j++) {
        if (arr[i][j] == num) {
            return false;
        }
    }
    return true;
}

// check in the row for existence
bool sudokuwindow::unUsedInCol(int j, int num)
{
    for (int i = 0; i < N; i++) {
        if (arr[i][j] == num) {
            return false;
        }
    }
    return true;
}

bool sudokuwindow::fillRemaining(int i, int j)
{
    // System.out.println(i+" "+j);
    if (j >= N && i < N - 1) {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N) {
        return true;
    }
    if (i < SRN) {
        if (j < SRN) {
            j = SRN;
        }
    }
    else if (i < N - SRN) {
        if (j == (int)(i / SRN) * SRN) {
            j = j + SRN;
        }
    }
    else {
        if (j == N - SRN) {
            i = i + 1;
            j = 0;
            if (i >= N) {
                return true;
            }
        }
    }
    for (int num = 1; num <= N; num++) {
        if (CheckIfSafe(i, j, num)) {
            arr[i][j] = num;
            if (fillRemaining(i, j + 1)) {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}

// Remove the K no. of digits to
// complete game
void sudokuwindow::removeKDigits(int numRemoved)
{

    int count = numRemoved;
    while (count != 0) {
        int cellId = randomGenerator(N * N) - 1;
        // System.out.println(cellId);
        // extract coordinates i and j
        int i = (cellId / N);
        int j = cellId % N;
        if (j != 0) {
            j = j - 1;
        }
        // System.out.println(i+" "+j);
        if (arr[i][j] != 0) {
            count--;
            arr[i][j] = 0;

            SolvedArr[i][j] = 100;
        }
    }

}
//deallocates sudoku board
sudokuwindow::~sudokuwindow()
{
    delete ui;
}



void sudokuwindow::on_SolverButton_clicked()
{
    if(lives != 0){

    }
    bool extern SolveSudoku(int (*arr)[9]);
    int i = 0, j = 0, k = 0;
    //ptr to point to each TextEdit object
    QVector<QTextEdit*>* VectorObjPtr = &textEdits;


    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            arr[i][j] = str[i][j].toInt();
        }
    }

    SolveSudoku(arr);


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            str[i][j] = QString::number(arr[i][j]);
            textEdits[k]->setText(str[i][j]);

            //this identifies which tiles that are solved by the solver to higlight
            if(SolvedArr[i][j] == 100){
            QTextEdit* ptr = (*VectorObjPtr)[k];
            connect(ptr, &QTextEdit::textChanged, this, [=]() {
                // Update the style sheet when the text changes
                ptr->setStyleSheet("background-color: lightgreen;");
            });
            }
            k++;
        }
    }

}


void sudokuwindow::on_SubmitButton_clicked() {

    if(lives != 0){
        lives--;

        if(lives == 3){
            ui->livesLabel->setText("Lives Remaining: 3");
        }
        else if(lives == 2){
            ui->livesLabel->setText("Lives Remaining: 2");
        }
        else if (lives == 1){
            ui->livesLabel->setText("Lives Remaining: 1");
        }
        else{
            ui->livesLabel->setText("Lives Remaining: 0");
        }



        // Convert user input to integer array
        int userArr[9][9];
        int k = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                QString userInput = textEdits[k]->toPlainText();
                // Check if the user input is empty
                if (userInput.isEmpty()) {
                    // Leave the corresponding tile blank
                    userArr[i][j] = 0;
                } else {
                    // Convert the user input to integer
                    userArr[i][j] = userInput.toInt();
                }
                k++;
            }
        }

        // Check user input against original puzzle

        k = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                QTextEdit* tile = textEdits[k];
                if (arr[i][j] == 0) {
                    // This tile was originally blank
                    if (userArr[i][j] == originalArr[i][j] && userArr[i][j] != 0) {
                        // Correct input
                        tile->setStyleSheet("background-color: lightgreen;");

                    } else {
                        // Incorrect input
                        tile->setStyleSheet("background-color: red;");
                    }
                }
                k++;
            }
        }



        bool win;

        k = 0;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(arr[i][j] == 0){
                    if(userArr[i][j] == originalArr[i][j] && userArr[i][j] != 0){
                        win = true;
                    }
                    else{
                        win = false;
                        break;
                    }
                }

            }
        }

        if(win == true){
            for(int i = 0; i < textEdits.size(); i++){
                textEdits[i++]->clear();
            }
            this->close();
            Won *v = new Won();
            v->setWindowTitle("Victory!");
            v->setAttribute(Qt::WA_DeleteOnClose,true);
            v->show();
        }


    }

    else{

        for(int i = 0; i < textEdits.size(); i++)
        {
            textEdits[i++]->clear();
        }
        this->close();

        Lost *l = new Lost();
        l->setWindowTitle("Retry");
        l->setAttribute(Qt::WA_DeleteOnClose,true);
        l->show();


        }


}





//clears the tiles upon closing window
void sudokuwindow::on_sudokuwindow_destroyed(){

    for(int i = 0; i < textEdits.size(); i++)
    {
        textEdits[i++]->clear();
    }
    this->close();

}

