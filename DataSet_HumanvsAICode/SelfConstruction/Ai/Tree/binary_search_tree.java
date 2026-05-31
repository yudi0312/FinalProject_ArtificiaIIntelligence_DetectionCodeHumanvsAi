public class BinarySearchTreeCore {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    private Node root;

    // Helper method to display elements using a simple inline system
    public void printRoot() {
        if (root != null) {
            System.out.println("BST Core created. Root element is: " + root.data);
        }
    }

    public static void main(String[] args) {
        BinarySearchTreeCore bst = new BinarySearchTreeCore();
        // Constructing a valid BST structure manually
        bst.root = new Node(20);
        bst.root.left = new Node(10);
        bst.root.right = new Node(30);

        bst.printRoot();
    }
}