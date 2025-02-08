class Solution {
public:
    int helper(int idx, int cnt, int buy, int k, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(idx == arr.size()) return 0;
        if(cnt == k && buy == 1) return 0;
        if(dp[idx][cnt][buy] != -1) return dp[idx][cnt][buy];
        int choose = 0;
        int notchoose = helper(idx+1,cnt,buy,k,arr,dp);
        if(buy){
            choose = helper(idx+1,cnt+1,0,k,arr,dp) - arr[idx];
        } 
        else{
            choose = helper(idx+1,cnt,1,k,arr,dp) + arr[idx];
        }
        return dp[idx][cnt][buy] = max(choose,notchoose);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (k+1, vector<int> (2,-1)));
        return helper(0,0,1,k,prices,dp);
    }
};