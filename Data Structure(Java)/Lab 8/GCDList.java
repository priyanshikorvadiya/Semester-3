//WAP to perform given operation in the linked list. There exist a Linked List. Add 
//a node that contains the GCD of those two nodes between every pair adjacent 
//node of Linked List. 

//Input : 18 ----> 6 ----> 10 ----> 3
//Output : 18 --> 6 --> 6 --> 2 --> 10 --> 1 --> 3

class Node{
    int info;
    Node link;
}

public class GCDList{

    static Node first = null;

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

    static int min(int a,int b){
        if(a > b){
            return a;
        }
        else{
            return b;
        }
    }

    static int find_gcd(int a, int b){
        
        for(int i = min(a, b) ; i >= 1 ; i--){
            if(a % i == 0 && b % i == 0){
                return i;
            }
        }
        return 1;
    }

    static void GCD(){
        if(first == null || first.link == null){
            return;
        }

        Node save = first;

        while(save.link != null){
            Node newNode = new Node();
 
            newNode.info = find_gcd(save.info, save.link.info);
            newNode.link = save.link;
            save.link = newNode;

            //To jump on third Node

            save = save.link.link;
        }
    }
    public static void main(String[] args) {
        
        InsertAtFirst(3);
        InsertAtFirst(10);
        InsertAtFirst(6);
        InsertAtFirst(18);

        Display();

        GCD();

        Display();
    }
}