// Write a program to implement queue using singly linked list. 

import java.util.Scanner;

class Node {
    int info;
    Node link;
}

public class QueueList {
    static Node F = null;
    static Node R = null;

    static void ENQUEUE(int x){
        Node newNode = new Node();

        newNode.info = x;
        newNode.link = null;

        if(R == null){
            F = R = newNode;
        }
        else{
            R.link = newNode;
            R = newNode;
        }
    }

    static void DEQUEUE(){
        if(F == null){
            System.out.println("Queue underflow!");
            return;
        }
        else{

            F = F.link;

            if(F == null){
                R = null;
            }
        }
    }
    
    static void DISPLAY(){
        if(F == null){
            System.out.println("Queue underflow!!");
            return;
        }

        Node save = F;

        while(save != null){
            System.out.print(save.info + "->");
            save = save.link;
        }
        System.out.println("null");
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
