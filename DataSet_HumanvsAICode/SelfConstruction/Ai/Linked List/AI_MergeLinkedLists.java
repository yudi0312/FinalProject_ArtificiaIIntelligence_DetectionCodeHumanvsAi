// ============================================================
// 10 - Merge Two Sorted Linked Lists
// Combines two already-sorted linked lists into a single
// sorted linked list without using extra space for new nodes.
// Time Complexity: O(n + m) | Space Complexity: O(1)
// ============================================================

public class MergeLinkedLists {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with merge operation ---
    static class LinkedList {
        Node head;

        // Insert at end (assumes you insert in sorted order for this demo)
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

        // Merge two sorted linked lists and return the merged list's head
        // Algorithm:
        //   1. Use a dummy node as a placeholder for the result head.
        //   2. Compare the current nodes of both lists.
        //   3. Attach the smaller one to the result and advance that pointer.
        //   4. Repeat until one list is exhausted.
        //   5. Attach the remaining nodes of the non-exhausted list.
        Node mergeSorted(Node listAHead, Node listBHead) {
            // Dummy node simplifies edge case handling for the first node
            Node dummy = new Node(0);
            Node resultTail = dummy; // Tracks the last node in the merged list

            Node pointerA = listAHead;
            Node pointerB = listBHead;

            // Compare and attach the smaller node at each step
            while (pointerA != null && pointerB != null) {
                if (pointerA.data <= pointerB.data) {
                    resultTail.next = pointerA;
                    pointerA = pointerA.next;
                } else {
                    resultTail.next = pointerB;
                    pointerB = pointerB.next;
                }
                resultTail = resultTail.next; // Advance the result tail
            }

            // Attach whichever list still has remaining nodes
            if (pointerA != null) {
                resultTail.next = pointerA;
            } else {
                resultTail.next = pointerB;
            }

            // The merged list starts after the dummy node
            return dummy.next;
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

        // Print from a given node (used for merged result)
        static void displayFrom(Node start, String label) {
            System.out.print(label + ": ");
            while (start != null) {
                System.out.print(start.data + " -> ");
                start = start.next;
            }
            System.out.println("null");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        LinkedList listA = new LinkedList();
        listA.insert(10);
        listA.insert(20);
        listA.insert(40);
        listA.insert(60);
        listA.display("List A");
        // Output: List A: 10 -> 20 -> 40 -> 60 -> null

        LinkedList listB = new LinkedList();
        listB.insert(5);
        listB.insert(15);
        listB.insert(35);
        listB.insert(50);
        listB.display("List B");
        // Output: List B: 5 -> 15 -> 35 -> 50 -> null

        LinkedList merger = new LinkedList();
        Node mergedHead = merger.mergeSorted(listA.head, listB.head);
        LinkedList.displayFrom(mergedHead, "Merged");
        // Output: Merged: 5 -> 10 -> 15 -> 20 -> 35 -> 40 -> 50 -> 60 -> null
    }
}
