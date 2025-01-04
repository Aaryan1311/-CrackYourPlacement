int dp[101][101];
int n;



 int helper(int x, int y, vector<vector<int>>& arr){
        if(x == arr.size()-1) return arr[x][y];
        if(dp[x][y] != -100000) return dp[x][y];
        int ans = helper(x+1,y,arr) + arr[x][y];
        if(y > 0) ans = min(ans,helper(x+1,y-1,arr) + arr[x][y]);
        if(y < n-1) ans = min(ans,helper(x+1,y+1,arr) + arr[x][y]);
        return dp[x][y] = ans;
    }

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        for(int i=0; i<101; ++i)
            for(int j=0; j<101; ++j)
                dp[i][j] = -100000;
        int mn = 1e9;
        for(int i =0;i<n;i++){
            mn = min(mn,helper(0,i,matrix));
        }
        return mn;
    }
};