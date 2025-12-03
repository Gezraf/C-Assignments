/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <math.h>
#define N 4


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

int main() {
    int mat[N][N] = {
        {5,3,4,6},
        {7,2,8,9},
        {9,5,1,4},
        {6,7,3,2}
    };

    FindValleys(mat);
    return 0;
}
