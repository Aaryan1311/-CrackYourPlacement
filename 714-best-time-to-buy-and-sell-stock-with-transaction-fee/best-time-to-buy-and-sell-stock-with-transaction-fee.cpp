class Solution {
public:
    int helper(int idx, int buy, int fee, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int choose = 0;
        int notchoose = helper(idx+1,buy,fee,arr,dp);
        if(buy){
            choose = helper(idx+1,0,fee,arr,dp) - arr[idx];
        }
        else{
            choose = helper(idx+1,1,fee,arr,dp) + arr[idx] - fee;
        }

        return dp[idx][buy] = max(choose,notchoose);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return helper(0,1,fee,prices,dp);
    }
};