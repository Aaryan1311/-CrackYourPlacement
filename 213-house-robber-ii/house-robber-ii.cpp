class Solution {
public:

    int helper(int idx, int end,vector<int>& arr, vector<int>& dp){
        if(idx > end) return 0;
        if(dp[idx] != -1) return dp[idx];

        int choose = helper(idx+2,end,arr,dp) + arr[idx];
        int notchoose = helper(idx+1,end,arr,dp);
        
        return dp[idx] = max(choose,notchoose);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans1 = helper(0,n-2,nums,dp);
        int ans2 = helper(1,n-1,nums,dp2);

        cout << ans1 << " " << ans2 << endl;
        return max(ans1,ans2);
    }
};