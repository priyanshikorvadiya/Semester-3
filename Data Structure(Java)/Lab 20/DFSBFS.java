// Write a program to create a graph & implement the adjacency list 
// representation of the graph 
//  Apply DFS and BFS on the given graph.

class Node{
    int info;
    Node link;
}

public class DFSBFS {
    static int Max = 20;
    static Node F = null;
    static Node R = null;
    
    static void ENQUEUE(int x){
        Node newNode = new Node();

        newNode.info = x;
        newNode.link = null;

        if(R == null){
            F = R = newNode;
        }
        else{
            R.link = newNode;
            R = newNode;
        }
    }

    static int DEQUEUE(){
        if(F == null){
            System.out.println("Queue underflow!");
            return -1;
        }
        else{
            int val = F.info;
            F = F.link;

            if(F == null){
                R = null;
            }

            return val;
        }
    }

    static Node adjList[] = new Node[Max];
    static int v;

    static void addEdge(int src, int dest){
        //Add dest to src
        Node newNode = new Node();

        newNode.info = dest;
        newNode.link = adjList[src];

        adjList[src] = newNode;

        newNode = new Node();

        newNode.info = src;
        newNode.link = adjList[dest];

        adjList[dest] = newNode;
    }

    static void DFS(int v, int visited[]){
        visited[v] = 1;

        System.out.println(v);
        
        Node save = adjList[v];

        while (save != null) {
            if(visited[save.info] == 0){
                DFS(save.info, visited);
            }
            save = save.link;
        }

    }

    static void BFS(int start){
        int visited[] = new int[Max];

        visited[start] = 1;
        ENQUEUE(start);

        while(F != null){
            int v = DEQUEUE();
            System.out.println(v);

            Node save = adjList[v];

            while(save != null){
                if(visited[save.info] == 0){
                    visited[save.info] = 1;
                    ENQUEUE(save.info);
                }
                save = save.link;
            }
        }
    }

    static void Display(int i){
        Node save = adjList[i];

        while(save != null){
            System.out.print(save.info + "->");
            save = save.link;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        
    for(int i = 0; i < Max; i++) {
        adjList[i] = null;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    System.out.println("Adjacency List:");
    for(int i = 0; i < 4; i++){ 
        Display(i);
    }

    int visited[] = new int[Max]; 
    System.out.println("DFS Traversal:");
    DFS(0, visited);

    System.out.println("\nBFS Traversal:\n");
    BFS(0);
    System.out.println();
    }
}
