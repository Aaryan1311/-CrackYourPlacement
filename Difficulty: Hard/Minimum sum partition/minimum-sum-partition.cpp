//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long int ll;
class Solution {
    
  public:
  
    int helper(int idx, int sum, int tar, vector<int>& arr,vector<vector<int>>& dp){
        if(idx == arr.size()) return tar - sum;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int choose = INT_MAX;
        if(sum + arr[idx] <= tar) choose = helper(idx+1,sum+arr[idx],tar,arr,dp);
        int notchoose = helper(idx+1,sum,tar,arr,dp);
        
        return dp[idx][sum] = min(choose,notchoose);
        
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int sum = 0;
        for(int i : arr) sum += i;
        vector<vector<int>> dp(arr.size(), vector<int> (sum/2+1,-1));
        return sum % 2 == 0 ? 2*helper(0,0,sum/2,arr,dp) : 2*helper(0,0,sum/2,arr,dp) + 1;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends