//WAP to allocate and de-allocate memory for int, char and float variable at 
//runtime. 

#include<stdio.h>
#include<stdlib.h>

void  main(){

    int *n1 = (int *)malloc(sizeof(int));
    char *c = (char *)malloc(sizeof(char));
    float *n2 = (float *)malloc(sizeof(float));

    *n1 = 4;
    *c = 'a';
    *n2 = 5.6f;

    if(n1 == NULL || c == NULL || n2 == NULL){
        printf("Memory allocation failed!!");
    }

    printf("Int : %d,Char : %s,Float : %f",*n1,*c,*n2);
}