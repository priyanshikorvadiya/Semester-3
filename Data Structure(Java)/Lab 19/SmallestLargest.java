// WAP to find the smallest and largest elements in the Binary Search Tree.

class TreeNode{
    int key;
    TreeNode left;
    TreeNode right;
}

public class SmallestLargest {

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

    static int FindMax(TreeNode root){
        TreeNode save = root;

        while(save.right != null){
            save = save.right;
        }
        return save.key;
    }

    static int FindMin(TreeNode root){
        TreeNode save = root;

        while(save.left != null){
            save = save.left;
        }
        return save.key;
    }

    public static void main(String[] args) {
        
        TreeNode tree = null;
        tree = Insert(tree, 8);
        tree = Insert(tree, 6);
        tree = Insert(tree, 5);
        tree = Insert(tree, 4);
        tree = Insert(tree, 3);
        tree = Insert(tree, 2);

        int min = FindMin(tree);
        int max = FindMax(tree);

        System.out.println("Smallest value is :" + min);
        System.out.println("Largest value is :" + max);
    }
}
