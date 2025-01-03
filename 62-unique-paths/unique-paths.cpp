class Solution {
public:
    int helper(int x, int y, int row, int col, vector<vector<int>>& dp){
        if(x == row && y == col) return 1;
        else if(x > row || y > col) return 0;
        if(dp[x][y] != -1) return dp[x][y];

        int down = 0;
        int right = 0;
        down = helper(x+1,y,row,col,dp);
        right = helper(x,y+1,row,col,dp);

        return dp[x][y] = down + right;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return helper(0,0,m-1,n-1,dp);
    }
};