//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int idx, int n, vector<int>& arr, vector<int>& dp){
        if(idx == n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int one = INT_MAX;
        if(idx + 1 < n)one = solve(idx+1,n,arr,dp) + abs(arr[idx+1] - arr[idx]);
        int two = INT_MAX;
        if(idx + 2 < n) two = solve(idx+2,n,arr,dp) + abs(arr[idx+2] - arr[idx]);
        
        return dp[idx] = min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(0,n,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends