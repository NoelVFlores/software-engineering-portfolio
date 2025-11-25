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


---------------------------------------------------------------------

**Screenshots**


**Difficulty Screen**
Shows the Easy/Medium/Hard Selection UI.
<img width="1030" height="428" alt="image" src="https://github.com/user-attachments/assets/14467de9-12ac-4bfb-a2b5-0353d582f3fa" />






**Game Board**
Ramdonmized Sudoku Board with timer and life counter (This example shows Easy Diffuculty).
<img width="1004" height="882" alt="image" src="https://github.com/user-attachments/assets/4a57e7be-3243-4665-8877-e6e5c3e8c5eb" />






**Solver Button**
Highlights solved cells in green.
<img width="980" height="856" alt="image" src="https://github.com/user-attachments/assets/0d1ec483-3075-418c-9dfe-2f1f47ab9247" />






**Submission Checking**
Correct = green, Incorrect = red.
<img width="976" height="858" alt="image" src="https://github.com/user-attachments/assets/347fd50d-1048-4408-90d2-da1e499603d8" />






**Losing Screen**
"You Lost" message with retry options.
<img width="882" height="662" alt="image" src="https://github.com/user-attachments/assets/8e625530-41d2-42b0-8cb8-cd86b6108eb8" />






**Winning Screen**
"You Win" with Play Again button.
<img width="940" height="710" alt="image" src="https://github.com/user-attachments/assets/3bb4ebd9-aa6c-474b-811c-506243376869" />



