// How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
//program to solve the above problem. 

// #include<stdio.h>

// int max = 100;

// int Match(char str[]){
//     char stack[max];
//     int top = -1,i = 0;

//     while(str[i] != 'c' && str[i] != '\0'){
//         if(top < max - 1){
//             stack[++top] = str[i];
//         }    
//         i++;
//     }

//     if(str[i] == '\0'){
//         return 0;
//     }

//     i++;

//     while(str[i] != '\0'){
//         if(top == -1  || str[i] != stack[top--]){
//             return 0;
//         }
//         top--;
//         i++;
//     }
    
//     if(top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void main(){
//     char str[100];

//     printf("Enter string :");
//     fflush(stdout);

//     if(scanf("%99s",str) != 1){
//         printf("Error reading input");
//     }

//     if(Match(str) == 1){
//         printf("String %s is matched.");
//     }
//     else{
//         printf("String %s is not matched");
//     }
// }

#include <stdio.h>

int max = 100;

int Match(char str[]) {
    char stack[100];
    int top = -1;
    int i = 0;

    while (str[i] != 'c' && str[i] != '\0') {
        if (top < max - 1) {
            stack[++top] = str[i];
        }
        i++;
    }

    if (str[i] == '\0') {
        return 0; 
    }

    i++;

    while (str[i] != '\0') {
        if (top == -1 || str[i] != stack[top]) {
            return 0;
        }
        top--; // Safe pop
        i++;
    }

    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s",str);

    if (Match(str) == 1) {
        printf("String %s is MATCHED.\n", str);
    } else {
        printf("String %s is NOT MATCHED!\n", str);
    }

}