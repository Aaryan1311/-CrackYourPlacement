class Solution {
public:
    int helper(int idx,int sum, int tar, vector<int>& arr, vector<vector<int>>& dp){
        if(sum == tar) return 1;
        if(idx == arr.size()) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];

        int choose = 0;
        int notchoose = helper(idx+1,sum,tar,arr,dp);
        if(sum + arr[idx] <= tar) choose = helper(idx,sum+arr[idx],tar,arr,dp);

        return dp[idx][sum] =  choose + notchoose;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return helper(0,0,amount,coins,dp);
    }
};