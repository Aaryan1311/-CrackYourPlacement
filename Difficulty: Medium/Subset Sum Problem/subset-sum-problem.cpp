//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool helper(int idx, int sum, int tar, vector<int>& arr, vector<vector<int>>& dp){
        if(sum == tar) return true;
        if(idx == arr.size()) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum] == 1;
        
        bool choose = false;
        bool notchoose = helper(idx+1,sum,tar,arr,dp);
        if(sum + arr[idx] <= tar){
            choose = helper(idx+1,sum+arr[idx],tar,arr,dp);
        }
        return dp[idx][sum] = choose || notchoose ? 1 : 0;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int sum = 0;
        for(int i : arr) sum += i;
        vector<vector<int>> dp(arr.size(),vector<int> (sum+1,-1));
        return helper(0,0,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends