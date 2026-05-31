// ============================================================
// 15 - Count Nodes in a Linked List
// Two approaches:
//   1. Iterative: traverse the list and count each node.
//   2. Recursive: count by recursing to the end, then adding 1
//      per call on the way back.
// Time Complexity: O(n) for both | Space: O(1) iter, O(n) recur
// ============================================================

public class CountNodes {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with node-counting operations ---
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

        // --- Method 1: Iterative Count ---
        // Traverse from head to null, incrementing a counter at each node.
        int countIterative() {
            int count = 0;
            Node current = head;

            while (current != null) {
                count++;
                current = current.next;
            }

            return count;
        }

        // --- Method 2: Recursive Count ---
        // Base case: null means 0 nodes remain.
        // Recursive case: 1 (for current node) + count of remaining nodes.
        int countRecursive(Node current) {
            if (current == null) {
                return 0; // No more nodes
            }
            return 1 + countRecursive(current.next); // Count this node plus the rest
        }

        // Print all elements
        void display() {
            Node current = head;
            System.out.print("List: ");
            while (current != null) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }
            System.out.println("null");
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
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> 50 -> null

        int iterativeCount = list.countIterative();
        System.out.println("Count (iterative): " + iterativeCount);
        // Output: Count (iterative): 5

        int recursiveCount = list.countRecursive(list.head);
        System.out.println("Count (recursive): " + recursiveCount);
        // Output: Count (recursive): 5

        // Empty list
        LinkedList emptyList = new LinkedList();
        System.out.println("Empty list count: " + emptyList.countIterative());
        // Output: Empty list count: 0
    }
}
