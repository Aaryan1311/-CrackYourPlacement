//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int helper(int idx, int act, vector<vector<int>>& arr,  vector<vector<int>>& dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][act] != -1) return dp[idx][act];
        
        int one = 0;
        int two = 0;
        int three = 0;
        if(act == 0){
            one = helper(idx+1,1,arr,dp) + arr[idx][0];
            two = helper(idx+1,2,arr,dp) + arr[idx][1];
            three = helper(idx+1,3,arr,dp) +  arr[idx][2];
        }
        else if(act == 1){
            two = helper(idx+1,2,arr,dp) + arr[idx][1];
            three = helper(idx+1,3,arr,dp) +  arr[idx][2];
        }
        else if(act == 2){
            one = helper(idx+1,1,arr,dp) + arr[idx][0];
            three = helper(idx+1,3,arr,dp) +  arr[idx][2];
        }
        else if(act == 3){
            one = helper(idx+1,1,arr,dp) + arr[idx][0];
            two = helper(idx+1,2,arr,dp) + arr[idx][1];
        }
        return dp[idx][act] = max(one,max(two,three));
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return helper(0,0,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends