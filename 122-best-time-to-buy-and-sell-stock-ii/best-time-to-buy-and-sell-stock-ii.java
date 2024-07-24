class Solution {
    public int helper(int idx, int buy, int arr[], int dp[][]){
        if(idx == arr.length) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int p = 0;
        int take = 0;
        int nottake = 0;
        int lev = 0;

        if(buy == 1){
            take = helper(idx+1,0,arr,dp) - arr[idx];
            nottake = helper(idx+1,buy,arr,dp);
        }
        if(buy == 0){
            nottake = helper(idx+1,buy,arr,dp);
            lev = helper(idx+1,1,arr,dp) + arr[idx]; 
        }
        return dp[idx][buy] = Math.max(take,Math.max(nottake,lev));
    }
    public int maxProfit(int[] prices) {
        int dp[][] = new int[prices.length][2];
        for(int r[] : dp) Arrays.fill(r,-1);
        return helper(0,1,prices,dp);
    }
}