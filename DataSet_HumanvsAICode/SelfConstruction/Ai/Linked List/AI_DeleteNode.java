// ============================================================
// 06 - Delete Node
// Removes a node with a given value from the linked list.
// Handles: deleting the head, a middle node, or the last node.
// Time Complexity: O(n)
// ============================================================

public class DeleteNode {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with delete operation ---
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

        // Delete the first occurrence of a node with the given value
        // Algorithm:
        //   1. If head holds the target value, move head forward.
        //   2. Otherwise, traverse the list keeping track of the
        //      previous node.
        //   3. When found, skip over the target node by linking
        //      previous.next to target.next.
        void delete(int target) {
            // Case 1: List is empty
            if (head == null) {
                System.out.println("List is empty. Cannot delete " + target);
                return;
            }

            // Case 2: Head node holds the target value
            if (head.data == target) {
                head = head.next; // Move head to the next node
                System.out.println("Deleted: " + target);
                return;
            }

            // Case 3: Search through the rest of the list
            Node previous = head;
            Node current = head.next;

            while (current != null) {
                if (current.data == target) {
                    // Bypass the current node
                    previous.next = current.next;
                    System.out.println("Deleted: " + target);
                    return;
                }
                previous = current;
                current = current.next;
            }

            // Node not found
            System.out.println("Value " + target + " not found in the list.");
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

        list.delete(30); // Delete middle node
        list.display();
        // Output: List: 10 -> 20 -> 40 -> 50 -> null

        list.delete(10); // Delete head
        list.display();
        // Output: List: 20 -> 40 -> 50 -> null

        list.delete(50); // Delete tail
        list.display();
        // Output: List: 20 -> 40 -> null

        list.delete(99); // Delete non-existent value
        // Output: Value 99 not found in the list.
    }
}
