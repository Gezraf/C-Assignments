/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <math.h>

// 1

#define LEFT 1
#define RIGHT 2

int strlen(char str[]) { // פונקציית עזר שמחזירה את האורך האמיתי של מחרוזת
    int i = 0;

    while (str[i] != '\0')  // בשאלה אמרו שבוודאות יתקבל כפרמטר מחרוזת
        i++;

    return i;
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

    temp[SIZE] = '\0'; // נשים בתו האחרון את עוצר המחרוזת
    for (int i = 0; i < SIZE; i++) {
        str[i] = temp[i]; // העתקת מחרוזת העזר למחרוזת המקורית
    }
}


// 2

#define ROWS 6
#define COLS 8

int checkRight(char mat[ROWS][COLS], int row, int col, char word[], int wordLength) {
    if (col + wordLength > COLS) // ייצא מוקדם אם סכום מספר העמודה באורך המילה גדול ממספר העמודות
        return 0;

    for (int i = 0; i < wordLength; i++) { // בדיקת שווי אופקית משמאל לימין
        if (mat[row][col+i] != word[i])
            return 0;
    }

    return 1;
}


int checkDown(char mat[ROWS][COLS], int row, int col, char word[], int wordLength) {
    if (row + wordLength > ROWS) // ייצא מוקדם אם סכום מספר השורה באורך המילה גדול ממספר השורות
        return 0;

    for (int i = 0; i < wordLength; i++) {
        if (mat[row+i][col] != word[i]) // בדיקת שווי אנכית מלמעלה למטה
            return 0;
    }

    return 1;
}


int checkDiag(char mat[ROWS][COLS], int row, int col, char word[], int wordLength) {
    if (row + wordLength > ROWS || col + wordLength > COLS) // ייצא מוקדם אם סכום מספר השורה/העמודה באורך המילה גדול ממספר העמודות/שורות בהתאם
        return 0;

    for (int i = 0; i < wordLength; i++) {
        if (mat[row+i][col+i] != word[i]) // בדיקת שווי אלכסונית
            return 0;
    }

    return 1;
}

int CountWords(char mat[ROWS][COLS], char word[]) {
    int count = 0;
    const int length = strlen(word);

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            count += checkRight(mat, r, c, word, length) + checkDown(mat, r, c, word, length) + checkDiag(mat, r, c, word, length);
        }
    }

    return count;
}

#define SIZE 81 // 81 תווים בגלל שאם מדובר במחרוזות אז חייב את עוצר המחרוזת בתו האחרון של כל מערך כדי שיהיו לכל היותר 80 תווים מהקלט

int main() {
    char string[SIZE], word[SIZE];

    printf("Enter your string: ");
    fgets(string, SIZE, stdin);
    string[strlen(string) - 1] = '\0'; // הפונקציה fgets שמה n\ בסוף המחרוזת אוטומטית, משהו שאנחנו לא רוצים, לכן נחליף אותו בעוצר המחרוזת

    printf("Enter your word: ");
    fgets(word, SIZE, stdin);
    word[strlen(word) - 1] = '\0'; // אותו דבר כמו למעלה


    char mat[ROWS][COLS];

    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLS; j++) {
            printf("Enter your character for the matrix: ");
            scanf(" %c", &mat[i][j]);
        }
    }

    int moves, dir;
    printf("Enter the amount of rotation moves: ");
    scanf("%d", &moves);

    printf("Enter the direction of rotation (1 -> LEFT | 2 -> RIGHT): ");
    scanf("%d", &dir);

    // RotateString

    // (string before)
    printf("Before: %s", string);

    // (string after)
    RotateString(string, moves, dir);
    printf("\nAfter: %s", string);


    // CountWords
    printf("\n%d", CountWords(mat, word));

    return 0;
}
