// Write a program to remove the duplicates nodes from given sorted Linked List. 
// Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
// Output: 1 → 6 → 13 → 27 

class Node{
    int info;
    Node link;

    Node(int info){
        this.info = info;
        this.link = null;;
    }
}

public class Duplicate {

    static Node first = null;
    public static void main(String[] args) {

        insertAtFirst(27);
        insertAtFirst(27);
        insertAtFirst(13);
        insertAtFirst(13); 
        insertAtFirst(13);
        insertAtFirst(6);   
        insertAtFirst(1);
        insertAtFirst(1);

        displayNodes();

        removeDuplicate();

        displayNodes();
    }

    static void insertAtFirst(int x) {
        Node newnode = new Node(x);
        newnode.link = first;
        first = newnode;
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

    static void removeDuplicate(){
        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        Node save = first;

        while(save != null && save.link != null){
            if(save.info == save.link.info){
                // Node temp = save.link;
                save.link = save.link.link;
            }
            else{
                save = save.link;
            }
        }
    }
}
