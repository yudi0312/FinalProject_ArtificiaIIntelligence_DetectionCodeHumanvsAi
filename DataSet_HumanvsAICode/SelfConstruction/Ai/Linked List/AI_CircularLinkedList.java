// ============================================================
// 03 - Circular Linked List
// Similar to a singly linked list, but the last node points
// back to the head instead of null — forming a circle.
// ============================================================

public class CircularLinkedList {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Circular Linked List definition ---
    static class CLinkedList {
        Node head; // First node (also reachable from the last node)

        // Insert a new node at the end of the circular list
        void insert(int data) {
            Node newNode = new Node(data);

            // If the list is empty, point the new node to itself
            if (head == null) {
                head = newNode;
                newNode.next = head; // Circular reference
                return;
            }

            // Traverse to the last node (the one pointing back to head)
            Node current = head;
            while (current.next != head) {
                current = current.next;
            }

            // Insert the new node and update the circular link
            current.next = newNode;
            newNode.next = head; // Point new last node back to head
        }

        // Print all elements once (stop when we loop back to head)
        void display() {
            if (head == null) {
                System.out.println("List is empty.");
                return;
            }

            Node current = head;
            System.out.print("Circular List: ");
            do {
                System.out.print(current.data + " -> ");
                current = current.next;
            } while (current != head); // Stop when we return to head

            System.out.println("(back to head: " + head.data + ")");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        CLinkedList list = new CLinkedList();

        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);

        list.display();
        // Output: Circular List: 10 -> 20 -> 30 -> 40 -> (back to head: 10)
    }
}
