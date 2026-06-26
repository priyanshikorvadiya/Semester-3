//WAP to find area of a circle

#include<stdio.h>
#define pie 3.14
void main(){
    float r;
    float area = 0;

    printf("Enter radius of a circle");
    scanf("%f",&r);

    area = pie * r * r; 

    printf("Area of circle is : %.2f",area);
}
