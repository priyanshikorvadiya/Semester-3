//WAP to split a circular linked list into two halves.

class Node{
    int info;
    Node link;
}

public class Split {

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

    static void Display(Node first){
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

    static void SplitList(){

        if(first == null || first.link == first){
            System.out.println("No sufficient elements!");
            return;
        }

        Node slow = first;
        Node fast = first;

        while(fast.link != first && fast.link.link != first){
            slow = slow.link;
            fast = fast.link.link;
        }

        Node first2 = slow.link;
        slow.link = first;

        last.link = first2;

        System.out.println("First Half :");
        Display(first);

        System.out.println("Second Half");
        Display(first2);
    }

    public static void main(String[] args) {
        
        InsertAtFirst(10);
        InsertAtFirst(9);
        InsertAtFirst(8);
        InsertAtFirst(7);

        SplitList();
    }
}
