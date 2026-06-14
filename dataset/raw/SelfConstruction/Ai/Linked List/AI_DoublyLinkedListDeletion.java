// ============================================================
// 18 - Doubly Linked List Deletion
// In a doubly linked list, deletion is more efficient because
// each node knows its previous neighbor, so no separate
// "previous pointer" traversal is needed.
// Handles: delete head, delete tail, delete middle node.
// Time Complexity: O(n) to find, O(1) to remove
// ============================================================

public class DoublyLinkedListDeletion {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;
        Node prev;

        Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    // --- Doubly Linked List with deletion operations ---
    static class DLinkedList {
        Node head;
        Node tail;

        // Insert at end for building the list
        void insert(int data) {
            Node newNode = new Node(data);

            if (head == null) {
                head = newNode;
                tail = newNode;
                return;
            }

            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }

        // Delete the first occurrence of a node with the given value
        // Algorithm:
        //   1. Find the target node by traversing from head.
        //   2. Update the previous node's next pointer.
        //   3. Update the next node's prev pointer.
        //   4. Handle edge cases: deleting head or tail.
        void delete(int target) {
            Node current = head;

            // Search for the target node
            while (current != null) {
                if (current.data == target) {
                    break; // Found the node to delete
                }
                current = current.next;
            }

            // Target not found
            if (current == null) {
                System.out.println("Value " + target + " not found.");
                return;
            }

            // Case 1: Node to delete is the head
            if (current == head) {
                head = head.next;
                if (head != null) {
                    head.prev = null; // New head has no predecessor
                } else {
                    tail = null; // List is now empty
                }
            }
            // Case 2: Node to delete is the tail
            else if (current == tail) {
                tail = tail.prev;
                if (tail != null) {
                    tail.next = null; // New tail has no successor
                } else {
                    head = null; // List is now empty
                }
            }
            // Case 3: Node to delete is in the middle
            else {
                // Link previous node directly to the node after current
                current.prev.next = current.next;
                // Link next node back to the node before current
                current.next.prev = current.prev;
            }

            System.out.println("Deleted: " + target);
        }

        // Print forward
        void displayForward() {
            Node current = head;
            System.out.print("Forward: ");
            while (current != null) {
                System.out.print(current.data + " <-> ");
                current = current.next;
            }
            System.out.println("null");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        DLinkedList list = new DLinkedList();

        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);

        list.displayForward();
        // Output: Forward: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> null

        list.delete(30); // Delete middle
        list.displayForward();
        // Output: Forward: 10 <-> 20 <-> 40 <-> 50 <-> null

        list.delete(10); // Delete head
        list.displayForward();
        // Output: Forward: 20 <-> 40 <-> 50 <-> null

        list.delete(50); // Delete tail
        list.displayForward();
        // Output: Forward: 20 <-> 40 <-> null

        list.delete(99); // Value not present
        // Output: Value 99 not found.
    }
}
