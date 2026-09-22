import java.util.*;
public class searchLL {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static boolean isPresent(ListNode list1, ListNode list2) {

        if (list1 == null) {
            return true;
        }

        ListNode start = list2;

        while (start != null) {

            ListNode p1 = list1;
            ListNode p2 = start;

            while (p1 != null && p2 != null && p1.val == p2.val) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) {
                return true;
            }

            start = start.next;
        }

        return false;
    }

    public static void printResult(boolean result) {
        System.out.println(result ? "Yes" : "No");
    }

    public static void main(String[] args) {

        ListNode list1 = new ListNode(10);
        list1.next = new ListNode(20);

        ListNode list2 = new ListNode(5);
        list2.next = new ListNode(10);
        list2.next.next = new ListNode(20);

        boolean result = isPresent(list1, list2);

        printResult(result);
    }
}