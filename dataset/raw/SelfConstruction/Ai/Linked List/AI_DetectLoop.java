// ============================================================
// 09 - Detect Loop (Cycle) in a Linked List
// Uses Floyd's Cycle Detection Algorithm (Tortoise & Hare).
// - slowPointer moves 1 step at a time.
// - fastPointer moves 2 steps at a time.
// If there is a loop, they will eventually meet inside it.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class DetectLoop {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with loop detection ---
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

        // Artificially create a loop for testing:
        // Connect the last node to the node at the given index (0-based).
        void createLoop(int loopStartIndex) {
            Node loopStartNode = null;
            Node current = head;
            int index = 0;

            while (current.next != null) {
                if (index == loopStartIndex) {
                    loopStartNode = current; // Remember where the loop should start
                }
                current = current.next;
                index++;
            }

            // Connect the tail to the loop start node
            if (loopStartNode != null) {
                current.next = loopStartNode;
            }
        }

        // Detect if the list contains a loop using Floyd's algorithm
        // Algorithm:
        //   Both pointers start at head.
        //   In each iteration, slow moves 1 step, fast moves 2 steps.
        //   If they ever meet, a loop exists.
        //   If fast reaches null, there is no loop.
        boolean hasLoop() {
            Node slowPointer = head;
            Node fastPointer = head;

            while (fastPointer != null && fastPointer.next != null) {
                slowPointer = slowPointer.next;       // Move 1 step
                fastPointer = fastPointer.next.next;  // Move 2 steps

                // If both pointers meet, a cycle is detected
                if (slowPointer == fastPointer) {
                    return true;
                }
            }

            // fastPointer reached null — no loop exists
            return false;
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        // List without a loop
        LinkedList list1 = new LinkedList();
        list1.insert(10);
        list1.insert(20);
        list1.insert(30);
        list1.insert(40);
        System.out.println("List 1 has loop: " + list1.hasLoop());
        // Output: List 1 has loop: false

        // List with a loop: tail connects back to node at index 1 (value 20)
        LinkedList list2 = new LinkedList();
        list2.insert(10);
        list2.insert(20);
        list2.insert(30);
        list2.insert(40);
        list2.createLoop(1); // 40 -> 20 (loop)
        System.out.println("List 2 has loop: " + list2.hasLoop());
        // Output: List 2 has loop: true
    }
}
