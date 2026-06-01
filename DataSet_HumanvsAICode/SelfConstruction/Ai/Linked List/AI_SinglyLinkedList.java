// ============================================================
// 01 - Singly Linked List
// Each node holds data and a reference to the next node.
// The list only travels in one direction (forward).
// ============================================================

public class SinglyLinkedList {

    // --- Node definition ---
    // Each node stores a value and points to the next node.
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List definition ---
    static class LinkedList {
        Node head; // Points to the first node in the list

        // Insert a new node at the end of the list
        void insert(int data) {
            Node newNode = new Node(data);

            // If the list is empty, the new node becomes the head
            if (head == null) {
                head = newNode;
                return;
            }

            // Traverse to the last node
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }

            // Attach the new node at the end
            current.next = newNode;
        }

        // Print all elements from head to the last node
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

        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> null
    }
}
