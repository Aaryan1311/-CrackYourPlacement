//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int helper(int idx, int sum, int cap, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        
        if(idx == wt.size()) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int choose = 0;
        if(sum + wt[idx] <= cap) choose = helper(idx,sum+wt[idx],cap,wt,val,dp) + val[idx];
        int notchoose = helper(idx+1,sum,cap,wt,val,dp);
        
        return dp[idx][sum] = max(choose,notchoose);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(wt.size(), vector<int> (capacity+1,-1));
        return helper(0,0,capacity,wt,val,dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends