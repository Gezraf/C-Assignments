/* Assignment: 4
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>

int ex4() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int flag1 = n >= 10 && n <= 99; // האם המספר דו-ספרתי
    int flag2 = n / 10 != n % 10; // האם ספרת העשרות שונה מספרת האחדות

    if (!(flag1 & flag2)) { // אם שני התנאים לא מתקיימים, נדפיס הודעת שגיאה
        printf("Invalid input");
        return 0;
    }

    int ones = num % 10;
    int tens = num / 10;

    int res = ones * 10 + tens;
    printf("The opposite number is %d", res);

    return 0;
}