public class StackUsingArray {
    private int[] data;
    private int top;

    public StackUsingArray(int capacity) {
        data = new int[capacity];
        top = -1;
    }

    public void push(int value) { data[++top] = value; }
    public int pop() { return data[top--]; }
    public int peek() { return data[top]; }
    public boolean isEmpty() { return top == -1; }

    public static void main(String[] args) {
        StackUsingArray stack = new StackUsingArray(10);
        stack.push(10); stack.push(20);
        System.out.println(stack.pop());
    }
}