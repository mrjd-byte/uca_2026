import java.util.*;

public class intersectLL {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static ListNode intersection(ListNode head1, ListNode head2) {

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        ListNode p1 = head1;
        ListNode p2 = head2;

        while (p1 != null && p2 != null) {

            if (p1.val == p2.val) {

                
                tail.next = new ListNode(p1.val);
                tail = tail.next;

                p1 = p1.next;
                p2 = p2.next;

            } else if (p1.val < p2.val) {

                p1 = p1.next;

            } else {

                p2 = p2.next;
            }
        }

        return dummy.next;
    }

    public static void printList(ListNode head) {

        while (head != null) {
            System.out.print(head.val);

            if (head.next != null) {
                System.out.print(" -> ");
            }

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(6);

        
        ListNode head2 = new ListNode(2);
        head2.next = new ListNode(4);
        head2.next.next = new ListNode(6);
        head2.next.next.next = new ListNode(8);

        System.out.println("List 1:");
        printList(head1);

        System.out.println("List 2:");
        printList(head2);

        ListNode result = intersection(head1, head2);

        System.out.println("Intersection:");
        printList(result);
    }
}