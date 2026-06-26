//WAP to find whether the given year is leap year or not.

#include<stdio.h>
void main (){
    int year;

    printf("Enter year :");
    scanf("%d",year);

    if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0){
        printf("Given year is leap year");
    }
    else{
        printf("Given year is not leap year");
    }
}