/* Assignment: 2
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>

int ex2() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == 0) { // אם המספר שווה אפס
        return 0;
    } else if (num >= 1 && num <= 9) { // אם המספר חד-ספרתי
        printf("%d", num);
        return 0;
    } else if (num >= 10 && num <= 99) { // אם המספר דו-ספרתי
        // אם המספר דו-ספרתי
        printf("%d", num / 10 + num % 10); // הדפסת סכום ספרותיו של המספר הדו-ספרתי
        return 0;
    } else if (num >= 100 && num <= 999) { // אם המספר תלת-ספרתי
        int flag = 1;
        int hundreds = num / 100;
        int tens = num % 100 / 10;
        int ones = num % 10;


        if (!(hundreds <= tens && tens <= ones)) { // אם ספרת האחדות לא קטנה מספרת העשרות וספרת העשרות לא קטנה מספרת המאות, נשים את הפלאג שלנו בערך 0 כדי לציין בוליאני שקרי
            flag = 0;
        }

        if (flag) {
            printf("The number is sorted in ascending order.");
        } else {
            printf("The number is NOT sorted in ascending order.");
        }

        return 0;

    } else if (num >= 1000 && num <= 9999) { // אם המספר בעל 4 ספרות
        int thousands = num / 1000;
        int hundreds = (num % 1000) / 100;
        int tens = ((num % 1000) % 100) / 10;
        int ones = num % 10;

        int sum1 = ones + tens;
        int sum2 = hundreds + thousands;

        printf("The desired sum is %d", sum1 + sum2);
        return 0;

    } else {
        printf("Invalid input");
        return 0;
    }
}