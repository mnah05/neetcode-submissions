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
class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        //[1] Split and reverse second half
        ListNode second = slow.next;
        slow.next = null;

        ListNode prev = null;
        ListNode curr = second;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        second = prev;

        //[2] Merge the two halves
        ListNode first = head;

        while (second != null) {
            //[3] save next nodes
            ListNode temp1 = first.next;
            ListNode temp2 = second.next;

            //[4] link between new nodes
            first.next = second;
            second.next = temp1;
            
            //[5] update to same
            first = temp1;
            second = temp2;
        }
    }
}