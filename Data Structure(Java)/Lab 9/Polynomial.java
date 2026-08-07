// Write a program to perform addition of two polynomial equations using 
// appropriate data structure.

class Node{
    int pow;
    int info;
    Node link;
}

public class Polynomial {

    static Node first1 = null;
    static Node first2 = null;
    static Node result = null;
    
    static Node InsertAtFirst(int y,int x,Node first){

        Node newNode = new Node();

        newNode.pow = y;
        newNode.info = x;
        newNode.link = first;

        first = newNode;

        return first;
    }

    static void PolyAdd(){
        Node temp1 = first1;
        Node temp2 = first2;
        Node revres = null;

        while(temp1 != null && temp2 != null){

            if(temp1.pow > temp2.pow){
                revres = InsertAtFirst(temp1.pow, temp1.info, revres);
                temp1 = temp1.link;
            }

            else if(temp1.pow < temp2.pow){
                revres = InsertAtFirst(temp2.pow, temp2.info, revres);
                temp2 = temp2.link;
            }

            else{
                revres = InsertAtFirst(temp1.pow, temp1.info + temp2.info, revres);
                temp1 = temp1.link;
                temp2 = temp2.link;
            }

            while (temp1 != null) {
                revres = InsertAtFirst(temp1.pow, temp1.info, revres);
                temp1 = temp1.link;
            }

            while (temp2 != null) {
                revres = InsertAtFirst(temp2.pow, temp2.info, revres);
                temp2 = temp2.link;
            }

            //Output is in reverse order because we have used insertatfirst
            //Below process will convert it in proper order

            Node save = revres;

            while(save != null){
                result = InsertAtFirst(save.pow,save.info,result);
                save = save.link;
            }
        }
    }

    static void Display(Node first){
        if(first == null){
            System.out.println("List is Empty!!");
            return;
        }

        Node save = first;

        while(save != null){
            System.out.print(save.info + " x^ " + save.pow );

            if(save.link != null){
                if(save.info >= 0){
                    System.out.print("+");
                }
                else{
                    System.out.print(" ");
                }
            }
            save = save.link;

            System.out.println();
        }
    }

    public static void main(String[] args) {
        
    first1 = InsertAtFirst(4,1,first1);
    first1 = InsertAtFirst(3,2,first1);

    System.out.println("Polynomial 1 :\n");
    Display(first1);

    first2 = InsertAtFirst(3,1,first2);

    System.out.println("Polynomial 2 :\n");
    Display(first2);

    System.out.println("Result : \n");
    PolyAdd();
    Display(result);

    }
}
