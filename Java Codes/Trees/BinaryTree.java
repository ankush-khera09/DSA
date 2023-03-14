import java.util.*;

public class BinaryTree{

    static class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            this.left = this.right = null;
        }
    }

    static class BinTree{
        static int index = -1;
        public static Node createTree(int nodes[]){
            index++;
            if(nodes[index]==-1) return null;

            Node newNode = new Node(nodes[index]);
            newNode.left = createTree(nodes);
            newNode.right = createTree(nodes);

            return newNode;
        }

        // static void PreOrder()
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        int nodes[] = {1,2,4,-1,-1,5,-1,3,-1,6,-1,-1};

        BinTree bt = new BinTree();
        Node root = bt.createTree(nodes);
        System.out.println(root.data);
    }
}