// Write a program to implement a node structure for singly linked list. Read the 
//data in a node, print the node. 

class Node {

    int info;
    Node link;

    Node(int info){
        this.info = info;
        this.link = null;
    }
}

public class NodeStructure {
    public static void main(String[] args) {
        
        Node node1 = new Node(1);

        System.out.println(node1.info);
        System.out.println(node1.link);
    }
}
