// Write a menu driven program to implement following operations on the Stack 
// using an Array 
//  PUSH, POP, DISPLAY 
//  PEEP, CHANGE

import java.util.Scanner;

public class StackOperation {
    static int[] S;
    static int top = -1;
    static int n;

    static void PUSH(int x) {
        if (top >= n - 1) {
            System.out.println("Stack Overflow!");
        } else {
            S[++top] = x;
            System.out.println(x + " pushed into stack.");
        }
    }

    static int POP() {
        if (top == -1) {
            System.out.println("Stack Underflow!!");
            return -1;
        } else {
            return S[top--];
        }
    }

    static void DISPLAY() {
        if (top == -1) {
            System.out.println("Stack is empty!");
            return;
        }
        System.out.print("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            System.out.print(S[i] + " ");
        }
        System.out.println();
    }

    static int PEEP(int i) {
        // i represents the ith element from the top (1st from top, 2nd from top, etc.)
        if (top - i + 1 < 0 || i <= 0) {
            System.out.println("Invalid Index");
            return -1;
        } else {
            return S[top - i + 1];
        }
    }

    static void CHANGE(int i, int x) {
        if (top - i + 1 < 0 || i <= 0) {
            System.out.println("Invalid Index!!");
        } else {
            S[top - i + 1] = x;
            System.out.println("Value changed successfully.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // CRITICAL FIX: Initialize stack size and array
        System.out.print("Enter the size of the stack: ");
        n = sc.nextInt();
        S = new int[n];

        boolean run = true;
        while (run) {
            System.out.println("\n--- Stack Operations Menu ---");
            System.out.println("1 - PUSH");
            System.out.println("2 - POP");
            System.out.println("3 - DISPLAY");
            System.out.println("4 - PEEP");
            System.out.println("5 - CHANGE");
            System.out.println("6 - Exit");
            System.out.print("Enter your choice (1-6): ");
            
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert: ");
                    int val = sc.nextInt();
                    PUSH(val);
                    break;
                case 2:
                    int poppedVal = POP();
                    if (poppedVal != -1) {
                        System.out.println("Popped value: " + poppedVal);
                    }
                    break;
                case 3:
                    DISPLAY();
                    break;
                case 4:
                    System.out.print("Enter position from top (1-based): ");
                    int idx = sc.nextInt();
                    int peepedVal = PEEP(idx);
                    if (peepedVal != -1) {
                        System.out.println("Value at position " + idx + " from top is: " + peepedVal);
                    }
                    break;
                case 5:
                    System.out.print("Enter position from top to change (1-based): ");
                    int j = sc.nextInt();
                    System.out.print("Enter new value: ");
                    int x = sc.nextInt();
                    CHANGE(j, x);
                    break;
                case 6:
                    System.out.println("Exiting program.");
                    run = false;
                    break;
                default:
                    System.out.println("Invalid choice! Please select between 1-6.");
                    break;
            }
        }
        sc.close();
    }
}
