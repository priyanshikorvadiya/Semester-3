//  Write a menu driven program to implement following operations on the Queue 
// using an Array 
//  ENQUEUE 
//  DEQUEUE 
//  DISPLAY

import java.util.Scanner;

public class QueueOperation {
    static int N = 10;

    static int R = -1,F = -1;
    static int[] Q = new int[N];

    static void ENQUEUE(int x){
        if(R >= N - 1){
            System.out.println("Queue overflow!");
            return;
        }
        else{
            if(F == -1){
                F = 0;
            }
            R++;
            Q[R] = x;
        }
    }

    static int DEQUEUE(){
        if(F == -1){
            System.out.println("Queue underflow!");
            return 0;
        }
        else{
            int Y = Q[F];

            if(F == R){
                F = -1;
                R = -1;
            }
            else{
                F++;
            }
            return Y;
        }
    }

    static void DISPLAY(){
        if(F == -1){
            System.out.println("Queue underflow!");
            return;
        }
        for(int i = 0 ; i <= R ; i++){
            System.out.print(Q[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- Queue Operation Menu ---\n");
            System.out.println("1-Enqueue an element.\n");
            System.out.println("2-Dequeue an element.\n");
            System.out.println("3-Display queue.\n");

            System.out.println("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter value:");
                    int val = sc.nextInt();
                    ENQUEUE(val);
                    break;
                case 2:
                    DEQUEUE();
                    break;
                case 3:
                    DISPLAY();
                    break;
                default:
                    System.out.println("Invalid choice.\n");
                    sc.close();
            }
        }
    }
}
