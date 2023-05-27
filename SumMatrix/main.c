#include <stdio.h>
#include <stdlib.h>

int check(int row1, int row2, int column1, int column2) {
    if ((row1 == row2) && (column1 == column2)) {
        return 1;
    }
    else {
        return 0;
    }
}

int** sum_matrices(int row1, int row2, int column1, int column2) {
    int** matrix1 = malloc(row1 * sizeof(int*));
    int** matrix2 = malloc(row2 * sizeof(int*));
    int** last = malloc(row1 * sizeof(int*));

    for (int i = 0; i < row1; i++) {
        matrix1[i] = malloc(column1 * sizeof(int));
        last[i] = malloc(column1 * sizeof(int));
    }

    for (int i = 0; i < row2; i++) {
        matrix2[i] = malloc(column2 * sizeof(int));
    }

    int result = check(row1, row2, column1, column2);
    if (result == 1) {
        int number;
        printf("Enter the information of the first matrix:\n");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                printf("Row %d, Column %d: ", (i + 1), (j + 1));
                scanf("%d", &number);
                matrix1[i][j] = number;
            }
        }

        printf("The entering process of the first matrix is done.\n");
        printf("Enter the information of the next matrix:\n");
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < column2; j++) {
                printf("Row %d, Column %d: ", (i + 1), (j + 1));
                scanf("%d", &number);
                matrix2[i][j] = number;
            }
        }

        printf("The entering process of the second matrix is done.\n");
        printf("Summing two matrices...\n");

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < column2; j++) {
                last[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printf("Summing is done.\n\n");
        printf("The data of the first matrix:\n\n");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                printf("\t%d", matrix1[i][j]);
            }
            printf("\n");
        }

        printf("\nThe data of the second matrix:\n\n");
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < column2; j++) {
                printf("\t%d", matrix2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else {
        printf("One or more entered values are not eligible for matrix sum.");
        exit(0);
    }

    return last;
}

int main() {
    int row1, row2, column1, column2;
    printf("Enter rows and columns of the first matrix:\n");
    scanf("%d%d", &row1, &column1);
    printf("Enter rows and columns of the second matrix:\n");
    scanf("%d%d", &row2, &column2);

    int** ptr = sum_matrices(row1, row2, column1, column2);

    printf("Last matrix's data:\n\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < column2; j++) {
            printf("\t%d", ptr[i][j]);
        }
        printf("\n");
    }

    printf("Process is completed.");

    // Free dynamically allocated memory
    for (int i = 0; i < row1; i++) {
        free(ptr[i]);
    }
    free(ptr);

    return 0;
}
