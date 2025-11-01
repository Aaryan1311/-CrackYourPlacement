class Solution {
public:
int helper(int idx, int pre, vector<int>& nums, vector<vector<int>>& dp){
    if(idx == nums.size()) return 0;
    if(dp[idx][pre+1] != -1) return dp[idx][pre+1];
    int choose = 0;
    if(pre == -1 || nums[pre] < nums[idx]) choose = helper(idx+1,idx,nums,dp)+1;
    int notchoose = helper(idx+1,pre,nums,dp);
    return dp[idx][pre+1] = max(choose,notchoose);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1,-1));
        return helper(0,-1,nums,dp);
    }
};