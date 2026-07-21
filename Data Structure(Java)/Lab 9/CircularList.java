// Write a menu driven program to implement following operations on the circular 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. 
//  Display all nodes.

import java.util.Scanner;

class Node{
    int info;
    Node link;
}

public class CircularList {

    static Node first = null;
    static Node last = null;

    static void InsertAtFirst(int x){
        Node newNode = new Node();

        if(first == null){
            newNode.info = x;
            first = newNode;
            last = newNode;
            newNode.link = first;
        }
        else{
            newNode.info = x;
            newNode.link = first;

            first = newNode;

            last.link = first;
        }
    }

    static void InsertAtLast(int x){

        Node newNode = new Node();

        if(first == null){
            System.out.println("Empty List!!");
            return;
        }
        else{
            newNode.info = x;
            newNode.link = first;
            last.link = newNode;

            last = newNode;
        }
    }

    static int Count(){
        
        if(first == null){
            System.out.println("Empty List!!");
            return 0;
        }
        else{
            Node save = first;
            int count = 0;

            while(save.link != first){
                count++;
                save = save.link;
            }

            return count;
        }
    }

    static void DeleteAtFirst(){

        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        if(first.link == first){
            first = null;
            return;
        }

        Node last = first;

        while (last.link != first) {
            last = last.link;
        }

        first = first.link;
        last.link = first;
    }
    
    static void DeleteAtLast(){
        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        if(first.link == first){
            first = null;
            return;
        }

        Node prev = null;
        Node last = first;

        while (last.link != first) {
            prev = last;
            last = last.link;
        }

        prev.link = first;
    }

    static void DeleteAtKthPosition(int k){
        int n = Count();

        if(k < 0 || k >= n){
            System.out.println("Invalid Position !!");
            return;
        }
        else if(k == 0){
            DeleteAtFirst();
            return;
        }
        else if(k == n - 1){
            DeleteAtLast();
            return;
        }
        else{
            Node save = first;
            
            for(int i = 0 ; i < k; i++){
                save = save.link;
            }

            save.link = save.link.link;
        }
    }

    static void Display(){
        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        Node save = first;

        while(save.link != first){
            System.out.print(save.info + " -> ");
            save = save.link;
        }
        System.out.print(save.info + " -> ");
        System.out.println("first");
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