class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1)
            return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode groupPrev = dummy;

        while (true) {

            ListNode kth = getKth(groupPrev, k);
            if (kth == null)
                break;

            ListNode groupNext = kth.next;
            ListNode groupStart = groupPrev.next;

            reverse(groupStart, kth);

            //reconnect
            groupPrev.next = kth;
            groupStart.next = groupNext;

            // move forward
            groupPrev = groupStart;
        }

        return dummy.next;
    }

    // returns kth node starting from curr (curr included)
    private ListNode getKth(ListNode curr, int k) {
        while (curr != null && k > 0) {
            curr = curr.next;
            k--;
        }
        return curr;
    }

    // reverses from start to end (inclusive)
    private void reverse(ListNode start, ListNode end) {
        ListNode prev = null;
        ListNode curr = start;

        while (prev != end) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
    }
}