// ============================================================
// 04 - Insert Node at Beginning
// Adds a new node to the front of the list in O(1) time.
// The new node becomes the new head of the list.
// ============================================================

public class InsertNodeBeginning {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with insert-at-beginning operation ---
    static class LinkedList {
        Node head;

        // Insert a new node at the BEGINNING of the list
        // Algorithm:
        //   1. Create the new node.
        //   2. Point the new node's next to the current head.
        //   3. Update head to the new node.
        void insertAtBeginning(int data) {
            Node newNode = new Node(data);

            // New node points to the current head
            newNode.next = head;

            // New node is now the head
            head = newNode;
        }

        // Also support end insertion for building the initial list
        void insertAtEnd(int data) {
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

        // Build initial list: 30 -> 40 -> 50
        list.insertAtEnd(30);
        list.insertAtEnd(40);
        list.insertAtEnd(50);
        list.display();
        // Output: List: 30 -> 40 -> 50 -> null

        // Insert at beginning
        list.insertAtBeginning(20);
        list.display();
        // Output: List: 20 -> 30 -> 40 -> 50 -> null

        list.insertAtBeginning(10);
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> 50 -> null
    }
}
