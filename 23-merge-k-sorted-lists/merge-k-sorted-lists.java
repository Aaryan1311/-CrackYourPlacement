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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0;i<lists.length;i++){
            ListNode head = lists[i];
            while(head != null){
                pq.add(head.val);
                head = head.next;
            }
        }
        if(pq.isEmpty()) return null;
        ListNode head = new ListNode(pq.remove());
        ListNode temp = head;
        while(!pq.isEmpty()){
            ListNode node = new ListNode(pq.remove());
            temp.next = node;
            temp = temp.next;
        }
        return head;
    }
}