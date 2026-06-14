// ============================================================
// 20 - Stack implemented using a Singly Linked List
// A Stack is a LIFO (Last-In, First-Out) data structure.
//   - push:  add to the TOP (head) of the stack — O(1).
//   - pop:   remove from the TOP (head) of the stack — O(1).
//   - peek:  view the top element without removing — O(1).
// The head of the linked list serves as the top of the stack.
// ============================================================

public class LinkedListStack {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Stack implemented with a linked list ---
    static class Stack {
        Node top;  // Points to the topmost element (head of the linked list)
        int size;

        Stack() {
            top = null;
            size = 0;
        }

        // Check if the stack is empty
        boolean isEmpty() {
            return top == null;
        }

        // Push: add a new element to the TOP of the stack
        // Algorithm:
        //   Create a new node and link it to the current top.
        //   Then move the top pointer to the new node.
        //   This is equivalent to inserting at the beginning of the list.
        void push(int data) {
            Node newNode = new Node(data);
            newNode.next = top; // New node points to the current top
            top = newNode;      // New node becomes the new top
            size++;
            System.out.println("Pushed: " + data);
        }

        // Pop: remove and return the TOP element from the stack
        // Algorithm:
        //   Save the top node's data.
        //   Move the top pointer to the next node.
        //   Return the saved data.
        int pop() {
            if (isEmpty()) {
                System.out.println("Stack is empty. Cannot pop.");
                return -1;
            }

            int removedData = top.data; // Save the top value
            top = top.next;             // Move top to the node below
            size--;
            return removedData;
        }

        // Peek: look at the top element without removing it
        int peek() {
            if (isEmpty()) {
                System.out.println("Stack is empty.");
                return -1;
            }
            return top.data;
        }

        // Print all elements from top to bottom
        void display() {
            if (isEmpty()) {
                System.out.println("Stack: [empty]");
                return;
            }

            Node current = top;
            System.out.print("Stack (top -> bottom): ");
            while (current != null) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }
            System.out.println("null  (size: " + size + ")");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        Stack stack = new Stack();

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.display();
        // Output: Stack (top -> bottom): 40 -> 30 -> 20 -> 10 -> null

        System.out.println("Peek: " + stack.peek());
        // Output: Peek: 40

        System.out.println("Popped: " + stack.pop());
        // Output: Popped: 40

        System.out.println("Popped: " + stack.pop());
        // Output: Popped: 30

        stack.display();
        // Output: Stack (top -> bottom): 20 -> 10 -> null

        stack.push(50);
        stack.display();
        // Output: Stack (top -> bottom): 50 -> 20 -> 10 -> null
    }
}
