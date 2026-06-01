// ============================================================
// 16 - Split Linked List
// Divides a linked list into two halves at the middle node.
// Uses the slow/fast pointer technique to find the midpoint.
// If the list has an odd number of nodes, the first half
// gets the extra node.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class SplitLinkedList {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with split operation ---
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

        // Split the list into two halves and store them in firstHalf/secondHalf
        // Algorithm:
        //   1. Use slow/fast pointers to locate the end of the first half.
        //   2. The node AFTER slow becomes the head of the second half.
        //   3. Break the link between slow and the second half.
        void split(LinkedList firstHalf, LinkedList secondHalf) {
            if (head == null) {
                firstHalf.head = null;
                secondHalf.head = null;
                return;
            }

            Node slowPointer = head;
            Node fastPointer = head.next; // Start fast one step ahead

            // Move until fast reaches the end of the list
            while (fastPointer != null && fastPointer.next != null) {
                slowPointer = slowPointer.next;
                fastPointer = fastPointer.next.next;
            }

            // slowPointer is at the last node of the first half
            firstHalf.head = head;              // First half starts at head
            secondHalf.head = slowPointer.next; // Second half starts after slow
            slowPointer.next = null;            // Disconnect the two halves
        }

        // Print all elements
        void display(String label) {
            Node current = head;
            System.out.print(label + ": ");
            while (current != null) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }
            System.out.println("null");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        // Odd number of nodes
        LinkedList list1 = new LinkedList();
        list1.insert(10);
        list1.insert(20);
        list1.insert(30);
        list1.insert(40);
        list1.insert(50);
        list1.display("Original (5 nodes)");

        LinkedList first1 = new LinkedList();
        LinkedList second1 = new LinkedList();
        list1.split(first1, second1);
        first1.display("First Half ");
        second1.display("Second Half");
        // First Half:  10 -> 20 -> 30 -> null
        // Second Half: 40 -> 50 -> null

        System.out.println();

        // Even number of nodes
        LinkedList list2 = new LinkedList();
        list2.insert(10);
        list2.insert(20);
        list2.insert(30);
        list2.insert(40);
        list2.display("Original (4 nodes)");

        LinkedList first2 = new LinkedList();
        LinkedList second2 = new LinkedList();
        list2.split(first2, second2);
        first2.display("First Half ");
        second2.display("Second Half");
        // First Half:  10 -> 20 -> null
        // Second Half: 30 -> 40 -> null
    }
}
