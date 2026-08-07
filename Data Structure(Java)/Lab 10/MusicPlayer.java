// Write a program to simulate music player application using suitable data 
// structure. There is no estimation about number of music files to be managed by 
// the music player. Your program should support all the basic music player 
// operations to play and manage the playlist. 

class Node{
    String info;
    Node lptr;
    Node rptr;
}

public class MusicPlayer{

    static Node first = null;

    static void InsertAtFirst(String title){
        Node newNode = new Node();

        if(first == null){
            newNode.info = title;
            newNode.lptr = null;
            newNode.rptr = null;

            first = newNode;
        }
        else{
            newNode.info = title;
            newNode.lptr = null;
            newNode.rptr = first;
            first.lptr = newNode;

            first = newNode;
        }
    }

    static void Display(){
        if(first == null){
            System.out.println("Empty List!!");
            return;
        }

        Node save = first;

        while (save != null) {
            System.out.print(save.info + "->");
            save = save.rptr;
        }
        System.out.println("null");
    }

    static void PlayPrevious(){
        Node save = first;

        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        if(save == first){
            System.out.println("No songs available.");
        }
        else{
            save = save.lptr;
            System.out.println("Playing previous :" + save.info);
        }
    }

    static void PlayNext(){
        Node save = first;

        if(first == null){
            System.out.println("Empty List !!");
            return;
        }

        if(save != null){
            save = save.rptr;
            System.out.println("Playing next :" + save.info);
        }
        else{
            System.out.println("No songs available.");
        }
    }

    public static void main(String[] args) {
        
        InsertAtFirst("Preet re");
        InsertAtFirst("Bairan");
        InsertAtFirst("Prem ki lila");
        InsertAtFirst("Ishq hai");

        Display();

        PlayNext();

        PlayPrevious();
        }
    }

    