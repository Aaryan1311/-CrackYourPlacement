class Solution {
public:
    int helper(int idx, int buy, int cnt, vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];
        int choose = 0;
        int notchoose = helper(idx+1,buy,cnt,arr,dp);
        if(buy == 1 && cnt > 0){
            choose = helper(idx+1,0,cnt-1,arr,dp) - arr[idx];
        }
        else if(buy == 0){
            choose = helper(idx+1,1,cnt,arr,dp) + arr[idx];
        }

        return dp[idx][buy][cnt] = max(choose,notchoose);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (3, vector<int> (3,-1)));
        return helper(0,1,2,prices,dp);
    }
};