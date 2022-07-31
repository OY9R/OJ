package com.leetcode.july;

import com.leetcode.ListNode;
import com.leetcode.Test;

public class DeleteDuplicates {
    //@Test("([1,2,3,3,4,4,5])=[1,2,5]([1,1,1,2,3])=[2,3]")
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode dummy = new ListNode(0, head);

        ListNode cur = dummy;
        while (cur.next != null && cur.next.next != null) {
            if (cur.next.val == cur.next.next.val) {
                int x = cur.next.val;
                while (cur.next != null && cur.next.val == x) {
                    cur.next = cur.next.next;
                }
            } else {
                cur = cur.next;
            }
        }

        return dummy.next;
    }
}
