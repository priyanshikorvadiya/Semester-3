//WAP to delete alternate nodes of a doubly linked list.

class Node{
    int info;
    Node rptr;
    Node lptr;
}

public class DeleteAlternate {
    static Node first = null;

    static void InsertAtFirst(int x){
        Node newNode = new Node();

        if(first == null){
            newNode.info = x;
            newNode.lptr = null;
            newNode.rptr = null;
            first = newNode;
        }
        else{
            newNode.rptr = first;
            newNode.info = x;
            newNode.lptr = null;
            first.lptr = newNode;
            first = newNode;
        }
    }

    static void Display(){
        if(first == null){
            System.out.println("Empty List!");
            return;
        }

        Node save = first;
        while (save != null) {
            System.out.print(save.info+" -> ");
            save = save.rptr;
        }
        System.out.println("null");
    }
    
    static void Deletion(){

        if(first == null){
            System.out.println("Empty List!!");
            return;
        }
        else if(first.rptr == null){
            System.out.println("Deletion not possible!!");
            return;
        }
        else{
            Node save = first;
            Node temp = null;

            while (save != null && save.rptr != null) {
                temp = save.rptr;
                save.rptr = temp.rptr;

                if(temp.rptr != null){
                    temp.rptr.lptr = save;
                }
                save = save.rptr;
            }
        }
    }

    public static void main(String[] args) {
        InsertAtFirst(9);
        InsertAtFirst(8);
        InsertAtFirst(7);
        InsertAtFirst(6);
        InsertAtFirst(5);
        InsertAtFirst(4);

        Display();

        Deletion();

        Display();
    }
}
