//WAP to implement stack using singly linked list.

import java.util.Scanner;

class Node{
    int info;
    Node link;
}

public class StackList {
    
    static Node top = null;

    static void PUSH(int x){
        Node newNode = new Node();

        newNode.info = x;
        newNode.link = top;

        top = newNode;
    }

    static void POP(){
        if(top == null){
            System.out.println("Stack underflow!!");
            return;
        }

        Node temp = top;
        System.out.println(temp.info);
        top = top.link;
    }

    static void DISPLAY(){
        if(top == null){
            System.out.println("Stack Underflow!!");
            return;
        }

        Node save = top;

        while(save != null){
            System.out.print(save.info + "->");
            save = save.link;
        }

        System.out.println("null");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        PUSH(10);
        PUSH(78);
        PUSH(0);

        DISPLAY();

        POP();
        POP();

        DISPLAY();

        sc.close();

    }
}

