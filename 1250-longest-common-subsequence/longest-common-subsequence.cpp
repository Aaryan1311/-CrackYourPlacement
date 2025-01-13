class Solution {
public:
    int helper(int idx1,  int idx2, string& s1, string& s2, vector<vector<int>>& dp){

        if(idx1 == s1.size() || idx2 == s2.size()) return 0;
        if(dp[idx1][idx2] != -1 ) return dp[idx1][idx2];

        int ans = 0;
        if(s1[idx1] == s2[idx2]){
            ans = 1 + helper(idx1 + 1,idx2 + 1, s1, s2, dp);
        }
        else{
            ans =  max(helper(idx1,idx2+1, s1, s2,dp), helper(idx1+1,idx2,s1,s2,dp));
        }

        dp[idx1][idx2] = ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(),-1));
        return helper(0,0,text1,text2,dp);
    }
};