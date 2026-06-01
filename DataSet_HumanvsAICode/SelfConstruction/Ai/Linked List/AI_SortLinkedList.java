// ============================================================
// 11 - Sort Linked List (Merge Sort)
// Merge Sort is best suited for linked lists because it does
// not require random access. It splits the list in half
// recursively and merges the sorted halves back together.
// Time Complexity: O(n log n) | Space Complexity: O(log n) stack
// ============================================================

public class SortLinkedList {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with merge sort ---
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

        // Public method to sort the list
        void sort() {
            head = mergeSort(head);
        }

        // Recursively splits and sorts the list using merge sort
        // Algorithm:
        //   1. Base case: a single node or null is already sorted.
        //   2. Find the middle node using slow/fast pointers.
        //   3. Split the list into two halves.
        //   4. Recursively sort each half.
        //   5. Merge the two sorted halves.
        private Node mergeSort(Node startNode) {
            // Base case: empty or single node
            if (startNode == null || startNode.next == null) {
                return startNode;
            }

            // Step 1: Find the middle of the list
            Node middle = findMiddle(startNode);

            // Step 2: Split the list into two halves
            Node secondHalfStart = middle.next;
            middle.next = null; // Cut the list at the middle

            // Step 3: Recursively sort both halves
            Node sortedLeft = mergeSort(startNode);
            Node sortedRight = mergeSort(secondHalfStart);

            // Step 4: Merge the two sorted halves
            return mergeSorted(sortedLeft, sortedRight);
        }

        // Find the middle node using slow/fast pointers
        private Node findMiddle(Node startNode) {
            Node slowPointer = startNode;
            Node fastPointer = startNode.next;

            while (fastPointer != null && fastPointer.next != null) {
                slowPointer = slowPointer.next;
                fastPointer = fastPointer.next.next;
            }

            return slowPointer; // slowPointer is at the middle
        }

        // Merge two already-sorted lists into one sorted list
        private Node mergeSorted(Node leftHead, Node rightHead) {
            Node dummy = new Node(0);
            Node tail = dummy;

            while (leftHead != null && rightHead != null) {
                if (leftHead.data <= rightHead.data) {
                    tail.next = leftHead;
                    leftHead = leftHead.next;
                } else {
                    tail.next = rightHead;
                    rightHead = rightHead.next;
                }
                tail = tail.next;
            }

            tail.next = (leftHead != null) ? leftHead : rightHead;

            return dummy.next;
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

        list.insert(50);
        list.insert(10);
        list.insert(40);
        list.insert(20);
        list.insert(30);

        System.out.println("Before sorting:");
        list.display();
        // Output: List: 50 -> 10 -> 40 -> 20 -> 30 -> null

        list.sort();

        System.out.println("After sorting:");
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> 50 -> null
    }
}
