//  Vowel Anxiety Problem 
// Utkarsh has reSently started taking English-language classes to improve his 
// reading and writing skills. However, he is still struggling to learn English. His 
// teacher gave him the following problem to improve his vowel-identification 
// skills:  
 
// There is a string S of length N consisting of lowercase English letters only.  
// Utkarsh has to start from the first letter of the string. 
// Each time he encounters a vowel; he has to reverse the entire substring that 
// came before the vowel. 
// Utkarsh needs help verifying his answer. Can you print the final string after 
// performing all the operations for him? 
 
// Input Format: 
//  First line will contain T, number of test cases. Then T test cases follow. 
//  The first line of each test case contains N, the length of the string. 
//  The second line contains S, the string itself. 
 
// Output Format: 
// For each test case, output in a single line the final string after traversing S from 
// left to right and performing the necessary reversals. 

import java.util.Scanner;

public class VowelAnxiety {

    static int top = -1;
    static int n = 100;
    static char[] S = new char[n];

    static void PUSH(char x){
        if(top >= n - 1){
            System.out.println("Stack overflow!!");
            return;
        }
        else{
            S[++top] = x;
        }
    }

    static void DISPLAY(){
        if(top == -1){
            System.out.println("Stack underflow!!");
            return;
        }
        else{
            for(int i = 0; i <= top ; i++){
                System.out.print(S[i]);
            }
            System.out.println();
        }
    }

    static void reverse(){
        for(int i = 0; i <= top/2 ; i++){
            char temp = S[i];
            S[i] = S[top - i];
            S[top - i] = temp;
        }
    }

    static void vowelCheck(){
        int i = 0;
        // S[i] != '\0';

        while(S[i] != '\0'){

            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' ||
            S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U') {
                reverse();
            }
            PUSH(S[i]);
            i++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string:");
        String str = sc.next();
        S = str.toCharArray();

        vowelCheck();;

        DISPLAY();

        sc.close();
    }
}
