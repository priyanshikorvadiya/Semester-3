//  Write a menu driven program to implement following operations on a circular 
// queue using an Array 
//  Insert 
//  Delete 
//  Display all elements of the queue

import java.util.Scanner;

public class CQOperation {
    static int N = 10;

    static int R = -1, F = -1;
    static int[] CQ = new int[N];

    static void CQInsert(int x){
        if(((R + 1) % N) == F){
            System.out.println("Stack Overflow!!");
            return;
        }
        else if(F == -1){
            F = 0;
            R = 0;
        }
        else{
            R = (R + 1) % N;
        }
        CQ[R] = x;
    }

    static int CQDelete(){
        if(F == -1){
            System.out.println("Queue Underflow!!");
            return 0;
        }
        else{
            int Y = CQ[F];

            if(F == R){
                F = -1;
                R = -1;
            }
            else{
                F = (F + 1) % N;
            }
            return Y;
        }
    }

    static void CQDisplay(){
        if(F == -1){
            System.out.println("Queue Underflow!");
            return;
        }
        int i = F;

        while(true){
            System.out.print(CQ[i] + " ");

            if(i == R){
                break;
            }

            i = (i + 1) % N;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- Circular Queue Operation Menu ---\n");
            System.out.println("1-Enqueue an element.\n");
            System.out.println("2-Dequeue an element.\n");
            System.out.println("3-Display queue.\n");

            System.out.println("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter value:");
                    int val = sc.nextInt();
                    CQInsert(val);
                    break;
                case 2:
                    CQDelete();
                    break;
                case 3:
                    CQDisplay();
                    break;
                default:
                    System.out.println("Invalid choice.\n");
                    sc.close();
            }
        }
    }
}
