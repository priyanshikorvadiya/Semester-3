//  Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
//  Insert a node 
//  Delete a node 
//  Search a node 
//  Preorder Traversal 
//  Postorder Traversal 
//  Inorder Traversal

import java.util.Scanner;

class TreeNode{
    int key;
    TreeNode left;
    TreeNode right;
}

public class TreeOperations {
    
    //Function to create new node

    static TreeNode CreateNode(int x){
        TreeNode root = new TreeNode();

        root.key = x;
        root.left = null;
        root.right = null;

        return root;
    }

    static TreeNode Insert(TreeNode root, int val){
        if(root == null){
            return CreateNode(val);
        }

        if(root.key == val){
            return root;
        }

        else if(root.key < val){
            root.right = Insert(root.right, val);
        }

        else{
            root.left = Insert(root.left, val);
        }

        return root;
    }

    //Additional function to find min value from given tree
    static TreeNode Min(TreeNode root){
        TreeNode save = root;

        while(save != null && save.left != null){
            save = save.left;
        }

        return save;
    }

    static TreeNode Delete(TreeNode root, int key){
        if(root == null){
            System.out.println("Value not found!");
            return null;
        }

        if(key < root.key){
            root.left = Delete(root.left, key);
        }

        else if(key > root.key){
            root.right = Delete(root.right, key);
        }

        else{//root->key = key
            if(root.left == null){
                return root.right;
            }
            else if(root.right == null){
                return root.left;
            }

            TreeNode temp = Min(root.right);
            root.key = temp.key;

            root.right = Delete(root.right, temp.key);
        }
        return root;
    }

    static TreeNode Search(TreeNode root, int key){
        if(root == null || root.key == key){
            return root;
        }

        if(root.key < key){
            return Search(root.right, key);
        }
        return Search(root.left, key);
    }

    static void Inorder(TreeNode root){
        if(root != null){
            Inorder(root.left);
            System.out.println(root.key);
            Inorder(root.right);
        }
    }

    static void Preorder(TreeNode root){
        if(root != null){
            System.out.println(root.key);
            Preorder(root.left);
            Preorder(root.right);
        }
    }

    static void Postorder(TreeNode root){
        if(root != null){
            Postorder(root.left);
            Postorder(root.right);
            System.out.println(root.key);
        }
    }

    public static void main(String[] args) {
        TreeNode root = null;
        int choice, val;
        TreeNode searchResult = null;
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n------- BST MENU -------");
            System.out.println("1. Insert a node");
            System.out.println("2. Delete a node");
            System.out.println("3. Search a node");
            System.out.println("4. Preorder Traversal");
            System.out.println("5. Inorder Traversal");
            System.out.println("6. Postorder Traversal");
            System.out.println("7. Exit Program");
            System.out.print("Enter your choice (1-7): ");
            
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert: ");
                    val = sc.nextInt();
                    root = Insert(root, val);
                    System.out.println("Node inserted successfully.");
                    break;

                case 2:
                    System.out.print("Enter value to delete: ");
                    val = sc.nextInt();
                    root = Delete(root, val);
                    break;

                case 3:
                    System.out.print("Enter value to search: ");
                    val = sc.nextInt();
                    searchResult = Search(root, val);
                    if (searchResult != null) {
                        System.out.println("Value " + val + " found in the tree.");
                    } else {
                        System.out.println("Value " + val + " NOT found in the tree.");
                    }
                    break;

                case 4:
                    System.out.print("Preorder Traversal: ");
                    Preorder(root);
                    System.out.println();
                    break;

                case 5:
                    System.out.print("Inorder Traversal: ");
                    Inorder(root);
                    System.out.println();
                    break;

                case 6:
                    System.out.print("Postorder Traversal: ");
                    Postorder(root);
                    System.out.println();
                    break;

                case 7:
                    System.out.println("Exiting code execution pipeline...");
                    sc.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice! Please select between 1 and 7.");
            }
        }
    }
}