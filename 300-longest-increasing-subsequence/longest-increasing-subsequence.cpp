class Solution {
public:
    int helper(int idx, int prev, vector<int>& arr, vector<vector<int>> &dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int pick = 0;
        if(prev == -1 || arr[idx] > arr[prev]){
            pick = helper(idx+1,idx,arr,dp) + 1;
        }
        int notpick = helper(idx+1,prev,arr,dp);
        return dp[idx][prev+1] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int> (nums.size()+1, -1));
        return helper(0,-1,nums,arr);
    }
};