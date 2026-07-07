//WAP to copy a linked list.

class Node{
    int info;
    Node link;

    Node(int info){
        this.info = info;
        this.link = null;
    }
}

public class CopyList {

    static Node first1 = null;
    static Node first2 = null;

    static void insertAtFirst(int x){
        Node newNode = new Node(x);

        newNode.info = x;
        newNode.link = first1;

        first1 = newNode;

    }

    static void displayNodes(Node first){

        if(first == null){
            System.out.println("List is empty!!");
            return;
        }

        Node save = first;

        while(save != null){
            System.out.print(save.info+"->");
            save = save.link;
        }
        System.out.println("null");
    }

    static void insertAtlast(int x){
        Node newNode = new Node(x);

        if(first2 == null){
            first2 = newNode;
            return;
        }

        Node save = first2;

        while(save.link != null){
            save = save.link;
        }
        save.link = newNode;
    }

    static void Copylist(){
        Node save = first1;

        while(save != null){
            insertAtlast(save.info);
            save = save.link;
        }
    }

    public static void main(String[] args) {
        
        insertAtFirst(9);
        insertAtFirst(8);
        insertAtFirst(7);
        insertAtFirst(6);

        displayNodes(first1);

        Copylist();

        displayNodes(first2);
    }
}