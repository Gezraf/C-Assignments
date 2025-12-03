/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <math.h>

// 1

#define LEFT 1
#define RIGHT 2

int strlen(char str[]) { // פונקציית עזר שמחזירה את האורך האמיתי של מחרוזת
    int i = 0, length = 0;

    while (str[i] != '\0') { // בשאלה אמרו שבוודאות יתקבל כפרמטר מחרוזת
        length++;
        i++;
    }

    return length;
}

void RotateString(char str[], int moves, int dir) {
    const int SIZE = strlen(str);
    moves %= SIZE; // אם מספר ההזזות גדול מגודל המחרוזת, נוכל לצמצם אותו כך שתתקבל אותה מחרוזת מעודכנת בסוף

    char temp[SIZE + 1];

    switch (dir) {
        case LEFT: // שמאלה
            for (int i = 0; i < SIZE; i++) {
                temp[i] = str[(i + moves) % SIZE]; // השמה מחזורית ברגע שהאינדקס חורג מגבולות המחרוזת
            }
            break;

        case RIGHT: // ימינה
            for (int i = 0; i < SIZE; i++) {
                temp[i] = str[(i - moves + SIZE) % SIZE]; // השמה מחזורית ברגע שהאינדקס חורג מגבולות המחרוזת, וברגע שהאינדקס שלילי יתווסף אל האינדקס גודל המחרוזת כדי שיהיה חיובי
            }
            break;

        default:
            printf("Invalid direction value!");
            return; // ייצא אם ערך הכיוון לא תקין
    }

    temp[SIZE] = '\0'; // נשים בתו האחרון את סוגר המחרוזת
    for (int i = 0; i < SIZE; i++) {
        str[i] = temp[i]; // העתקת מחרוזת העזר למחרוזת המקורית
    }
}


// 2

#define ROWS 6
#define COLS 8

int checkRight(char mat[ROWS][COLS], int row, int col, char word[]) {
    int length = strlen(word);

    if (col + length > COLS)
        return 0;

    for (int i = 0; i < length; i++) {
        if (mat[row][col+i] != word[i])
            return 0;
    }

    return 1;
}


int checkDown(char mat[ROWS][COLS], int row, int col, char word[]) {
    int length = strlen(word);

    if (row + length > ROWS)
        return 0;

    for (int i = 0; i < length; i++) {
        if (mat[row+i][col] != word[i])
            return 0;
    }

    return 1;
}


int checkDiag(char mat[ROWS][COLS], int row, int col, char word[]) {
    int length = strlen(word);

    if (row + length > ROWS || col + length > COLS)
        return 0;

    for (int i = 0; i < length; i++) {
        if (mat[row+i][col+i] != word[i])
            return 0;
    }

    return 1;
}

int CountWords(char mat[ROWS][COLS], char word[]) {
    int count = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            count += checkRight(mat, r, c, word) + checkDown(mat, r, c, word) + checkDiag(mat, r, c, word);
        }
    }

    return count;
}

int main() {
    char mat[6][8] = {
        { 'a', 'w', 'o', 'r', 'd', 'b', 'c', 'w' },
        { 'd', 'o', 'o', 'e', 'f', 'h', 'i', 'o' },
        { 'j', 'r', 'k', 'r', 'w', 'l', 'w', 'r' },
        { 'm', 'd', 'n', 'o', 'd', 'o', 'o', 'd' },
        { 'p', 'q', 'r', 's', 'w', 'o', 'r', 'd' },
        { 't', 'u', 'v', 'w', 'x', 'y', 'd', 'd' }
    };
    
    printf("%d", CountWords(mat, "word"));

    return 0;
}
