class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int ans1 = 1;
        int ans2 = nums[0]*nums[1]*nums[nums.length-1];
        for(int i = 0;i<3;i++){
            ans1 *= nums[nums.length-i-1];
        }
        return Math.max(ans1,ans2);
    }
}