public class TreeSearch {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Searches for a target integer key within a BST structure.
     */
    public boolean search(Node root, int key) {
        // Base Case: Not found (null) or Exact Match Found
        if (root == null) return false;
        if (root.data == key) return true;

        // Route left if target key is smaller; route right if larger
        if (key < root.data) {
            return search(root.left, key);
        }
        return search(root.right, key);
    }

    public static void main(String[] args) {
        TreeSearch bst = new TreeSearch();
        Node root = new Node(50);
        root.left = new Node(25);
        root.right = new Node(75);

        System.out.println("Searching for 25: " + bst.search(root, 25)); // Expected: true
        System.out.println("Searching for 99: " + bst.search(root, 99)); // Expected: false
    }
}