//Write a program to sort elements of a linked list.

class Node{
    int info;
    Node link;
}

public class SortList {
    
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

    static void Sort(){
        Node save;
        Node save2;

        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        for(save = first; save.link != null; save = save.link){
            for(save2 = save.link ; save2 != null ; save2 = save2.link){
                if(save.info > save2.info){
                    int temp = save.info;
                    save.info = save2.info;
                    save2.info = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        InsertAtFirst(2);
        InsertAtFirst(7);
        InsertAtFirst(0);
        InsertAtFirst(4);
        InsertAtFirst(8);

        Display();

        Sort();

        Display();

    }
}
