/* Assignment: 5
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>

int ex5() {
    int h1, d1;
    int h2, d2;

    printf("Enter h1 and d1: ");
    scanf("%d%d", &h1, &d1);

    printf("Enter h2 and d2: ");
    scanf("%d%d", &h2, &d2);

    if (h1 < h2) { // אם השעה הראשונה קטנה מהשעה השנייה
        if (d1 <= d2) {
            printf("difH=%d, difD=%d", (h2-h1), (d2-d1));
        } else {
            printf("difH=%d, difD=%d", (h2 - h1) - 1, 60 - d1 + d2);
        }
    } else if (h1 == h2) { // אם השעה הראשונה שווה לשעה השנייה
        if (d1 <= d2) {
            printf("difH=%d, difD=%d", 0, (d2-d1));
        } else {
            printf("difH=%d, difD=%d", 23, 60 - d1 + d2); // כאן זה 23 קבוע משום ששני השעות שוות אך המספר השני של הדקות קטן מהמספר הראשון
        }
    } else { // h1 > h2 אם השעה הראשונה גדולה מהשעה השנייה
        if (d1 <= d2) {
            printf("difH=%d, difD=%d", 24 - (h1 - h2), (d2-d1));
        } else {
            printf("difH=%d, difD=%d", 24 - (h1 - h2) - 1, 60 - d1 + d2);
        }
    }

    return 0;
}