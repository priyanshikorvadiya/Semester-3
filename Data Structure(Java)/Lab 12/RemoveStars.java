// Removing starts from a string Problem 
// You are given a string s, which contains stars *. In one operation, you can: 
// Choose a star in s. Remove the closest non-star character to its left, as well as 
// remove the star itself. Return the string after all stars have been removed. 
 
// Note :  
//  The input will be generated such that the operation is always possible. 
//  It can be shown that the resulting string will always be unique.

import java.util.Scanner;

public class RemoveStars {
    
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

    static int POP(){
        if(top == 0){
            System.out.println("Stack underflow!!");
            return -1;
        }
        else{
            return S[top--];
        }
    }

    static void DISPLAY(){
        if(top == -1){
            System.out.println("Stack underflow!!");
            return;
        }
        else{
            for(int i = 0; i <= top ; i++){
                System.out.println(S[i]);
            }
            System.out.println();
        }
    }

    static void REMOVE(){
        int len = S.length;

        for(int i = 0 ; i < len ; i++){
            if(S[i] == '*'){
                POP();
            }
            else{
                PUSH(S[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string:");
        String str = sc.next();
        S = str.toCharArray();

        REMOVE();

        DISPLAY();

        sc.close();
    }
}
