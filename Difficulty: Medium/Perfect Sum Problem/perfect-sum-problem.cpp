//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int idx, int sum, int tar, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == arr.size()){
            if(sum == tar) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        // cout << sum << endl;
        int choose = 0;
        if(sum + arr[idx] <= tar) choose = helper(idx+1,sum + arr[idx], tar,arr,dp);
        int notchoose = helper(idx+1,sum,tar,arr,dp);
        // cout << choose << " " << notchoose<< " " << sum << endl;
        return dp[idx][sum] = choose + notchoose;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int sum = 0;
        for(int i : arr) sum += i;
        vector<vector<int>> dp(arr.size(), vector<int> (sum+1,-1));
        return helper(0,0,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends