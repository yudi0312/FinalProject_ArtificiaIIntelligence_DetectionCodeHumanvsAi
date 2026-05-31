// ============================================================
// 14 - Search Node in a Linked List
// Scans through the list to find a node with the target value.
// Returns the node's position (1-based index) or -1 if absent.
// Time Complexity: O(n) | Space Complexity: O(1)
// ============================================================

public class SearchNode {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Linked List with search operation ---
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

        // Search for a value and return its 1-based position in the list
        // Algorithm:
        //   Start from the head and compare each node's data.
        //   Track the current position with a counter.
        //   Return the position when found, or -1 if not found.
        int search(int target) {
            Node current = head;
            int position = 1; // 1-based index

            while (current != null) {
                if (current.data == target) {
                    return position; // Found at this position
                }
                current = current.next;
                position++;
            }

            return -1; // Target was not found
        }

        // Search and return the actual node reference (or null if not found)
        Node searchNode(int target) {
            Node current = head;

            while (current != null) {
                if (current.data == target) {
                    return current;
                }
                current = current.next;
            }

            return null;
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
        list.insert(25);
        list.insert(37);
        list.insert(42);
        list.insert(55);
        list.display();
        // Output: List: 10 -> 25 -> 37 -> 42 -> 55 -> null

        // Search by value — returns position
        int pos1 = list.search(37);
        System.out.println("Search 37: found at position " + pos1);
        // Output: Search 37: found at position 3

        int pos2 = list.search(10);
        System.out.println("Search 10: found at position " + pos2);
        // Output: Search 10: found at position 1

        int pos3 = list.search(99);
        System.out.println("Search 99: " + (pos3 == -1 ? "not found" : "position " + pos3));
        // Output: Search 99: not found

        // Search and get the node itself
        Node foundNode = list.searchNode(42);
        System.out.println("Node for 42: " + (foundNode != null ? foundNode.data : "null"));
        // Output: Node for 42: 42
    }
}
