class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(x == arr.size() -1 && y == arr[0].size()-1) return arr[x][y];
        if(dp[x][y] != -1) return dp[x][y];
        
        int down = 50000;
        int right = 50000;

        if(x != arr.size()-1) down = helper(x+1,y,arr,dp) + arr[x][y];
        if(y != arr[0].size()-1) right = helper(x,y+1,arr,dp) + arr[x][y];

        return dp[x][y] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>  (grid[0].size(),-1));
        return helper(0,0,grid,dp);
    }
};