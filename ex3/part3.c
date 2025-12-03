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

int CountWords(char mat[6][8], char word[][]) {

}

int main() {
    char str[9] = "refdeeae";

    printf("Before: %s\n", str);
    RotateString(str, 10, 1);
    printf("After: %s", str);

    return 0;
}
