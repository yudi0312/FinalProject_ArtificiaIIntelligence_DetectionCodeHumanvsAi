public int count() {
    int count = 0;
    for (ListNode n = head; n != null; n = n.next) {
        count++;
    }
    return count;
}

public class ListNode {

String name;        // a name in the list
ListNode next;      // the next node in the list
ListNode prev;      // the previous node in the list

/**
 * Constructor with just a name. This form would be most useful when
 * starting a list.
 */
public ListNode(String name) {
    this.name = name;
    next = null;
    prev = null;
}

/**
 * Constructor with a name and a reference to the previous list node. This
 * form would be most useful when adding to the end of a list.
 */
public ListNode(String name, ListNode node) {
    this.name = name;
    next = null;
    prev = node;
}
}
