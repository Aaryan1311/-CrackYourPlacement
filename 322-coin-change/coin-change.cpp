typedef long long int ll;
class Solution {
public:
    ll helper(int idx, ll sum, ll tar, vector<int>& arr, vector<vector<ll>>& dp){
        if(idx == arr.size()){
            if(sum == tar) return 0;
            return INT_MIN;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        ll choose = 1000000;
        if(sum + arr[idx] <= tar) choose = helper(idx,sum+arr[idx], tar, arr, dp) + 1;
        ll notchoose = helper(idx+1,sum,tar,arr,dp);
        if(choose < 0 && notchoose < 0){
            dp[idx][sum] = INT_MIN;
            return choose;
        }
        else if(choose < 0){
            dp[idx][sum] = notchoose;
            return notchoose;
        }
        else if(notchoose < 0){
            dp[idx][sum] = choose;
            return choose;
        }
        return dp[idx][sum] = min(choose,notchoose); 
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<ll>> dp(coins.size(), vector<ll> (amount+1,-1));
        int ans =  (int)(helper(0,0,amount,coins,dp));
        return ans >= 1000000 ? -1 : ans;
    }
};