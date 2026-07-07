//WAP to reverse a linked list.

class Node{
    int info;
    Node link;

    Node(int info){
        this.info = info;
        this.link = null;
    }
}

public class ReverseList {
    
static Node first;

static void insertAtFirst(int x){
    Node newNode = new Node(x);

    newNode.info = x;
    newNode.link = first;

    first = newNode;
}

static void displayNodes(){
    if(first == null){
        System.err.println("Empty List!!");
        return;
    }

    Node save = first;

    while(save != null){
        System.out.print(save.info+"->");
        save = save.link;
    }
    System.out.println("null");
}

static void reverseList(){
    Node prev = null;
    Node save = first;
    Node next = null;

    while(save != null){
        next = save.link;
        save.link = prev;

        prev = save;
        save = next; 
    }
    first = prev;
}

    public static void main(String[] args) {
        insertAtFirst(9);
        insertAtFirst(8);
        insertAtFirst(7);
        insertAtFirst(6);

        System.out.println("Original List:");
        displayNodes();

        reverseList();

        System.out.println("Reversed List:");
        displayNodes();
    }
}
