//WAP to convert days into years,weeks and years.

#include <stdio.h>
void main() {
    int totalDays, years, weeks, days;

    printf("Enter number of days: ");
    scanf("%d", &totalDays);

    years = totalDays / 365;
    totalDays = totalDays % 365;

    weeks = totalDays / 7;
    days = totalDays % 7;

    printf("Years = %d\n", years);
    printf("Weeks = %d\n", weeks);
    printf("Days = %d\n", days);

}