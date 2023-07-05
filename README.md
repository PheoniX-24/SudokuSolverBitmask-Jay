# SudokuSolverBitmask-Jay

**Sudoku Solver**
This program solves a 9x9 Sudoku puzzle using a backtracking algorithm. It takes an incomplete Sudoku puzzle as input and finds a valid solution, if one exists. If multiple valid solutions exist, it will find all of them.

**Input Format**
The input is provided in the form of a 9x9 grid representing the Sudoku puzzle. Each cell in the grid is either filled with a number from 1 to 9 or left empty (represented by 0). The input grid should be provided in a text file.

Example Input:

8 5 0 0 0 2 4 0 0
7 2 0 0 0 0 0 0 9
0 0 4 0 0 0 0 0 0
0 0 0 1 0 7 0 0 2
3 0 5 0 0 0 9 0 0
0 4 0 0 0 0 0 0 0
0 0 0 0 8 0 0 7 0
0 1 7 0 0 0 0 0 0
0 0 0 0 3 6 0 4 0

**Output Format**
The program will output the solution(s) to the Sudoku puzzle, if any are found. Each solution will be displayed as a 9x9 grid, where the empty cells will be filled with the correct numbers. If multiple solutions exist, all of them will be displayed.

Example Output:

8 5 9 6 1 2 4 3 7
7 2 3 8 5 4 1 6 9
1 6 4 3 7 9 5 2 8
9 8 6 1 4 7 3 5 2
3 7 5 2 6 8 9 1 4
2 4 1 5 9 3 7 8 6
4 3 2 9 8 1 6 7 5
6 1 7 4 2 5 8 9 3
5 9 8 7 3 6 2 4 1

**Key Features**
**Backtracking Algorithm:** The code utilizes a backtracking algorithm to solve the Sudoku puzzle. Backtracking is a systematic approach to finding solutions by trying out different options and undoing choices when they lead to dead ends. In the context of the Sudoku puzzle, the algorithm recursively fills empty cells with valid numbers and backtracks when a conflict is encountered, exploring different possibilities until a solution is found or all possibilities are exhausted.

**Bitmasking:** Bitmasking is used to efficiently keep track of numbers that have already been used in a particular row, column, or 3x3 grid. Instead of using separate variables or data structures to store this information, bitmasking allows compact representation of the used numbers using bitwise operations. The takenRow, takenCol, and takenGrid arrays use bitmasking to keep track of which numbers have been used in each row, column, and grid.

**Recursive Approach:** The code employs a recursive approach to explore different combinations and possibilities. It uses a recursive function (rec()) that is called for each empty cell in the Sudoku grid. The function checks available choices for the cell, makes a move, and then calls itself recursively for the next cell. This recursive process continues until a complete solution is found or all possibilities are exhausted.

Feel free to modify the code or experiment with different Sudoku puzzles to test its capabilities. Enjoy solving Sudoku puzzles with this program!
