class Solution {
    public boolean check(int[] nums) {
        int chng = 0;
        for(int i = 0;i<nums.length-1;i++){
            if(nums[i] > nums[i+1]){
                chng++;
            }
        }
        if(nums[nums.length-1] > nums[0]) chng++;
        return chng < 2;
    }
}