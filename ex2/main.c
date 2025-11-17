/* Assignment: 2
    Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void); // הכרזה על פונקציית התפריט שתוגדר בהמשך, מה שיאפשר קישור בין פונקציות

// פונקציות עזר
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; // על פי טבלת ASCII, הפרש הערך בין אותיות קטנות לגדולות הוא 32
    }

    return c;
}


int isPalindrome(int n) {
    int copy = n;
    int reversedNum = 0;
    int remainder;

    while (copy != 0) { // לולאה שמחשבת מספר הפוך למספר המקורי
        remainder = copy % 10;
        reversedNum = reversedNum * 10 + remainder;
        copy /= 10;
    }

    if (reversedNum == n) { // בדיקה האם המספר פלינדרום - האם המספר המקורי שווה למספר ההפוך
        return 1;
    }

    return 0;

}

int isPrime(int n) {
    if (n <= 1) return 0;

    for (int i = 2; i <= n / 2; i++) { // אפשר לבדוק עד חצי מהבדיקות לבדיקת מספר ראשוני
        if (n % i == 0) return 0;
    }

    return 1;
}

int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

int min(int a, int b) {
    if (a <= b) return a;
    return b;
}

//

void option1() { // אפשרות 1
    char c1 = '/';
    char c2 = '/';

    while (!((c1 >= 'A' && c1 <= 'Z') || (c1 >= 'a' && c1 <= 'z')) ||
       !((c2 >= 'A' && c2 <= 'Z') || (c2 >= 'a' && c2 <= 'z')))
    {
        printf("Enter 2 characters: ");
        scanf(" %c %c", &c1, &c2);
        if (!((c1 >= 'A' && c1 <= 'z') || (c2 >= 'A' && c2 <= 'z'))) {
            printf("Invalid input - Please enter characters in the range [a-z].");
        }
    }

    c1 = toLower(c1);
    c2 = toLower(c2);

    if (c2 < c1) { // שמירה על סדר אלפביתי
        char temp = c1;
        c1 = c2;
        c2 = temp;
    }

    for (char row = c1; row <= c2; row++) { // השם לערך row החל מc1 עד c2 כולל
        for (char col = row; col <= c2; col++) { // השם לערך col החל מrow עד c2 כולל
            printf("%c %c  ", row, col);
        }
        printf("\n");
    }

    menu();
}

void option2() { // אפשרות 2
    int n1, n2, guess;
    int guesses = 11; // ערך זבל שיאפשר לנו להיכנס ללולאה כדי להכניס את הערך האמיתי מהמשתמש בהמשך
    int playing = 1; // המשחק יחזור כל עוד השחקן רוצה לשחק שוב, זהו דגל שמכריע על כך

    srand((unsigned int) time(NULL)); // שורה שצריך לכתוב על מנת שההגרלה בהמשך תעבוד

    while (playing && guesses >= 0) {
        int hasWon = 0; // האם השחקן ניצח?
        printf("Enter a number: ");
        scanf(" %d", &n1);

        printf("Enter a number: ");
        scanf("%d", &n2);

        printf("Enter the number of guesses you would like to make [2-10] :");
        scanf("%d", &guesses);

        while (!(guesses >= 2 && guesses <= 10)) {
            if (!(guesses >= 2 && guesses <= 10)) {
                printf("Invalid input - Please enter a number of guesses in the range [2-10].\n");
            }

            printf("Enter the number of guesses you would like to make [2-10]:");
            scanf("%d", &guesses);

        }

        const int RANGE_MIN = min(n1, n2);
        const int RANGE_MAX = max(n1, n2);
        const int chosenNumber = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;

        for (int i = 0, limit = guesses; i < limit; i++) {
            if (guesses == 0)
                break;

            printf("Enter your guess (you have %d guesses left): ", guesses);
            scanf("%d", &guess);


            if (!(guess >= RANGE_MIN && guess <= RANGE_MAX)) {
                printf("Invalid guess - not in the required range [%d-%d]\n", RANGE_MIN, RANGE_MAX);
                guesses--;
            } else if (guess < chosenNumber) {
                printf("The number is HIGHER.\n");
                guesses--;
            } else if (guess > chosenNumber) {
                printf("The number is LOWER.\n");
                guesses--;
            } else if (guess == chosenNumber) {
                hasWon = 1;
                break;
            }
        }

        if (hasWon || guesses == 0) {
            if (hasWon) { // אם ניצח
                printf("Congratulations - you have won !\n");
            } else { // אם לא ניצח
                printf("Game is over , unsuccessful attempts !\n");
            }

            printf("Enter 'y' if you'd like to play for another round: ");

            char choice;
            scanf(" %c", &choice);

            if (toLower(choice) != 'y')
                playing = 0;
        }
    }

    menu();
}

void option3() { // אפשרות 3
    int number = -1;
    int n;

    while (!(number >= 1 && number <= 60)) {
        printf("Enter a number between 1 and 60: ");
        scanf("%d", &number);
    }

    n = number;

    for (int rows = 0; rows <= number; rows++) {
        for (int i = 0; i < number - rows; i++) {
            printf("X");
        }

        printf("  ");

        for (int j = 0; j < rows; j++) {
            printf("0");
        }

        printf("\n");
    }

    menu();
}

void option4() { // אפשרות 4
    int n1, n2;
    printf("Enter two limits: ");
    scanf("%d %d", &n1, &n2);

    const int RANGE_MIN = min(n1, n2);
    const int RANGE_MAX = max(n1, n2);

    for (int i = RANGE_MIN; i <= RANGE_MAX; i++) {
        if (isPalindrome(i) && isPrime(i)) {
            printf("%d \t", i);
        }
    }

    menu();
}

void menu() {
    printf("\n"); // שורה חדשה נקייה כדי להפריד בין תרגילים שונים אפשריים

    int option;

    // אני שומר על הדפסת התפריט מסודר ע"י הדפסות בשורות נפרדות ולא ע"י שבירת שורה
    printf("Please choose an option:\n");
    printf("1- Magic letters\n");
    printf("2- The guessing game\n");
    printf("3 - Pattern print\n");
    printf("4 - Prime Palindrome scavenger hunt\n");
    printf("5 - Exit\n");

    scanf("%d", &option);

    while (!(option >= 1 && option <= 5)) {
        // אם האופציה לא תקינה
        printf("Invalid option! Please enter a valid option in the range [1-5].\n");
        scanf("%d", &option);
    }

    switch (option) {
        case 1: // Magic letters
            option1();
            break;
        case 2: // The guessing game
            option2();
            break;
        case 3: // Pattern print
            option3();
            break;
        case 4: // Prime Palindrome
            option4();
            break;
        case 5: // Exit
            printf("Have a great day & see you soon!");
            break;
        default:
            break;
    }
}

int main() {
    menu();
    return 0;
}
