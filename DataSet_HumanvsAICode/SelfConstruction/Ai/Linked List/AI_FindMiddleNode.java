// ============================================================
// 08 - Find Middle Node
// Uses the "slow and fast pointer" (Floyd's) technique to
// find the middle node in a single pass.
// - Slow pointer moves 1 step at a time.
// - Fast pointer moves 2 steps at a time.
// When fast reaches the end, slow is at the middle.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class FindMiddleNode {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with find-middle operation ---
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

        // Find and return the middle node using two pointers
        // Algorithm:
        //   slowPointer advances one node per iteration.
        //   fastPointer advances two nodes per iteration.
        //   When fastPointer can't advance further, slowPointer
        //   is sitting at the middle of the list.
        Node findMiddle() {
            if (head == null) {
                return null;
            }

            Node slowPointer = head;
            Node fastPointer = head;

            // Move until fastPointer reaches the last or second-to-last node
            while (fastPointer != null && fastPointer.next != null) {
                slowPointer = slowPointer.next;       // Move 1 step
                fastPointer = fastPointer.next.next;  // Move 2 steps
            }

            // slowPointer is now at the middle
            return slowPointer;
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

        // Odd number of elements
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        list.display();
        // Output: List: 10 -> 20 -> 30 -> 40 -> 50 -> null

        Node middle = list.findMiddle();
        System.out.println("Middle node: " + middle.data);
        // Output: Middle node: 30

        // Even number of elements — returns second middle
        LinkedList list2 = new LinkedList();
        list2.insert(10);
        list2.insert(20);
        list2.insert(30);
        list2.insert(40);
        list2.display();

        Node middle2 = list2.findMiddle();
        System.out.println("Middle node (even list): " + middle2.data);
        // Output: Middle node (even list): 30
    }
}
