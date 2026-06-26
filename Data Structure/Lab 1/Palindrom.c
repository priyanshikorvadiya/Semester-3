//WAP to find whether the given number is palindrom or not.

#include <stdio.h>

void main() {
    int num, ogNum, rev = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    ogNum = num;

    while (num != 0) {
        remainder = num % 10;
        rev = rev * 10 + remainder;
        num /= 10;
    }

    if (ogNum == rev){
        printf("%d is a Palindrome Number.", ogNum);
    }   
    else{
        printf("%d is not a Palindrome Number.", ogNum);
    }
}