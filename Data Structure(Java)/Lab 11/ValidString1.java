// How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
//program to solve the above problem. 

import java.util.Scanner;

public class ValidString1 {
    
    static int n = 100;

    static int Match(String str){
        String[] S = new String[100] ;
        int top = -1;
        int i = 0;

        while(str.charAt(i) != 'c' && str.charAt(i) != '\0'){
            if(top < n - 1){
                S[++top] = String.valueOf(str.charAt(i)) ;
            }
            i++;
        }

        if(str.charAt(i) == '\0'){
            return 0;
        }

        i++;

        while(str.charAt(i) != '\0'){
            if(top == -1 || String.valueOf(str.charAt(i)) != S[top]){
                return 0;
            }
            top--;
            i++;
        }

        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter string :");
        String str = sc.next();

        if(Match(str) == 1){
            System.out.println("String " +str + " is matched.");
        }
        else{
            System.out.println("String " +str + " is not matched.");
        }
        sc.close();
    }
}
