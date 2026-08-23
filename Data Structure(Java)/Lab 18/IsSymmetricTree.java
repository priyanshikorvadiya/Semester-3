// Write a program to check whether the given two trees are symmetric or not.

import java.util.Scanner;

class TreeNode{
    int key;
    TreeNode left;
    TreeNode right;
}

public class IsSymmetricTree {

    //Function to create new node

    static TreeNode CreateNode(int x){
        TreeNode root = new TreeNode();

        root.key = x;
        root.left = null;
        root.right = null;

        return root;
    }

    static TreeNode Insert(TreeNode root , Scanner sc){

        System.out.println("Enter data(-1 for no node):");
        int data = sc.nextInt();

        if(data == -1){
            return null;
        }

        TreeNode newNode = CreateNode(data);

        System.out.println("Enter data for left branch of tree:");
        newNode.left = Insert(newNode.left , sc);

        System.out.println("Enter data for right branch of tree:");
        newNode.right = Insert(newNode.right , sc);

        return newNode;
    }

    static boolean IsSame(TreeNode r1, TreeNode r2){
        if(r1 == null && r2 == null){
            return true;
        }

        else if(r1 == null || r2 == null){
            return false;
        }

        return (r1.key == r2.key) && IsSame(r1.left, r2.right) && IsSame(r1.right, r2.left);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        boolean res;

        System.out.println("Build Tree1 :");
        TreeNode tree1 = null;
        tree1 = Insert(tree1 , sc);

        System.out.println("Build Tree2 :");
        TreeNode tree2 = null;
        tree2 = Insert(tree2 , sc);

        res = IsSame(tree1, tree2);

        if(res == true){
            System.out.println("Given trees are symmetric.");
        }
        else{
            System.out.println("Given trees are not symmetric!!");
        }

        sc.close();
    }
}
