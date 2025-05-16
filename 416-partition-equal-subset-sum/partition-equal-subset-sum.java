class Solution {
    public boolean helper(int idx, int curr, int tar, int nums[], Boolean dp[][]){
        if(curr == tar) return true;
        if(idx >= nums.length) return false;
        if(curr > tar) return false;
        if(dp[idx][curr] != null) return dp[idx][curr];

        boolean choose = helper(idx+1,curr+nums[idx],tar,nums,dp);
        boolean notchoose = helper(idx+1,curr,tar,nums,dp);

        return dp[idx][curr] =  choose || notchoose;
    }
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum % 2 == 1) return false;
        Boolean dp[][] = new Boolean[nums.length][sum/2+1];
        return helper(0,0,sum/2,nums,dp);
    }
}