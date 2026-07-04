//WAP to check whether 2 singly linked lists are same or not

class Node{
    int info;
    Node link;

    Node(int info){
        this.info = info;
        this.link = null;;
    }
}

public class Compare {
    static Node first = null;
    public static void main(String[] args) {

        Node First1 = null;
        Node First2 = null;

        First1 = insertAtFirst(9,First1);
        First1 = insertAtFirst(8,First1);
        First1 = insertAtFirst(7,First1);
        First1 = insertAtFirst(6,First1);

        First2 =insertAtFirst(9,First2);
        First2 =insertAtFirst(8,First2);
        First2 =insertAtFirst(7,First2);
        First2 =insertAtFirst(6,First2);

        displayNodes(First1);
        displayNodes(First2);

        CompareNodes(First1, First2);
    }

    static Node insertAtFirst(int x,Node first) {
        Node newnode = new Node(x);
        newnode.link = first;
        first = newnode;

        return first;
    }

    static void displayNodes(Node first) {
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

    static void CompareNodes(Node save1,Node save2){

        int isSame = 0;

        while(save1 != null && save2 != null){
            if(save1.info != save2.info){
                isSame = 1;
                break;
            }
            save1 = save1.link;
            save2 = save2.link;
        }

        if(save1 == null && save2 == null && isSame == 0){
            System.out.println("Given both lists are same.");
        }
        else{
            System.out.println("Given both lists are not same !!");
        }
    }
}
