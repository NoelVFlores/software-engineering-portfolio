**Sudoku Game - C++ / QT GUI Application**
_A full sudoku game with board generation, solver, submission checking, difficulty modes, and win/lose screens._

This project was developed for EE 5103 - Engineering Programming as a GUI based C++ application using the **QT Framework**.
It features a functional Sudoku generator, interactive board, instant solver, life-based gameplay (difficulty based), validation and dynamic UI updates.


**Features**

**1. Difficulty Selection Menu**
Implemented in MainMenu

* Easy → 20 cells removed, 3 lives

* Medium → 35 cells removed, 2 lives

* Hard → 50 cells removed, 1 life



**2. Sudoku Board Generation**
This board is created by:

* Filling diagonal boxes (fillDiagonal)
* Recursively filling remaining spaces (fillRemaining)
* Removing K cells based on difficulty (removeKDigits)


**3. Built-in Sudoku Solver**
Uses backtracking algorithm:
  bool SolveSudoku(int arr[9][9]);


**4. Submission Checker**
This app checks each user input:
* Correct → highlights green

* Incorrect → highlights red

Lives decrease until 0


**5. Win/Lose Screens**
Lose screen (Lost) when lives reach 0
Win screen (Won) when board is solved and at least 1 life remaining

