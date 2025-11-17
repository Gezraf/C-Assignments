/* Assignment: 2
    Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; // על פי טבלת ASCII, הפרש הערך בין אותיות קטנות לגדולות הוא 32
    }

    return c;
}

void option1() { // אפשרות 1
    char c1 = '/';
    char c2 = '/';

    while (!((c1 >= 'A' && c1 <= 'z') || (c2 >= 'A' && c2 <= 'z'))) {
        printf("Enter 2 characters: ");
        scanf("%c", &c1);
        scanf("%c", &c2);
        if (!((c1 >= 'A' && c1 <= 'z') || (c2 >= 'A' && c2 <= 'z'))) {
            printf("Invalid input - Please enter alphabetical characters.");
        }
    }

    c1 = toLower(c1);
    c2 = toLower(c2);

}

void option2() { // אפשרות 2
    {}
}

void option3() { // אפשרות 3
    int number = -1;
    int n;

    // Ensure the number is between 1 and 60
    while (!(number >= 1 && number <= 60)) {
        printf("Enter a number between 1 and 60: ");
        scanf("%d", &number);
    }

    n = number;

    for (int rows = 0; rows < number; rows++) {
        for (int i = 0; i < number - rows - 1; i++) {
            printf("X");
        }

        printf(" ");

        for (int j = 0; j < rows; j++) {
            printf("0");
        }

        printf("\n");
    }
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


void option4() { // אפשרות 4
    int n1, n2;
    printf("Enter two limits: ");
    scanf("%d %d", &n1, &n2);

    int rangeMin = min(n1, n2);
    int rangeMax = max(n1, n2);

    for (int i = rangeMin; i <= rangeMax; i++) {
        if (isPalindrome(i) && isPrime(i)) {
            printf("%d \t", i);
        }
    }
}


int main(void) {
    int option;

    // אני שומר על הדפסת התפריט מסודר ע"י הדפסות בשורות נפרדות ולא ע"י שבירת שורה
    printf("Please choose an option:\n");
    printf("1- Magic letters\n");
    printf("2- The guessing game\n");
    printf("3 - Pattern print\n");
    printf("4 - Prime Palindrome scavenger hunt\n");
    printf("5 - Exit\n");

    scanf("%d", &option);


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


    return 0;
}
