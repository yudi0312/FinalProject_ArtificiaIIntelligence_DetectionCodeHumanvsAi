// ============================================================
// 12 - Remove Duplicates from a Sorted Linked List
// Traverses the list once and removes any consecutive nodes
// that have the same value as the current node.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class RemoveDuplicates {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with remove-duplicates operation ---
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

        // Remove all duplicate nodes from a SORTED list
        // Algorithm:
        //   Traverse the list. For each node, check if its next
        //   node has the same value. If so, skip the next node
        //   by pointing current.next to the node after it.
        //   Repeat until current.next has a different value.
        void removeDuplicatesSorted() {
            Node current = head;

            while (current != null && current.next != null) {
                // If current and next have the same value, skip the next node
                if (current.data == current.next.data) {
                    current.next = current.next.next; // Bypass the duplicate
                } else {
                    current = current.next; // Only advance if no duplicate found
                }
            }
        }

        // Remove duplicates from an UNSORTED list using a simple approach:
        // For each node, scan ahead and remove any matching values.
        // Time Complexity: O(n^2)
        void removeDuplicatesUnsorted() {
            Node current = head;

            while (current != null) {
                Node runner = current; // runner checks all nodes after current

                while (runner.next != null) {
                    if (runner.next.data == current.data) {
                        runner.next = runner.next.next; // Skip the duplicate
                    } else {
                        runner = runner.next;
                    }
                }

                current = current.next;
            }
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
        // Sorted list with duplicates
        LinkedList sortedList = new LinkedList();
        sortedList.insert(10);
        sortedList.insert(10);
        sortedList.insert(20);
        sortedList.insert(30);
        sortedList.insert(30);
        sortedList.insert(30);
        sortedList.insert(40);

        System.out.println("Before (sorted):");
        sortedList.display();
        // Output: List: 10 -> 10 -> 20 -> 30 -> 30 -> 30 -> 40 -> null

        sortedList.removeDuplicatesSorted();

        System.out.println("After removing duplicates (sorted):");
        sortedList.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> null

        // Unsorted list with duplicates
        LinkedList unsortedList = new LinkedList();
        unsortedList.insert(30);
        unsortedList.insert(10);
        unsortedList.insert(20);
        unsortedList.insert(10);
        unsortedList.insert(30);

        System.out.println("\nBefore (unsorted):");
        unsortedList.display();
        // Output: List: 30 -> 10 -> 20 -> 10 -> 30 -> null

        unsortedList.removeDuplicatesUnsorted();

        System.out.println("After removing duplicates (unsorted):");
        unsortedList.display();
        // Output: List: 30 -> 10 -> 20 -> null
    }
}
