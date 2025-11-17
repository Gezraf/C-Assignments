/* Assignment: 3
Author: Guy Shitrit, ID: 330707761
*/

#include <stdio.h>

int ex3() {
    int mashkanta;
    int income;

    printf("Enter your mashkanta: ");
    scanf("%d", &mashkanta);
    
   if(mashkanta < 100000) {
        printf("Can't get mashkanta - mashkanta is lower than 100,000");
        return 0;
   } 
   
    printf("Enter your monthly income: ");
    scanf("%d",&income);

    int returned;
    int years;

    int hundred_thousands = mashkanta / 100000;

    if (income % 750 >= 0) { // תקופה מינימאלית
        returned = hundred_thousands * 750;
        years = 15;
    } else if (income % 600 >= 0) {
        returned = hundred_thousands * 600;
        years = 20;
    } else if (income % 500 >= 0) {
        returned = hundred_thousands * 500;
        years = 25;
    }

    if (returned < income * 0.31) {
        printf("Can get mashkanta! You have to pay for %d years, and get a %d ILS return", years, returned);
    } else {
        printf("Can't get mashkanta - return bigger than 31%% of the monthly family income.");
    }

    return 0;
}
