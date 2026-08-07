// Write a program to swap two consecutive nodes in the linked list. Don’t change 
//the values of nodes, implement by changing the link of the nodes. 
// Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
// Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 

class Node{
    int info;
    Node link;
}

public class SwapNode {

    static Node first = null;
    
    static void insertAtFirst(int x){
        Node newNode = new Node();

        newNode.info = x;
        newNode.link = first;

        first = newNode;
    }

    static void display(){
        Node save = first;

        if(first == null){
            System.out.println("List is empty!!");
            return;
        }

        while(save != null){
            System.out.print(save.info + "->");
            save = save.link;
        }

        System.out.println("null");
    }

    static void Swap(){
        Node save = first;
        Node second;
        Node third;

        first = save.link;

        while(save != null && save.link != null){

            third = save.link.link;
            second = save.link ;
            second.link = save;

            if(third != null && third.link != null){
                save.link = third.link;
            }
            else{
                save.link = third;
            }
            save = third;
        }
    }

    public static void main(String[] args) {
        
        insertAtFirst(8);
        insertAtFirst(7);
        insertAtFirst(6);
        insertAtFirst(5);
        insertAtFirst(4);
        insertAtFirst(3);
        insertAtFirst(2);
        insertAtFirst(1);

        display();

        Swap();

        display();

    }
}
