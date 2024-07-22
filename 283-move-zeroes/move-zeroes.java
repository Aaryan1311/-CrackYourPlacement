class Solution {
    public void moveZeroes(int[] nums) {
        int idx = 0;
        int pl = 0;
        int cnt  = 0;
        int n = nums.length;
        while(idx < n){
            if(nums[idx] == 0){
                cnt++;
                idx++;
            }
            else{
                nums[pl]  = nums[idx];
                // nums[idx] = 0;
                idx++;
                pl++;
            }
        }
        for(int i = 1;i<=cnt;i++){
            nums[n-i] = 0;
        }
    }
}