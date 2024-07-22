class Solution {
    public int findDuplicate(int[] nums) {
        int val = nums[0];
        while(true){
            if(nums[val] == val) return val;
            else{
                int nv = nums[val];
                nums[val] = val;
                val = nv;
            }
        }
    }
}