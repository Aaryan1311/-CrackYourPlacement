class Solution {
    public int findDuplicate(int[] nums) {
        
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        int p1 = slow;
        int p2 = 0;
        do{
            p1 = nums[p1];
            p2 = nums[p2];
        }while(p1 != p2);
        return p1;
    }
}