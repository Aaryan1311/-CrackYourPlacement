//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int helper(int idx, int act, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        // Base case: if we've considered all the rows
        if (idx == arr.size()) return 0;
        
        // If we've already computed the result for this state, return it
        if (dp[idx][act] != -1) return dp[idx][act];
        
        int one = 0, two = 0, three = 0;
        
        // If act is -1, we can pick any action
        if (act == 0) {
            one = helper(idx + 1, 1, arr, dp) + arr[idx][0];
            two = helper(idx + 1, 2, arr, dp) + arr[idx][1];
            three = helper(idx + 1, 3, arr, dp) + arr[idx][2];
        }
        // If the action was 1, we can't choose action 1 again
        else if (act == 1) {
            two = helper(idx + 1, 2, arr, dp) + arr[idx][1];
            three = helper(idx + 1, 3, arr, dp) + arr[idx][2];
        }
        // If the action was 2, we can't choose action 2 again
        else if (act == 2) {
            one = helper(idx + 1, 1, arr, dp) + arr[idx][0];
            three = helper(idx + 1, 3, arr, dp) + arr[idx][2];
        }
        // If the action was 3, we can't choose action 3 again
        else {
            one = helper(idx + 1, 1, arr, dp) + arr[idx][0];
            two = helper(idx + 1, 2, arr, dp) + arr[idx][1];
        }
        
        // Store the result in dp and return the maximum
        return dp[idx][act] = max(one, max(two, three));
    }

    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Create a dp table with -1 indicating uncomputed states
        vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
        return helper(0, 0, arr, dp); // Start from index 0 with no previous action (-1)
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