// WAP to implement Priority Queue.

import java.util.Scanner;

class PriorityQ{
    int data;
    int priority;
}

public class PriorityQueue {
    static int N = 8;

    static PriorityQ PQ[] = new PriorityQ[N];
    static int PI = 0;

    static void INSERT(int x,int p){

        if(PI == N){
            System.out.println("Priority queue overflow!!");
            return;
        }

        PQ[PI] = new PriorityQ();

        PQ[PI].data = x;
        PQ[PI].priority = p;
        PI++;
    }

    static void DELETE(){
        if(PI == 0){
            System.out.println("Priority queue is overflow!");
            return;
        }

        int highestPI = 0;

        for(int i = 0; i < PI ; i++){
            if(PQ[i].priority > PQ[highestPI].priority){
                highestPI = i;
            }
        }

        int Y = PQ[highestPI].data;
        int Ypriority = PQ[highestPI].priority;

        System.out.println("Dequeued element : [Value : " + Y + "(Priority : %d)] " + Ypriority);

        for(int i = highestPI; i < PI; i++){
            PQ[i] = PQ[i + 1];
        }
        PI--;
    }

    static void DISPLAY(){
        if(PI == 0){
            System.out.println("Priority queue underflow!");
            return;
        }

        for(int i = 0; i < PI ; i++){
            System.out.println("[Value : " + PQ[i].data + "(Priority : %d)] " + PQ[i].priority);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- Priority Queue Operation Menu ---\n");
            System.out.println("1-Enqueue an element.\n");
            System.out.println("2-Dequeue an element.\n");
            System.out.println("3-Display queue.\n");

            System.out.println("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter value:");
                    int val = sc.nextInt();
                    System.out.println("Enter priority:");
                    int prio = sc.nextInt();
                    INSERT(val, prio);
                    break;
                case 2:
                    DELETE();
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
