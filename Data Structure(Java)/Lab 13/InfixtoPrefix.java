// Write a program to convert infix notation to prefix notation using stack.

import java.util.Scanner;

public class InfixtoPrefix{

    static int N = 100;
    static char[] S = new char[N];
    static int top = -1; 
    
    static int IPF(char ch){
        if(ch == '+' || ch == '-'){
            return 1;
        }
        if(ch == '*' || ch == '/'){
            return 3;
        }
        if(ch == '^'){
            return 6;
        }
        if(Character.isLetterOrDigit(ch)){
            return 7;
        }
        if(ch =='('){
            return 9;
        }
        if(ch == ')'){
            return 0;
        }
        return -1;
    }
    
    static int SPF(char ch){
        if (ch == '+' || ch == '-'){
            return 2;
        }
        if (ch == '*' || ch == '/'){
            return 4;
        }
        if (ch == '^'){
            return 5;
        }
        if (Character.isLetterOrDigit(ch)){
            return 8; 
        }
        if (ch == '('){
            return 0;
        }
        return 0;
    }
    
    static int RANK(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            return -1;
        }
        if (Character.isLetterOrDigit(ch)) {
            return 1;
        }
        return 0;
    }
    
    static void PUSH(char ch){
        if(top < N - 1){
            S[++top] = ch;
        }
        else{
            System.out.println("Stack overflow!!");
            return;
        }
    }
    
    static char POP(){
        if(top == -1){
            return '\0';
        }
        else{
            return S[top--];
        }
    }
    
    static void Conversion(char[] input){
        int len = input.length;
        char[] INFIX = new char[len + 2];

        for(int i = 0; i <len ; i++){
            char raw = input[len - 1 - i];
            INFIX[i] = (raw == '(') ? ')' : (raw == ')') ? '(' : raw;
        }

        int p_index = 0;
        INFIX[len] = ')';
        INFIX[len + 1] = '\0';
        top = -1; 

        PUSH('(');
        char[] POLISH = new char[N];
        
        int rank = 0;
        int index = 0;
        char NEXT = INFIX[index++];
        
        while (NEXT != '\0') {
            if(top < 0){ 
                System.out.println("Stack underflow!!");
                return;
            }
            
            if(Character.isLetterOrDigit(NEXT)){
                POLISH[p_index++] = NEXT;
                rank = rank + RANK(NEXT);
            }
            else{

                while(top >= 0 && SPF(S[top]) >= IPF(NEXT)){
                    char temp = POP();
                    
                    if (temp != '(' && temp != ')') {
                        POLISH[p_index++] = temp;
                        rank = rank + RANK(temp);
                    }
                    if(rank < 0){ 
                        System.out.println("Rank can't be less than 0. Current rank :"+rank);
                        return;
                    }
                }
                
                if(top >= 0 && SPF(S[top]) != IPF(NEXT)){
                    PUSH(NEXT);
                }
                else{
                    POP();
                }
            }
            
            NEXT = INFIX[index++]; 
        }
        
        if(top != -1 || rank != 1){ 
            System.out.println("ERROR : Final evaluation is Invalid : Top = " + top +" Rank = "+ rank);
        }
        else{
            System.out.println("Infix expression :"+new String(input));
            System.out.print("Prefix expression :");

            for(int i = p_index - 1; i >= 0; i--) {
                System.out.print(POLISH[i]);
            }

            System.out.println();
        }
    }
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter input exp :");
        String inputstr = sc.next();

        int len = inputstr.length();
        char[] input = new char[len];

        for(int i = 0 ; i < len ; i++){
            input[i] = inputstr.charAt(i);
        }

        Conversion(input);
        
        sc.close();
    }
}
