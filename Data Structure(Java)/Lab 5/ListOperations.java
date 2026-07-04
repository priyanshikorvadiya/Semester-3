//  Write a menu driven program to implement following operations on the singly 
// linked list.  
//  Insert a node at the front of the linked list. 
//  Display all nodes. 
//  Delete a first node of the linked list. 
//  Insert a node at the end of the linked list. 
//  Delete a last node of the linked list. 
//  Delete a node from specified position. 
//  Count the no. of nodes in the linked list. 

import java.util.Scanner;

class Node {
    int info;
    Node link;

    Node(int info) {
        this.info = info;
        this.link = null;
    }
}

public class ListOperations {
    // Shared head of the linked list
    static Node first = null; 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;

        while (choice != 8) {
            System.out.println("\n--- Singly Linked List Menu ---");
            System.out.println("1-Insert at front.");
            System.out.println("2-Display all nodes.");
            System.out.println("3-Delete first node.");
            System.out.println("4-Insert at end.");
            System.out.println("5-Delete last node.");
            System.out.println("6-Delete from specified position.");
            System.out.println("7-Count total nodes.");
            System.out.println("8-Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert at front: ");
                    int x = sc.nextInt();
                    insertAtFirst(x);
                    break;
                case 2:
                    displayNodes();
                    break;
                case 3:
                    deleteAtFirst();
                    break;
                case 4:
                    System.out.print("Enter value to insert at end: ");
                    int val = sc.nextInt();
                    insertAtEnd(val);
                    break;
                case 5:
                    deleteAtLast();
                    break;
                case 6:
                    System.out.print("Enter position to delete (1-based index): ");
                    int posi = sc.nextInt();
                    deleteAtPosi(posi);
                    break;
                case 7:
                    int count = countNodes();
                    System.out.println("Total number of nodes: " + count);
                    break;
                case 8:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        sc.close();
    }

    static void insertAtFirst(int x) {
        Node newnode = new Node(x);
        newnode.link = first;
        first = newnode;
        System.out.println("Inserted " + x + " at front.");
    }

    static void displayNodes() {
        if (first == null) {
            System.out.println("List is empty.");
            return;
        }
        Node save = first;
        while (save != null) {
            System.out.print(save.info + " -> ");
            save = save.link;
        }
        System.out.println("null");
    }

    static void deleteAtFirst() {
        if (first == null) {
            System.out.println("Underflow! Empty List.");
            return;
        }
        System.out.println("Deleted node with value: " + first.info);
        first = first.link;
    }

    static void insertAtEnd(int x) {
        Node newNode = new Node(x);
        if (first == null) {
            first = newNode;
            System.out.println("Inserted " + x + " as the first node.");
            return;
        }
        Node save = first;
        while (save.link != null) {
            save = save.link;
        }
        save.link = newNode;
        System.out.println("Inserted " + x + " at end.");
    }

    static Node deleteAtLast(){
        if (first == null) {
            System.out.println("List is empty.");
            return null;
        }
        
        if (first.link == null) {
            return null;
        }
    
        Node pred = null;
        Node save = first;
        
        while (save.link != null) {
            pred = save;       
            save = save.link;  
        }
        
        pred.link = null; 
        
        return first;

    }

    static void deleteAtPosi(int posi) {
        if (first == null) {
            System.out.println("Underflow! Empty List.");
            return;
        }
        if (posi < 1) {
            System.out.println("Invalid Position!");
            return;
        }
        if (posi == 1) {
            System.out.println("Deleted node at position 1: " + first.info);
            first = first.link;
            return;
        }
        Node save = first;
        int i = 0;
        while (i < posi - 1 && save != null) {
            save = save.link;
            i++;
        }
        if (save == null || save.link == null) {
            System.out.println("Position out of bounds!");
        } else {
            System.out.println("Deleted node at position " + posi + ": " + save.link.info);
            save.link = save.link.link;
        }
    }

    static int countNodes() {
        int count = 0;
        Node save = first;
        while (save != null) {
            count++;
            save = save.link;
        }
        return count;
    }
}
