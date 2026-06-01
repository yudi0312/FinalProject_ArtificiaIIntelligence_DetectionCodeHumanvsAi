// ============================================================
// 02 - Doubly Linked List
// Each node holds data, a reference to the next node, and
// a reference to the previous node. Allows traversal in
// both forward and backward directions.
// ============================================================

public class DoublyLinkedList {

    // --- Node definition ---
    // Each node stores a value and points to both neighbors.
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

    // --- Doubly Linked List definition ---
    static class DLinkedList {
        Node head; // First node
        Node tail; // Last node

        // Insert a new node at the end of the list
        void insert(int data) {
            Node newNode = new Node(data);

            // If the list is empty, the new node is both head and tail
            if (head == null) {
                head = newNode;
                tail = newNode;
                return;
            }

            // Link the new node after the current tail
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode; // Update tail to the new node
        }

        // Print all elements from head to tail (forward direction)
        void displayForward() {
            Node current = head;
            System.out.print("Forward: ");
            while (current != null) {
                System.out.print(current.data + " <-> ");
                current = current.next;
            }
            System.out.println("null");
        }

        // Print all elements from tail to head (backward direction)
        void displayBackward() {
            Node current = tail;
            System.out.print("Backward: ");
            while (current != null) {
                System.out.print(current.data + " <-> ");
                current = current.prev;
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

        list.displayForward();
        // Output: Forward: 10 <-> 20 <-> 30 <-> 40 <-> null

        list.displayBackward();
        // Output: Backward: 40 <-> 30 <-> 20 <-> 10 <-> null
    }
}
