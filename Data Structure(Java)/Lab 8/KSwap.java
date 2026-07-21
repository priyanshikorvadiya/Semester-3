//WAP to swap Kth node from beginning with Kth node from end in a singly linked 
//list.

import java.util.Scanner;

class Node{
    int info;
    Node link;
}

public class KSwap {

    static Node first;

    static void InsertAtFirst(int x){

        Node newNode = new Node();

        newNode.info = x;
        newNode.link = first;
        first = newNode;
    }

    static void Display(){
        Node save = first;

        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        while(save != null){
            System.out.print(save.info +"->");
            save = save.link;
        }
        System.out.println("null");
    }

    static int Count(){
        int count = 0;
        Node save = first;

        while(save != null){
            count++;
            save = save.link;
        }

        return count;
    }

    static void Swap(int k){
        int n = Count();

        if(k < 0 || k > n || 2 * k - 1 == n){
            System.out.println("Invalid position !!");
            return;
        }
        
        Node prev = null;
        Node save = first;
        int count = 1;

        while(count < k){
            count++;
            prev = save;
            save = save.link;
        }

        count = 1;
        Node prev2 = null;
        Node save2 = first;

        while(count < (n - k + 1)){
            count++;
            prev2 = save2;
            save2 = save2.link;
        }

        if(prev != null){
            prev.link = save2;
        }
        else{
            first = save2;
        }

        if(prev2 != null){
            prev2.link = save;
        }
        else{
            first = save;
        }

        Node temp = save.link;
        save.link = save2.link;
        save2.link = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        InsertAtFirst(10);
        InsertAtFirst(9);
        InsertAtFirst(8);
        InsertAtFirst(7);
        InsertAtFirst(6);

        Display();

        System.out.println("Enter position :");
        int k = sc.nextInt();

        Swap(k);

        Display();

        sc.close();
    }
    
}
