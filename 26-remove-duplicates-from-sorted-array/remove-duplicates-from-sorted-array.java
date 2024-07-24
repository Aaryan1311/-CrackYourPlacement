class Solution {
    public int removeDuplicates(int[] nums) {
        int pl = 0;
        int unpl = 0;
        int cnt = 1;
        while(unpl < nums.length){
            if(nums[pl] == nums[unpl]){
                unpl++;
            }
            else{
                pl++;
                
                nums[pl] = nums[unpl];
                cnt++;  
            }
        }
        return cnt;
    }
}