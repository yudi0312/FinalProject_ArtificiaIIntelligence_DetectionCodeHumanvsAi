// ============================================================
// 05 - Insert Node at End
// Adds a new node to the tail of the list.
// Requires traversal to the last node — O(n) time,
// or O(1) if a tail pointer is maintained.
// ============================================================

public class InsertNodeEnd {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with tail pointer for O(1) end insertion ---
    static class LinkedList {
        Node head;
        Node tail; // Keeping track of the last node avoids full traversal

        // Insert a new node at the END of the list
        // Algorithm:
        //   1. Create the new node.
        //   2. If list is empty, set head and tail to the new node.
        //   3. Otherwise, link the current tail to the new node,
        //      then update the tail pointer.
        void insertAtEnd(int data) {
            Node newNode = new Node(data);

            // Empty list case
            if (head == null) {
                head = newNode;
                tail = newNode;
                return;
            }

            // Link the current last node to the new node
            tail.next = newNode;

            // Move tail to the new last node
            tail = newNode;
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
            System.out.println("Tail: " + (tail != null ? tail.data : "none"));
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insertAtEnd(10);
        list.display();
        // Output: List: 10 -> null | Tail: 10

        list.insertAtEnd(20);
        list.display();
        // Output: List: 10 -> 20 -> null | Tail: 20

        list.insertAtEnd(30);
        list.insertAtEnd(40);
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> null | Tail: 40
    }
}
