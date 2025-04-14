class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i :nums){
            pq.add(i);
        }
        for(int i = 0;i<k-1;i++) pq.remove();
        return pq.peek();
    }
}