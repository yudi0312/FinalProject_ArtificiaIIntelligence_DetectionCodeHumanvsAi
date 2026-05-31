// ============================================================
// 19 - Queue implemented using a Singly Linked List
// A Queue is a FIFO (First-In, First-Out) data structure.
//   - enqueue: add to the REAR (tail) of the queue.
//   - dequeue: remove from the FRONT (head) of the queue.
// Using head as front and tail as rear gives O(1) for both.
// ============================================================

public class LinkedListQueue {

    // --- Node definition ---
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // --- Queue implemented with a linked list ---
    static class Queue {
        Node front; // Points to the node at the front (to be dequeued next)
        Node rear;  // Points to the node at the rear (last enqueued)
        int size;

        Queue() {
            front = null;
            rear = null;
            size = 0;
        }

        // Check if the queue is empty
        boolean isEmpty() {
            return front == null;
        }

        // Enqueue: add a new element to the REAR of the queue
        // Algorithm:
        //   Create a new node and attach it after the current rear.
        //   Update rear to point to the new node.
        //   If the queue was empty, front also points to the new node.
        void enqueue(int data) {
            Node newNode = new Node(data);

            if (isEmpty()) {
                front = newNode;
                rear = newNode;
            } else {
                rear.next = newNode; // Link new node after the current rear
                rear = newNode;      // Update rear to the new node
            }

            size++;
            System.out.println("Enqueued: " + data);
        }

        // Dequeue: remove and return the element from the FRONT of the queue
        // Algorithm:
        //   Save the front node's data.
        //   Move front pointer to the next node.
        //   If the queue becomes empty, also set rear to null.
        int dequeue() {
            if (isEmpty()) {
                System.out.println("Queue is empty. Cannot dequeue.");
                return -1;
            }

            int removedData = front.data; // Save the front value
            front = front.next;           // Move front to the next node

            if (front == null) {
                rear = null; // Queue is now empty; clear rear too
            }

            size--;
            return removedData;
        }

        // Peek: look at the front element without removing it
        int peek() {
            if (isEmpty()) {
                System.out.println("Queue is empty.");
                return -1;
            }
            return front.data;
        }

        // Print all elements from front to rear
        void display() {
            if (isEmpty()) {
                System.out.println("Queue: [empty]");
                return;
            }

            Node current = front;
            System.out.print("Queue (front -> rear): ");
            while (current != null) {
                System.out.print(current.data + " -> ");
                current = current.next;
            }
            System.out.println("null  (size: " + size + ")");
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) {
        Queue queue = new Queue();

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.display();
        // Output: Queue (front -> rear): 10 -> 20 -> 30 -> 40 -> null

        System.out.println("Peek: " + queue.peek());
        // Output: Peek: 10

        System.out.println("Dequeued: " + queue.dequeue());
        // Output: Dequeued: 10

        System.out.println("Dequeued: " + queue.dequeue());
        // Output: Dequeued: 20

        queue.display();
        // Output: Queue (front -> rear): 30 -> 40 -> null

        queue.enqueue(50);
        queue.display();
        // Output: Queue (front -> rear): 30 -> 40 -> 50 -> null
    }
}
