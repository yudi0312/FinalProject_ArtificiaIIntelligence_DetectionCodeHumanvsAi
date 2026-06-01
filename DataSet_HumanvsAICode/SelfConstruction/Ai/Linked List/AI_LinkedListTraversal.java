// ============================================================
// 13 - Linked List Traversal
// Demonstrates multiple ways to visit each node in a list:
//   1. Iterative traversal (standard loop)
//   2. Recursive traversal (forward)
//   3. Recursive traversal (reverse/backward printing)
// Time Complexity: O(n) for all methods
// ============================================================

public class LinkedListTraversal {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with traversal methods ---
    static class LinkedList {
        Node head;

        // Insert at end for building the list
        void insert(int data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                return;
            }
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }

        // --- Method 1: Iterative Traversal ---
        // Visits each node using a loop starting from head.
        void traverseIterative() {
            System.out.print("Iterative: ");
            Node current = head;

            while (current != null) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }

            System.out.println("null");
        }

        // --- Method 2: Recursive Traversal (Forward) ---
        // Visits each node by calling itself on the next node.
        void traverseRecursiveForward(Node current) {
            if (current == null) {
                System.out.println("null");
                return;
            }
            System.out.print(current.data + " -> ");
            traverseRecursiveForward(current.next); // Recurse on next node
        }

        // --- Method 3: Recursive Traversal (Backward / Reverse Print) ---
        // Recurses all the way to the tail first, then prints on the way back.
        void traverseRecursiveBackward(Node current) {
            if (current == null) {
                return;
            }
            traverseRecursiveBackward(current.next); // Go to the end first
            System.out.print(current.data + " -> "); // Print on the way back
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);

        // Iterative traversal
        list.traverseIterative();
        // Output: Iterative: 10 -> 20 -> 30 -> 40 -> 50 -> null

        // Recursive forward traversal
        System.out.print("Recursive Forward: ");
        list.traverseRecursiveForward(list.head);
        // Output: Recursive Forward: 10 -> 20 -> 30 -> 40 -> 50 -> null

        // Recursive backward traversal (prints in reverse order)
        System.out.print("Recursive Backward: ");
        list.traverseRecursiveBackward(list.head);
        System.out.println("null");
        // Output: Recursive Backward: 50 -> 40 -> 30 -> 20 -> 10 -> null
    }
}
