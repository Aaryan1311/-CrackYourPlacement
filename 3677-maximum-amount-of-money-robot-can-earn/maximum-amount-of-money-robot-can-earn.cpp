class Solution {
public:
    int helper(int i, int j, int m, int n, int neu, vector<vector<int>>& arr,
               vector<vector<vector<int>>>& dp) {
        if (i == m - 1 && j == n - 1) {
            if (arr[i][j] < 0) {
                if (neu > 0)
                    return 0;
                return arr[i][j];
            } else
                return arr[i][j];
        }
        if (i == m || j == n)
            return -5000000;
        if (dp[i][j][neu] != -5000000)
            return dp[i][j][neu];
        int down = INT_MIN;
        int right = INT_MIN;
        if (arr[i][j] < 0) {
            int ans1 = helper(i, j + 1, m, n, neu, arr, dp) + arr[i][j];
            int ans2 = INT_MIN;
            if (neu > 0) {
                ans2 = helper(i, j + 1, m, n, neu - 1, arr, dp);
            }
            right = max(ans1, ans2);

            int ans3 = helper(i + 1, j, m, n, neu, arr, dp) + arr[i][j];
            int ans4 = INT_MIN;
            if (neu > 0) {
                ans4 = helper(i + 1, j, m, n, neu - 1, arr, dp);
            }
            down = max(ans3, ans4);
        } else {
            down = helper(i + 1, j, m, n, neu, arr, dp) + arr[i][j];
            right = helper(i, j + 1, m, n, neu, arr, dp) + arr[i][j];
        }

        dp[i][j][neu] = max(down, right);

        return dp[i][j][neu];
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(
            coins.size(),
            vector<vector<int>>(coins[0].size(), vector<int>(3, -5000000)));

        return helper(0, 0, coins.size(), coins[0].size(), 2, coins, dp);
    }
};