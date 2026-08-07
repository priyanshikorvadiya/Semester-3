//  Write a menu driven program to implement following operations on the doubly 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. (Home Work) 
//  Display all nodes. (Home Work)

import java.util.Scanner;

class Node{
    int info;
    Node rptr;
    Node lptr;
}

public class DoublyList {

    static Node first = null;

    static void InsertAtFirst(int x){
        Node newNode = new Node();

        if(first == null){
            newNode.info = x;
            newNode.lptr = null;
            newNode.rptr = null;
            first = newNode;
        }
        else{
            newNode.rptr = first;
            newNode.info = x;
            newNode.lptr = null;
            first.lptr = newNode;
            first = newNode;
        }
    }

    static void DeleteAtFirst(){
        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        if(first.rptr == null){
            first = null;
        }
        else{
            first.rptr.lptr = null;
            first = first.rptr;
        }
        
    }

    static void DeleteAtLast(){
        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        Node save = first;

        if(first.rptr == null){
            first = null;
        }

        while(save.rptr.rptr != null){
            save = save.rptr;
        }
        save.rptr = null;

    }

    static int Count(){
        if(first == null){
            System.out.println("Empty List!!");
            return 0;
        }

        Node save = first;
        int count = 0;

        while(save != null){
            count++;
            save = save.rptr;
        }
        return count;
    }

    static void DeleteAtKthPosition(int k){
        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        int n = Count();
        Node save = first;

        if(k < 0 || k >= n){
            System.out.println("Invalid Position !!");
            return;
        }
        else if(k == 0){
            DeleteAtFirst();
        }
        else if(k == n - 1){
            DeleteAtLast();
        }
        else{
            for(int i = 0; i < k; i++){
                save = save.rptr;
            }
            save.rptr = save.rptr.rptr;
            save.rptr.rptr = save;
        }
    }

    static void InsertAtLast(int x){
        Node newNode = new Node();

        if(first == null){
            newNode.info = x;
            newNode.rptr = null;
            newNode.lptr = null;
            first = newNode;
        }

        Node save = first;

        while(save.rptr != null){
            save = save.rptr;
        }

        newNode.info = x;
        newNode.lptr = save;
        newNode.rptr = null;

        save.rptr = newNode;

    }

    static void Display(){
        if(first == null){
            System.out.println("Empty List!");
            return;
        }

        Node save = first;
        while (save != null) {
            System.out.print(save.info+" -> ");
            save = save.rptr;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        boolean run = true;

        while(run){
            System.out.println("Enter your choice (1-5)\n");
            System.out.println("1-Insert a node at the front of the linked list.\n");
            System.out.println("2-Delete a node from specified position.\n");
            System.out.println("3-Insert a node at the end of the linked list.\n");
            System.out.println("4-Display all nodes.\n");
            System.out.println("5-Exit\n");
            int choice = sc.nextInt();

            switch (choice)
            {
            case 1:
                System.out.println("Enter value to insert :");
                int val = sc.nextInt();
                InsertAtFirst(val);
                break;

            case 2:
                System.out.println("Enter position where you want to delete:");
                int k = sc.nextInt();
                DeleteAtKthPosition(k);
                break;

            case 3:
                System.out.println("Enter value to insert :");
                int value = sc.nextInt();
                InsertAtLast(value);
                break;

            case 4:
                Display();
                break;

            case 5:
                System.out.println("Exiting program.\n");
                run = false;
                break;
            default:
                System.out.println("Invalid choice");
                break;
            }
        }
    sc.close();
    }
    
}
