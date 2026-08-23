//  Given a binary tree, determine if it is height-balanced (A height-balanced binary 
// tree is a binary tree in which the depth of the two subtrees of every node never 
// differs by more than one).

import java.util.Scanner;

class TreeNode{
    int key;
    TreeNode left;
    TreeNode right;
}

public class HeightBalanced {

    //Function to create new node

    static TreeNode CreateNode(int x){
        TreeNode root = new TreeNode();

        root.key = x;
        root.left = null;
        root.right = null;

        return root;
    }

    static TreeNode Insert(TreeNode root, Scanner sc){

        System.out.print("Enter data(-1 for no node) :");
        int data = sc.nextInt();

        if(data == -1){
            return null;
        }
        
        TreeNode newNode = CreateNode(data);

        System.out.println("Enter data for left branch of the tree :");
        newNode.left = Insert(newNode.left, sc);

        System.out.println("Enter data for right branch of the tree :");
        newNode.right = Insert(newNode.right, sc);

        return newNode;
    }

    static int max(int n1, int n2){
        if(n1 > n2){
            return n1;
        }
        return n2;
    }

    static int findHeight(TreeNode root){
        if(root == null){
            return 0;
        }

        int lefth = findHeight(root.left);
        int righth = findHeight(root.right);

        return (max(lefth, righth)) + 1;
    }

    static boolean IsHeightBalanced(TreeNode root){
        if(root == null){
            return true;
        }

        int h1 = findHeight(root.left);
        int h2 = findHeight(root.right);

        if(Math.abs(h1 - h2) > 1){
            return false;
        }

        boolean isLeftBalanced = IsHeightBalanced(root.left);
        boolean isRightBalanced = IsHeightBalanced(root.right);

        return isLeftBalanced && isRightBalanced;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        TreeNode tree = null;

        tree = Insert(tree, sc);

        boolean res = IsHeightBalanced(tree);

        if(res == true){
            System.out.println("Given tree is height balanced.");
        }
        else{
            System.out.println("Given tree is not height balanced.");
        }
    }
}