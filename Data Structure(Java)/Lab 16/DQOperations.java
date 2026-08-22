// Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
//  Insert at front end, Insert at rear end 
//  Delete from front end, Delete from rear end 
//  Display all elements of the queue 

import java.util.Scanner;

public class DQOperations {
    static int N = 6;
    static int[] Q = new int[N];
    static int F = -1;
    static int R = -1;

    static void DQINSERT_FRONT(int x){
        if(F == 0){
            System.out.println("DQueue overflow at front !!");
            return;
        }

        if(F == -1){
            F = 0;
            R = 0;
        }
        else{
            F = F - 1;
        }
        Q[F] = x;
    }

    static void DQINSERT_REAR(int x){
        if(R == N - 1){
            System.out.println("DQueue overflow at rear!");
            return;
        }

        if(F == -1){
            F = 0;
            R = 0;
        }
        else{
            R = R + 1;
        }
        Q[R] = x;
    }

    static int DQDELETE_FRONT(){
        if(F == -1){
            System.out.println("DQueue underflow at front!");
            return -1;
        }

        int Y = Q[F];

        if(F == R){
            F = -1;
            R = -1;
        }
        else{
            F = F + 1;
        }
        return Y;
    }

    static int DQDELETE_REAR(){

        if(R == -1){
            System.out.println("DQueue underflow at rear!");
            return -1;
        }

        int Y = Q[R];

        if(F == R){
            F = -1;
            R = -1;
        }
        else{
            R = R - 1;
        }

        return Y;
    }

    static void DQDISPLAY(){
        if(F == -1){
            System.out.println("Queue underflow!");
            return;
        }
        for(int i = F; i <= R ; i++){
            System.out.print(Q[i]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- Double Ended Queue Operation Menu ---\n");
            System.out.print("1-Enqueue an element at the front of DQueue.\n");
            System.out.print("2-Eequeue an element at the rear of DQueue.\n");
            System.out.print("3-Dequeue an element at the front of DQueue.\n");
            System.out.print("4-Dequeue an element at the rear of DQueue.\n");
            System.out.println("5-Display queue.\n");

            System.out.print("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter value:");
                    int val = sc.nextInt();
                    DQINSERT_FRONT(val);
                    break;
                case 2:
                    System.out.println("Enter value:");
                    int val1 = sc.nextInt();
                    DQINSERT_REAR(val1);
                    break;
                case 3:
                    DQDELETE_FRONT();
                    break;
                case 4:
                    DQDELETE_REAR();
                    break;
                case 5:
                    DQDISPLAY();
                    break;
                default:
                    System.out.println("Invalid choice.\n");
                    sc.close();
            }
        }
    }
}


