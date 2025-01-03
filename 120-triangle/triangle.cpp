class Solution {
public:
    int helper(int idx, int subidx, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(idx == arr.size()-1) return arr[idx][subidx];
        if(dp[idx][subidx] != -1) return dp[idx][subidx];

        int same = 3000000;
        int next = 3000000;

        same = helper(idx+1,subidx,arr,dp) + arr[idx][subidx];
        next = helper(idx+1,subidx+1,arr,dp) + arr[idx][subidx];

        return dp[idx][subidx] = min(same,next);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle[triangle.size()-1].size(),-1));
        return helper(0,0,triangle,dp);
    }
};