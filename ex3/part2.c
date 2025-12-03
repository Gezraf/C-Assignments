/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <math.h>
#define N 4
#define SIZE 5


//1

void FindValleys(int mat[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val = mat[i][j];

            if (val < mat[i-1][j] &&   // למעלה
                val < mat[i+1][j] &&   // למטה
                val < mat[i][j-1] &&   // שמאלה
                val < mat[i][j+1]) {   // ימינה
                count++;
                printf("Valley at (%d,%d) = %d\n", i, j, val);
                }
        }
    }

    if (count == 0)
        printf("No result found");
}


// 2

int sumDiagonal(int mat[SIZE][SIZE], int i, int j) { // פונקציית עזר שמחשבת סכום מספרים באלכסון מימין לשמאל החל מתא מסוים
    int sum = 0;

    while(i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        sum += mat[i][j];
        i++;
        j--;
    }

    return sum;
}


void MaxSumDiagonal(int mat[SIZE][SIZE]) {
    int max = mat[0][0];
    int rowIndex = 0, colIndex = 0;

    for(int i = 0; i<SIZE; i++) {
        for(int j = 0; j<SIZE; j++) {
            int sum = sumDiagonal(mat, i, j);
            if(sum > max) {
                max = sum;
                rowIndex = i;
                colIndex = j;
            }
        }
    }

    while(rowIndex >= 0 && rowIndex < SIZE && colIndex >= 0 && colIndex < SIZE) {
        printf("%d ",  mat[rowIndex][colIndex]);
        rowIndex++;
        colIndex--;
    }
}


// 3

void printMatrix(int mat[SIZE][SIZE], int size) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

void RotateMatrix90(int mat[SIZE][SIZE]) {
    int temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            temp[i][j] = mat[SIZE - j - 1][i]; // נאלצתי לצייר כדי להחליט מה החוקיות כדי לדעת איך לבצע טרנספוזה כזאת
        }
    }


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            mat[i][j] = temp[i][j]; // להעתיק את מטריצת העזר לתוך המטריצה המקורית
        }
    }
}

int main() {
    int One[SIZE][SIZE];

    for(int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            printf("Enter a number to the matrix: ");
            scanf("%d", &One[i][j]);
        }
    }

    printf("MaxSumDiagonal:\n");
    MaxSumDiagonal(One);

    printf("\n\nRotateMatrix90:\n");
    printMatrix(One, SIZE); //  הדפסה לפני השינוי
    RotateMatrix90(One);
    printf("\n");
    printMatrix(One, SIZE); // הדפסה לאחר השינוי

    return 0;
}
