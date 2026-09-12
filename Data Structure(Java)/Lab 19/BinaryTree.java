//Write a program to construct a binary tree from given Postorder and Preorder 
//traversal sequence.

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
}

public class BinaryTree {
    static TreeNode root = null;

    static int preindex = 0;

    static TreeNode CreateNode(int data){
        TreeNode newNode = new TreeNode();

        newNode.data = data;
        newNode.left = null;
        newNode.right = null;

        return  newNode;
    }

    static TreeNode CreateBinaryTree(int[] pre, int[] post, int l, int h, int size){
        if(preindex >= size || l > h){
            return null;
        }

        TreeNode node = CreateNode(pre[preindex]);
        preindex++;

        if(l == h || preindex >= size){
            return node;
        }

        int i;
        for(i = 0 ; i <= h ; i++){
            if(post[i] == pre[preindex]){
                break;
            }
        }

        if(i <= h){
            node.left = CreateBinaryTree(pre, post, l, i, size);
            node.right = CreateBinaryTree(pre, post, i + 1, h - 1, size);
        }

        return  node;
    }

    static TreeNode ConstructFinalBinaryTree(int[] pre, int post[], int size){
        return CreateBinaryTree(pre, post, 0, size - 1, size);
    }

    static void Inorder(TreeNode root){
        if(root != null){
            Inorder(root.left);
            System.out.print(root.data);
            Inorder(root.right);
        }
    }

    public static void main(String[] args) {
        int pre[] = {1, 2, 4, 5, 3, 6, 7};
        int post[] = {4, 5, 2, 6, 7, 3, 1};

        int size = pre.length;

        root = ConstructFinalBinaryTree(pre, post, size);

        Inorder(root);

        System.out.println();
    }
}
