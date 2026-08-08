// Valid Parenthesis Problem 
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
// Now Chef wants to know if the given string is balanced or not.  
// If is balanced then print 1, otherwise print 0.  
// A balanced parenthesis string is defined as follows: 
//  The empty string is balanced 
//  If P is balanced then (P), {P}, [P] is also balanced 
//  if P and Q are balanced PQ is also balanced 
//  "([])", "({})[()]" are balanced parenthesis strings  
//  "([{]})", "())" are not balanced. 
 
// Input Format:  
// The first line of the input contains a single integer T denoting the number of 
// test cases. The description of T test cases follows. The first and only line of 
// each test case contains a single string 
 
// Output Format:  
// For each test case, print a single line containing the answer.

import java.util.Scanner;

public class ValidParenthesis {

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

    static char POP(){
        if(top == 0){
            System.out.println("Stack underflow!!");
            return '\0';
        }
        else{
            return S[top--];
        }
    }

    static int CheckParenthesis(){

        int i = 0;

        while(S[i] != '\0'){
            char checkChar;

            if(S[i] == '(' || S[i] == '{' || S[i] == '['){
                PUSH(S[i]);
            }
            else if(S[i] == ')' || S[i] == '}' || S[i] == ']'){

                if(top == -1){
                    return 0;
                }
                checkChar = POP();

                if((S[i] == ')' && checkChar != '(') || (S[i] == '}' && checkChar != '{') || (S[i] == ']' && checkChar =='[')){
                    return 0;
                }
            }
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

        System.out.println("Enter string:");
        String str = sc.next();
        S = str.toCharArray();

        top = -1;
        
        System.out.println(CheckParenthesis());

        sc.close();
    }

}
