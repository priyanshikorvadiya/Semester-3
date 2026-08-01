//Write a program to determine if an input character string is of the form aibi 
//where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. 

#include <stdio.h>

int Match(char str[]) {
    int i = 0;
    int Acount = 0,Bcount = 0;

    while (str[i] == 'a')
    {
        Acount++;
        i++;
    }

    if(Acount == 0){
        return 0;
    }

    while(str[i] == 'b'){
        Bcount++;
        i++;
    }

    if(str[i] == '\0' && Acount == Bcount){
        return 1;
    }
    return 0;
    
}

void main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s",str);

    if (Match(str) == 1) {
        printf("String %s is Valid.\n", str);
    } else {
        printf("String %s is NOT Valid!\n", str);
    }

}