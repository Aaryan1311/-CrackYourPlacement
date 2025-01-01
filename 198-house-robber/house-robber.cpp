class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int> dp(n+1,-1);
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        for(int i = 2;i<n;i++){
            int one = 0;
            int two = 0;
            if(i >= 2){
                one = dp[i-2] + arr[i];
            }
            if(i >= 3){
                two = dp[i-3] + arr[i];
            }
            dp[i] = max(one,two);
        }
    return max(dp[n-1],dp[n-2]);
    }
};