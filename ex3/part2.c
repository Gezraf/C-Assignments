/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <math.h>
#define N 4
#define SIZE 5


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


int sumDiagonal(int mat[SIZE][SIZE], int i, int j) {
    int sum = 0;
    
    while(i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        sum += mat[i][j];
        i++;
        j--;
    }

    return sum;
}


void MaxSumDiagonal(int mat[SIZE][SIZE]) {
    int max = -1;
    for(int i = 0; i<SIZE; i++) {
        for(int j = 0; j<SIZE; j++) {            
            int sum = sumDiagonal(mat, i, j);
            if(sum > max) {
                max = sum;
            }
        }
    }
    
    printf("The max sum is %d", max);
}



void RotateMatrix90(int mat[SIZE][SIZE]) {
    int temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            temp[i][j] = mat[SIZE - i - 1][j];
        }
    }


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            mat[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int mat[SIZE][SIZE] = {
        {5,3,4,6,1},
        {7,2,8,9,0},
        {9,5,1,4,1},
        {6,7,3,2,3},
        {2,6,1,0,6}
    };
    
    
    MaxSumDiagonal(mat);
    return 0;
}
