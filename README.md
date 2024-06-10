# Final-Project-Linear-Equation-Solver

İbrahim Turğut       20211706033 \
Arda Kerem Şenpınar  20211706027 \
Ömer Kürşat Canbaz   20211706009

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

# Compilation of the Program

In this part, instructions about the compiling and running program will be mentioned.

Firstly, let's start with how user can compile the program;
To compile the program, there are some required tools such as Microsoft Visual Studio, Visual Studio Code or online compilers etc. Online compilers are best way to use this program if you don't have the installed program.

# Running of the Program

After that, Please write the code that calculate the linear equations using Gaussian elimination. When you entered the code please run that. When you run the code, there will be two options. One of them is pressing 1 to input from terminal. The other option is pressing 2 to read equations from txt file. 

When user press 1, program will ask the number of equations and coefficients of the equations, separately. After that, it solves the equations.

When user press 2, program will ask them to write the file that includes the number of equations and their coefficients from a formatted text file. Next, program will solve the equation that is in the file.

When the program done the solution, it will show the results on the screen.
