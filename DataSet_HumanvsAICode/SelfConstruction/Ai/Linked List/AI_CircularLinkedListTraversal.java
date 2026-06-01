// ============================================================
// 17 - Circular Linked List Traversal
// Demonstrates traversal methods specific to a circular list:
//   1. Traverse exactly once (do-while loop stops at head).
//   2. Traverse N full rotations (useful for round-robin logic).
//   3. Count nodes in the circular list.
// ============================================================

public class CircularLinkedListTraversal {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Circular Linked List with traversal operations ---
    static class CLinkedList {
        Node head;

        // Insert a new node at the end (last node points to head)
        void insert(int data) {
            Node newNode = new Node(data);

            if (head == null) {
                head = newNode;
                newNode.next = head; // Points to itself
                return;
            }

            // Find the current last node
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }

            // Append and maintain the circular link
            current.next = newNode;
            newNode.next = head;
        }

        // --- Method 1: Single-Pass Traversal ---
        // Uses a do-while loop to visit each node exactly once.
        // Starts at head and stops when we loop back to head.
        void traverseOnce() {
            if (head == null) {
                System.out.println("List is empty.");
                return;
            }

            System.out.print("Single Pass: ");
            Node current = head;

            do {
                System.out.print(current.data + " -> ");
                current = current.next;
            } while (current != head); // Stop when back at head

            System.out.println("(head: " + head.data + ")");
        }

        // --- Method 2: Multi-Rotation Traversal ---
        // Traverses the circular list a given number of full rotations.
        // Useful for round-robin scheduling simulations.
        void traverseNRotations(int numberOfRotations) {
            if (head == null) return;

            System.out.print("Traversal x" + numberOfRotations + ": ");
            Node current = head;
            int nodeCount = countNodes();
            int totalSteps = nodeCount * numberOfRotations;

            for (int step = 0; step < totalSteps; step++) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }

            System.out.println("...");
        }

        // --- Method 3: Count Nodes ---
        // Counts how many nodes are in the circular list.
        int countNodes() {
            if (head == null) return 0;

            int count = 1; // Start counting from head
            Node current = head.next;

            while (current != head) {
                count++;
                current = current.next;
            }

            return count;
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        CLinkedList list = new CLinkedList();

        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);

        // Single traversal
        list.traverseOnce();
        // Output: Single Pass: 10 -> 20 -> 30 -> 40 -> 50 -> (head: 10)

        // Multi-rotation traversal (2 full loops)
        list.traverseNRotations(2);
        // Output: Traversal x2: 10 -> 20 -> 30 -> 40 -> 50 -> 10 -> 20 -> 30 -> 40 -> 50 -> ...

        // Count nodes
        System.out.println("Node count: " + list.countNodes());
        // Output: Node count: 5
    }
}
