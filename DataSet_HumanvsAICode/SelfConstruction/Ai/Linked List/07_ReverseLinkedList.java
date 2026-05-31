// ============================================================
// 07 - Reverse Linked List
// Reverses the direction of all next pointers in the list
// so the tail becomes the new head.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class ReverseLinkedList {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with reverse operation ---
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

        // Reverse the entire linked list in-place (iterative approach)
        // Algorithm:
        //   We use three pointers: previous, current, and nextNode.
        //   At each step, we flip the current node's next pointer to
        //   point backward instead of forward.
        //   When done, head is updated to what was the last node.
        void reverse() {
            Node previous = null;  // Will become the new tail (null)
            Node current = head;   // Starts at the original head
            Node nextNode = null;  // Temporarily holds the next node

            while (current != null) {
                nextNode = current.next;  // Save next before overwriting
                current.next = previous;  // Flip the pointer backward
                previous = current;       // Move previous forward
                current = nextNode;       // Move current forward
            }

            // After the loop, previous is the new head (last original node)
            head = previous;
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

        System.out.println("Before reversal:");
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> 50 -> null

        list.reverse();

        System.out.println("After reversal:");
        list.display();
        // Output: List: 50 -> 40 -> 30 -> 20 -> 10 -> null
    }
}
