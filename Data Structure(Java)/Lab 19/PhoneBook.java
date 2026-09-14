// Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations: 
//  Add new entry in phone book,  
//  Remove entry from phone book,  
//  Search phone number  
//  List all entries in ascending order of name and 
//  List all entries in descending order of name

import java.util.Scanner;

class TreeNode{
    String name;
    String phone;
    TreeNode left;
    TreeNode right;
}

public class PhoneBook {
    
    //Function to create new node

    static TreeNode CreateNode(String name,String phone){
        TreeNode root = new TreeNode();

        root.name = name;
        root.phone = phone;
        root.left = null;
        root.right = null;

        return root;
    }

    static TreeNode Insert(TreeNode root, String name, String phone){
        if(root == null){
            return CreateNode(name , phone);
        }

        int strcmp = root.name.compareTo(name);

        if(strcmp == 0){
            return root;
        }

        else if(strcmp > 0){
            root.left = Insert(root.left, name , phone);
        }
        
        else{
            root.right = Insert(root.right, name , phone);
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

    static TreeNode Delete(TreeNode root,String name){

        if(root == null){
            System.out.println("Value not found!!");
            return root;
        }

        int strcmp = root.name.compareTo(name);

        if(strcmp < 0){
            root.left = Delete(root.left, name);
        }

        else if(strcmp > 0){
            root.right = Delete(root.right, name);
        }

        else{//root.key = key
            if(root.left == null){
                TreeNode save = root.right;

                return save;
            }
            else if(root.right == null){
                TreeNode save = root.left;

                return save;
            }

            TreeNode temp = Min(root.right);
            root.name = temp.name;
            root.phone = temp.phone;

            root.right = Delete(root.right,temp.name);
        }
        return root;
    }

    //Function to search

    static TreeNode Search(TreeNode root, String phone){
        if(root == null){
            return root;
        }

        int strcmp = root.phone.compareTo(phone);

        if(strcmp > 0){
            return Search(root.right, phone);
        }
        return Search(root.left, phone);
    }

    //Ascending 

    static void Ascending(TreeNode root){
        if(root != null){
            Ascending(root.right);
            System.out.print(root.name + " -> ");
            System.out.println(root.phone);
            Ascending(root.left);
        }
    }

    //Descending
    
    static void Descending(TreeNode root){
        if(root != null){
            Descending(root.left);
            System.out.print(root.name + " -> ");
            System.out.println(root.phone);
            Descending(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
            TreeNode root = null;
            int choice;
            String name = null;
            String phone = null;

            while (true) {
                System.out.println();
                System.out.println("--- Phone Book Dictionary Menu ---");
                System.out.println("1. Add new entry");
                System.out.println("2. Remove entry");
                System.out.println("3. Search ");
                System.out.println("4. List entries in ascending order");
                System.out.println("5. List entries in descending order");
                System.out.println("6. Exit");
                System.out.print("Enter your choice: ");

                if (!sc.hasNextInt()) {
                    break;
                }

                choice = sc.nextInt();

                switch (choice) {
                    case 1: {
                        System.out.print("Enter name: ");
                        name = sc.next();

                        System.out.print("Enter phone number: ");
                        phone = sc.next();

                        root = Insert(root, name, phone);
                        break;
                    }

                    case 2: {
                        System.out.print("Enter name to remove: ");
                        name = sc.next();

                        root = Delete(root, name);
                        break;
                    }

                    case 3: {
                        System.out.print("Enter name to search: ");
                        name = sc.next();

                        TreeNode searchResult = Search(root, name);

                        if (searchResult != null) {
                            System.out.println("Value found in the tree.");
                        } else {
                            System.out.println("Value NOT found in the tree.");
                        }
                        break;
                    }

                    case 4: {
                        System.out.println();
                        System.out.println("--- Phone Book Entries (A to Z) ---");
                        Ascending(root);
                        break;
                    }

                    case 5: {
                        System.out.println();
                        System.out.println("--- Phone Book Entries (Z to A) ---");
                        Descending(root);
                        break;
                    }

                    case 6: {
                        System.out.println("Exiting program.");
                        return;
                    }

                    default: {
                        System.out.println("Invalid choice! Please try again.");
                        break;
                    }
                }
            }
            sc.close();
        }
    }
