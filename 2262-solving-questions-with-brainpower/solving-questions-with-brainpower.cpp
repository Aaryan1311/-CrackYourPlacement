class Solution {
public:
    long long helper(int idx, vector<vector<int>>& arr, vector<long long>& dp){
        if(idx >= arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long choose = helper(idx+arr[idx][1]+1,arr,dp) + arr[idx][0];
        long long notchoose = helper(idx+1,arr,dp);

        dp[idx] = max(choose,notchoose);
        return dp[idx];
    }
    long long mostPoints(vector<vector<int>>& arr) {
        vector<long long> dp(arr.size(),-1);
        return helper(0,arr,dp);
    }
};