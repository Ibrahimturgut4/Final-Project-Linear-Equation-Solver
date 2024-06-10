/*
İbrahim Turğut             20211706033
Arda Kerem Şenpınar        20211706027 
Ömer Kürşat Canbaz         20211706009
*/
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int getFromTerminal(int* size, double*** matrix);
int readFromFile(const char* fileName, int* size, double*** matrix);
void gauss(int size, double** matrix);
void freeMat(int size, double** matrix);

int main() {
    int size;                //Quantity of equations
    double** matrix = NULL;  // A pointer to the matrix
    int choice;              // The input technique selected by the user


    // Prompt the user to select the input method.
    printf("Choose 1 for terminal, 2 for file:\n");
    if (scanf("%d", &choice) != 1) {  // Input error verification
        fprintf(stderr, "Error reading choice.\n");
        return EXIT_FAILURE;
    }
    // Retrieve the data from the terminal or file in accordance with the user's preference.

    if (choice == 1) {
        if (getFromTerminal(&size, &matrix) != 0) {  // Retrieve data from the terminal.

            fprintf(stderr, "Error getting data from terminal.\n");
            return EXIT_FAILURE;
        }
    }
    else if (choice == 2) {
        char fileName[100];  // File name buffer
        printf("Enter file name (with the extension .txt):\n");
        if (scanf("%99s", fileName) != 1) {  // Read the file name
            fprintf(stderr, "Error reading file name.\n");
            return EXIT_FAILURE;
        }

        if (readFromFile(fileName, &size, &matrix) != 0) {  // Get data from file
            fprintf(stderr, "Error reading from file.\n");
            return EXIT_FAILURE;
        }
    }
    else {
        fprintf(stderr, "Invalid choice! Please choose 1 or 2.\n");
        return EXIT_FAILURE;
    }

    // Perform Gaussian elimination
    printf("Matrix read successfully. Starting Gauss elimination...\n");
    gauss(size, matrix);

    // Free allocated memory
    freeMat(size, matrix);

    return EXIT_SUCCESS;
}

// Function for retrieving the matrix from the terminal
int getFromTerminal(int* size, double*** matrix) {
    // Prompt the user to specify the number of equations.
    printf("Enter how many equations:\n");
    if (scanf("%d", size) != 1) return -1;

    // Reserve memory for the matrix
    *matrix = (double**)malloc(*size * sizeof(double*));
    if (*matrix == NULL) return -1;

    for (int i = 0; i < *size; i++) {
        (*matrix)[i] = (double*)malloc((*size + 1) * sizeof(double));
        if ((*matrix)[i] == NULL) {
            for (int k = 0; k < i; k++) free((*matrix)[k]);
            free(*matrix);
            return -1;
        }
    }

    // Instruct the user to input the coefficients and constants.

    printf("Enter the coefficients followed by the constant for each equation:\n");
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j <= *size; j++) {
            if (scanf("%lf", &((*matrix)[i][j])) != 1) return -1;
        }
    }

    return 0;
}

// Matrix retrieval function from a file

int readFromFile(const char* fileName, int* size, double*** matrix) {
    FILE* file = fopen(fileName, "r");  // Open the file
    if (!file) {
        fprintf(stderr, "File not found: %s\n", fileName);
        return -1;
    }

    // Retrieve the quantity of equations from the file

    if (fscanf(file, "%d", size) != 1) {
        fprintf(stderr, "Error reading size from file: %s\n", fileName);
        fclose(file);
        return -1;
    }

    // Reserve memory for the matrix
    *matrix = (double**)malloc(*size * sizeof(double*));
    if (*matrix == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);
        return -1;
    }

    for (int i = 0; i < *size; i++) {
        (*matrix)[i] = (double*)malloc((*size + 1) * sizeof(double));
        if ((*matrix)[i] == NULL) {
            for (int k = 0; k < i; k++) free((*matrix)[k]);
            free(*matrix);
            fprintf(stderr, "Memory allocation error.\n");
            fclose(file);
            return -1;
        }

        // Extract the coefficients and constants from the file
        for (int j = 0; j <= *size; j++) {
            if (fscanf(file, "%lf", &((*matrix)[i][j])) != 1) {
                fprintf(stderr, "Error reading matrix data from file: %s\n", fileName);
                fclose(file);
                return -1;
            }
        }
    }

    fclose(file);  // Close the file
    return 0;
}

// Gaussian elimination function
void gauss(int size, double** matrix) {
    // Forward elimination
    for (int i = 0; i < size; ++i) {
        // Check for zero pivot element
        if (matrix[i][i] == 0) {
            fprintf(stderr, "No unique solution exists as a pivot is zero.\n");
            return;
        }

        // Remove the lowest rows
        for (int j = i + 1; j < size; ++j) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= size; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Back substitution and solution printing

    double* solutions = (double*)malloc(size * sizeof(double));
    for (int i = size - 1; i >= 0; i--) {
        solutions[i] = matrix[i][size];
        for (int j = i + 1; j < size; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
        solutions[i] /= matrix[i][i];
    }

    // Output the solutions
    printf("Solutions:\n");
    for (int i = 0; i < size; i++) {
        printf("x%d = %lf\n", i + 1, solutions[i]);
    }

    free(solutions);  // Free the solutions array
}

// Function to deallocate the allocated memory for the matrix
void freeMat(int size, double** matrix) {
    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
