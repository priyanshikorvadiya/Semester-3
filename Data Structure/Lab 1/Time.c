#include<stdio.h>
void main(){

    int sec,min = 0,hour = 0;

    printf("Enter seconds :");
    scanf("%d",sec);

    hour = sec / 3600;
    min  = (sec % 3600) / 60;
    sec  = sec % 60;

    printf("%d :: %d :: %d",hour,min,sec);
}