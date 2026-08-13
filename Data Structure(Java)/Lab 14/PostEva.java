// Write a program for evaluation of postfix Expression using Stack.

import java.util.Scanner;

public class PostEva {
  
    static final int MAX = 100;
    static int[] stack = new int[MAX];
    static int top = -1;

    static void push(int x) {
        if (top >= MAX - 1) {
            System.out.println("Stack overflow!!");
            return;
        }
        stack[++top] = x;
    }

    static int pop() {
        if (top < 0) {
            System.out.println("Stack underflow!!");
            return -1;
        }
        return stack[top--];
    }

    static int Evaluation(char[] exp) {
        int op1, op2;
        char ch;

        for (int i = 0; i < exp.length; i++) {
            ch = exp[i];

            if (Character.isDigit(ch)) {
                push(ch - '0');
            } else {
                op2 = pop(); 
                op1 = pop(); 

                switch (ch) {
                    case '+':
                        push(op1 + op2);
                        break;
                    case '-':
                        push(op1 - op2);
                        break;
                    case '*':
                        push(op1 * op2);
                        break;
                    case '/':
                        if (op2 == 0) {
                            System.out.println("Error: Division by zero!");
                            return -1;
                        }
                        push(op1 / op2);
                        break;
                    case '^':
                        push((int) Math.pow(op1, op2));
                        break;
                    default:
                        System.out.println("Invalid operator: " + ch);
                        return -1;
                }
            }
        }
        return pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter postfix exp : ");
        String str = sc.next();

        char[] exp = str.toCharArray();

        System.out.println("Result is : " + Evaluation(exp));
        
        sc.close();
    }
}
