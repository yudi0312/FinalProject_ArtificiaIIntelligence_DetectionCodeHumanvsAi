// Justin Butler
// 11/15/2021
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted List.
Memory Usage: 38.4 MB, less than 71.66% of Java online submissions for Remove Duplicates from Sorted List.
*/
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head; // Pointer to head to traverse are linked list.
        while(curr !=null && curr.next !=null)
        {
            if(curr.val == curr.next.val) // when we have duplicate elements, set the next pointer to be offset by 1 listnode.
            {
                curr.next = curr.next.next;
            }
            else //otherwise just do a regular traversal
            {
                curr = curr.next;
            }
        }
        return head;
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */