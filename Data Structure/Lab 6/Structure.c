// WAP to define a C structure named Student (roll_no, name, branch and 
//batch_no) and also to access the structure members using Pointer. 

#include<stdio.h>
struct Student
{
    int roll_no;
    char branch;
    char Name;
    int batch_no;
};

void main(){
    struct Student *sptr,s1;
    sptr = &s1;

    printf("Enter name :");
    scanf("%s",sptr ->Name);
    printf("Enter branch name :");
    scanf("%s",sptr ->branch);
    printf("Enter roll no. :");
    scanf("%d",sptr ->roll_no);
    printf("Enter branch no. :");
    scanf("%d",sptr ->batch_no);

    printf("Name : %s\n",sptr ->Name);
    printf("Branch : %s\n",sptr ->branch);
    printf("Roll no : %d\n",sptr ->roll_no);
    printf("Batch no. : %d\n",sptr ->batch_no);
    
}
