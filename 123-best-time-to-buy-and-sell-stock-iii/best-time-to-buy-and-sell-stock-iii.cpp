class Solution {
public:
    int helper(int idx,int buy, int cnt, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(idx == arr.size()) return 0;
        if(cnt == 2 && buy == 1){
            return 0;
        }
        if(dp[idx][cnt][buy] != -1) return dp[idx][cnt][buy];
        int choose = 0;
        int notchoose = 0;
        if(buy){
            choose = helper(idx+1,0,cnt+1,arr,dp) - arr[idx];
            notchoose = helper(idx+1,buy,cnt,arr,dp);
        }
        else{
            choose = helper(idx+1,1,cnt,arr,dp) + arr[idx];
            notchoose = helper(idx+1,0,cnt,arr,dp);
        }

        return dp[idx][cnt][buy] = max(choose,notchoose);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (3, vector<int> (2,-1)));
        return helper(0,1,0,prices,dp);
    }
};