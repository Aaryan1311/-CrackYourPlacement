//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int helper(int idx, int left, vector<int>& arr, vector<vector<int>>& dp){
        if(left == 0) return 0;
        if(idx == arr.size()){
            return INT_MIN;
        }
        if(dp[idx][left] != -1) return dp[idx][left];
        
        int choose = INT_MIN;
        if(left  - idx - 1 >= 0) choose = helper(idx,left - idx - 1, arr,dp) + arr[idx];
        int notchoose = helper(idx+1,left,arr,dp);
        
        return dp[idx][left] = max(choose,notchoose);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        vector<vector<int>> dp(price.size()+1, vector<int>(price.size()+1,-1));
        return helper(0,price.size(),price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends