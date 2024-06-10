# Final-Project-Linear-Equation-Solver

# Description
This program use Gaussian elimination to solve systems of linear equations. The Gaussian elimination approach is utilized to process input from both the terminal and a text file, providing flexibility in the way equations are supplied.

# Features

User input received via the terminal: Input the number of equations and their coefficients directly.
Text input received via a file: Import equations from a .txt file.
Gaussian Elimination: Employs Gaussian elimination to solve a system of equations.
Back Substitution: Computes the solution of the equations after transforming them into echelon form.

# Methods Used
The function getFromTerminal retrieves the dimensions of the matrix and its elements (coefficients of the equations) directly from the terminal.

readFromFile: Retrieves the dimensions of the matrix and its constituent members from a designated text file.

The "gauss" function conducts Gaussian elimination on a matrix to solve it. It transforms the matrix to row-echelon form and then does back substitution to determine the values of the variables.

freeMat: Deallocates the dynamically allocated memory utilized for the matrix.
